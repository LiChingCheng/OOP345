#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>
using namespace std;

namespace sict {
	template <typename L, typename V>
	class LVPair {
		L tlabel;
		V tvalue;
	public:
		LVPair() {}
		LVPair(const L& label, const V& value) :tlabel(label), tvalue(value) {}
		virtual void display(ostream& os) const { os << tlabel << " : " << tvalue << endl; }
		const L& getLabel() const { return tlabel; }
		const V& getValue() const { return tvalue; }
	};
	template <typename L, typename V>
	ostream& operator<<(ostream& os, const LVPair<L, V>& pair) { pair.display(os); return os; };


	template <typename L, typename V>
	class SummableLVPair :public LVPair<L, V> {
		static V sumValue;
		static size_t min;
	public:
		SummableLVPair() {}
		SummableLVPair(const L& label, const V& v);
		static const V& getInitialValue() { return sumValue; }
		V sum(const L& label, const V& sum)const;
		void display(ostream& os) const;
	};

	template <typename L, typename V>
	SummableLVPair<L, V>::SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
		if (min < label.size()) {
			min = label.size();
		}
	}

	template <typename L, typename V>
	size_t SummableLVPair<L, V>::min = 0u;

	template <typename L, typename V>
	V SummableLVPair<L, V>::sum(const L& label, const V& sum)const {
		V total = LVPair<L, V>::getValue() + sum;
		return total;
	}

	template <typename L, typename V>
	void  SummableLVPair<L, V>::display(ostream& os) const {
		os.setf(ios::left);
		os.width(min);
		LVPair<L, V>::display(os);
	}

	template <>
	int SummableLVPair<string, int>::sumValue = 0;

	template<>
	string SummableLVPair<string, string>::sumValue = "";

	template<>
	string SummableLVPair<string, string>::sum(const string& label, const string& sum)const {
		string temp = sum +" "+ LVPair<string, string>::getValue();
		return temp;
	}
}
#endif // !SICT_LVPAIR_H

// 12345
// 12 3 45
