//Li-Ching, Cheng 143292175 SEE

#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H
#include <iostream>
#include <fstream>

extern int FW;

namespace sict {
	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}
#endif // !SICT_IPRODUCT_H