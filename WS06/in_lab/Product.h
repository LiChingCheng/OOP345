//Li-Ching, Cheng 143292175 SEE

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include <string>
#include <iomanip>
#include "iProduct.h"

namespace sict {
	class Product : public iProduct {
		size_t proNo;
		double proPrice;
	public:
		Product(size_t str, double p);
		double price() const;
		void display(std::ostream& os) const;
	};
}
#endif // !SICT_PRODUCT_H
