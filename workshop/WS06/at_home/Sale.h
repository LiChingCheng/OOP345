//Li-Ching, Cheng 143292175 SEE

#ifndef SICT_SALES_H
#define SICT_SALES_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "iProduct.h"

namespace sict {
	class Sale {
		std::vector<iProduct*> product;
	public:
		Sale(const char* file);
		void display(std::ostream& os) const;
	};
}
#endif // !SICT_SALES_H

