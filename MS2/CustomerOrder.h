//Li-Ching, Cheng 143292175 SEE

#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDER_H
#include <iostream>
#include <vector>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	struct Item {
		std::string itemName{ "" };
		unsigned int serialNum{ 0u };
		bool fill = false;
	};

	class CustomerOrder {
		/*std::string custName{ "" };
		std::string product{ "" };
		Item* items{ nullptr };
		size_t itemNum{ 0u };
		static size_t field;*/
		std::string custName;
		std::string product;
		Item* items;
		size_t itemNum;
		static size_t field;
	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder(CustomerOrder&& custOrder);
		CustomerOrder& operator=(CustomerOrder&& custOrder);
		~CustomerOrder();
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail=false) const;

		CustomerOrder(const CustomerOrder& custOrder) = delete;
		CustomerOrder& operator=(const CustomerOrder& custOrder) = delete;
	};
}
#endif // !SICT_CUSTOMERORDER_H


