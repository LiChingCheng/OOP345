#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>
using namespace std;

namespace sict {
	template <typename L,typename V>
	class LVPair {
		L tlable;
		V tvalue;
	public:
		LVPair() {}
		LVPair(const L& lable, const V& value) :tlable(lable), tvalue(value) {}
		void display(ostream& os) const { os << tlable << " : " << tvalue << endl; }
	};
	template <typename L, typename V>
	ostream& operator<<(ostream& os, const LVPair<L, V>& pair) { pair.display(os); return os; };
}
#endif // !SICT_LVPAIR_H

