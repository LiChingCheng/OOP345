//Li-Ching,Cheng
//143292175
//SEE

#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H
#include <iostream>

namespace sict {
	class Taxable {
		const float taxT;
	public:
		Taxable(float tax) :taxT{ tax } {};
		float operator()(float price) {
			return price * (1 + taxT);
		}
	};
}
#endif // !SICT_TAXABLE_H

