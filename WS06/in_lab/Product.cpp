//Li-Ching, Cheng 143292175 SEE

#include "Product.h"

namespace sict {
	Product::Product(size_t no, double p) {
		proNo = no;
		proPrice = p;
	}

	double Product::price() const {
		return proPrice;
	}

	void Product::display(std::ostream& os) const {
		int fw = FW;
		os << proNo << std::setw(fw) << proPrice;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	iProduct* readRecord(std::ifstream& file) {
		size_t tempNo = 0u;
		double tempPrice = 0;
		std::string temp;
		if (file.is_open()) {
			std::getline(file, temp, '\n');
			tempNo = std::stoi(temp.substr(0, temp.find(' ')));
			tempPrice = std::stod(temp.substr(temp.find(' ')));
		}
		return new Product(tempNo, tempPrice);
	}
}