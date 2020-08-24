//Li-Ching, Cheng 143292175 SEE

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H
#include <iostream>
#include <string>
#include <iomanip>

namespace sict {
	class ItemSet {
		/*
		std::string item{ "" };
		unsigned int serialNum{ 0u };
		unsigned int remainNum{ 0u };
		std::string  descript{ "" };
		static size_t field;*/
		std::string item;
		unsigned int serialNum;
		unsigned int remainNum;
		std::string  descript;
		static size_t field;
	public:
		ItemSet();
		ItemSet(const std::string& str);
		ItemSet(ItemSet&& itemSet);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};
}

#endif // !SICT_ITEMSET_H


