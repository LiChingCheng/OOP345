//Li-Ching, Cheng 143292175 SEE

#include "Sale.h"

namespace sict {
	Sale::Sale(const char* file) {
		size_t count = 0u;
		std::string temp;
		std::ifstream fin(file);
		if (fin.is_open()) {
			while (std::getline(fin, temp, '\n')) {
				count++;
			}
			fin.clear();
			fin.seekg(0, std::ios::beg);
			for (size_t i = 0; i < count; i++) {
				product.push_back(readRecord(fin));
			}
			fin.close();
		}
		else {
			std::string s = "File can not open.";
			throw s;
		}
	}
	void Sale::display(std::ostream& os) const {
		int fw = FW;
		double total = 0;
		os << std::setw(fw) << std::right << "Product No" << std::setw(fw) << "Cost" << std::endl;
		/*for (size_t i = 0; i < product.size(); i++) {
			os << std::setw(fw) << std::setprecision(2) << std::fixed;
			product.at(i)->display(os);
			os << std::endl;
			total += product.at(i)->price();
		}*/
		for (auto& i : product) {
			os << std::setw(fw) << std::setprecision(2) << std::fixed;
			os << *i;
			//os << std::fixed << std::setprecision(2);
			total += i->price();
			os << std::endl;
		}
		os << std::setw(fw) << "Total" << std::setw(fw) << total << std::endl;
	}
}