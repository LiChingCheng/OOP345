#ifndef SICT_LIST_H
#define SICT_LIST_H
#include <iostream>
using namespace std;

namespace sict {
	template <typename T, size_t N>
	class List {
		T a[N];
		size_t num{ 0u };
	public:
		size_t size() const { return num; };
		const T& operator[](size_t i) const { return a[i]; };
		void operator+=(const T&t) { if (num < N) { a[num] = t; num++; } };
	};

	template <typename T, typename L, typename V, int N>
	class LVList :public List<T, N> {
	public:
		V accumulate(const L& label) const {
			List<T, N>& temp = (List<T, N>&)*this;
			V tsumValue = SummableLVPair<L, V>::getInitialValue();
			for (size_t i = 0; i < temp.size(); i++) {
				if (label == temp[i].getLabel()) {
					tsumValue = temp[i].sum(label, tsumValue);
				}
			}
			return tsumValue;
		};
	};
}

#endif // !SICT_LIST_H
