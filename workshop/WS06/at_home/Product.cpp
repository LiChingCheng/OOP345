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
		/*size_t p_begin = 0u;
		size_t t_begin = 0u;
		size_t tempNo = 0u;
		double tempPrice = 0;
		char tempTax;
		std::string temp;
		char tax;*/
		iProduct* product = nullptr;
		size_t tempNo;
		double tempPrice;
		char tempTax;
		//if (file.is_open()) {
			/*std::getline(file, temp, '\n');
			p_begin = temp.find(' ') + 1;
			t_begin = temp.find(' ', p_begin);
			tempNo = std::stoi(temp.substr(0, temp.find(' ')));
			tempPrice = std::stod(temp.substr(p_begin, (t_begin - p_begin)));
			if (t_begin != std::string::npos) {
				tempTax = temp.substr(t_begin + 1);
				if (tempTax.compare(0, 1, "P") == 0) {
					tax = 'P';
				}
				if (tempTax.compare(0, 1, "H") == 0) {
					tax = 'H';
				}
				return new TaxableProduct(tempNo, tempPrice, tax);
			}
		}
		return new Product(tempNo, tempPrice);*/
			file >> tempNo >> tempPrice;
			if (file.get()!='\n') {
				file >> tempTax;
			}
			else {
				tempTax = ' ';
			}
			if (file.good()) {
				if (tempTax != ' ') {
					return new TaxableProduct(tempNo, tempPrice, tempTax);
				}
				else {
					return new Product(tempNo, tempPrice);;
				}
			}
	}

	TaxableProduct::TaxableProduct(size_t no, double p, char t) :Product::Product(no, p) {
		tax = t;
	}

	double TaxableProduct::price() const {
		double tempP=0;
		if (tax == 'H') {
			tempP = Product::price()*(1 + (HST / 100.0));
		}
		if (tax == 'P') {
			tempP = Product::price()*(1 + (PST / 100.0));
		}
		return tempP;
	}

	void TaxableProduct::display(std::ostream& os) const {
		int fw = FW;
		Product::display(os);
		os << std::setw(4);
		if (tax) {
			std::string taxPrint;
			if (tax == 'H') {
				taxPrint = "HST";
			}
			if (tax == 'P') {
				taxPrint = "PST";
			}
			os << taxPrint;
		}
	}
}