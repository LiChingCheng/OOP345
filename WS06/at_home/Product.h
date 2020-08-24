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
		Product(size_t no, double p);
		double price() const;
		void display(std::ostream& os) const;
	};

	enum  Tax { HST = 13, PST = 8 };

	class TaxableProduct :public Product {
		char tax;
	public:
		TaxableProduct(size_t no, double p, char t);
		double price() const;
		void display(std::ostream& os) const;
	};
}
#endif // !SICT_PRODUCT_H
