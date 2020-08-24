#include "CustomerOrder.h"

namespace  sict {
	size_t CustomerOrder::field{ 0u };

	CustomerOrder::CustomerOrder() :custName(""), product(""), items(nullptr), itemNum(0u) {}

	CustomerOrder::CustomerOrder(const std::string& str) {
		size_t pos = 0u;
		Utilities temp;
		std::string tempstr = "";
		std::vector<std::string> tempItem;
		size_t size = std::count(str.begin(), str.end(), temp.getDelimiter()) - 1;
		if (!str.empty()) {
			custName = temp.extractToken(str, pos);
			if (field < custName.length()) {
				field = custName.length();
			}
			if (pos != std::string::npos) {
				product = temp.extractToken(str, pos);
			}
			if (pos == std::string::npos) {
				throw ("No data available");
			}
			else {
				for (size_t i = 0; i < size; i++) {
					tempstr = temp.extractToken(str, pos);
					tempItem.push_back(tempstr);
				}
				itemNum = size;
				items = new Item[size];
				for (size_t i = 0; i < size; i++) {
					items[i].itemName = tempItem[i];
				}
			}
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& custOrder) {
		*this = std::move(custOrder);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& custOrder) {
		if (this != &custOrder&& &custOrder != nullptr)
		{
			if (items != nullptr) {
				//delete[] items;
				items = nullptr;
			}
			items = custOrder.items;
			custName = custOrder.custName;
			product = custOrder.product;
			itemNum = custOrder.itemNum;
			custOrder.items = nullptr;
			custOrder.custName = "";
			custOrder.product = "";
			custOrder.itemNum = 0;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		delete[]items;
		items = nullptr;
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (size_t i = 0; i < itemNum; i++) {
			if (item.getName().compare(items[i].itemName) == 0) {
				if (item.getQuantity() > 0 && items[i].fill == false) {
					items[i].serialNum = item.getSerialNumber();
					--item;
					items[i].fill = true;
					os << " Filled " << custName << " [" << product << "][" << items[i].itemName << "][" << items[i].serialNum << "]";
				}
				else if (item.getQuantity() > 0 && items[i].fill == true) {
					os << " Unable to fill " << custName << " [" << product << "][" << items[i].itemName << "][" << items[i].serialNum << "] already filled";
				}
				else if (item.getQuantity() < 0) {
					os << " Unable to fill " << custName << " [" << product << "][" << items[i].itemName << "][" << items[i].serialNum << "] out of stock";
				}
				os << std::endl;
			}
		}
	}

	bool CustomerOrder::isFilled() const {
		bool filled = false;
		size_t allTrue{ 0 };
		for (size_t i = 0; i < itemNum; i++) {
			if (items[i].fill) {
				allTrue++;
			}
		}
		if (allTrue == itemNum) {
			filled = true;
		}
		return filled;
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const {
		bool filled = false;
		size_t allTrue{ 0 };
		size_t countTrue{ 0 };
		for (size_t i = 0; i < itemNum; i++) {
			if (items[i].itemName == item) {
				allTrue++;
				if (items[i].fill) {
					countTrue++;
				}
			}
		}
		if (allTrue == countTrue || allTrue == 0) {
			filled = true;
		}
		return filled;
	}

	std::string CustomerOrder::getNameProduct() const {
		size_t space{ 0 };
		std::string addSpace{ "" };
		if (custName.length() < field) {
			space = field - custName.length();
			for (size_t i = 0; i < space; i++) {
				addSpace += " ";
			}
		}
		return custName + addSpace + " [" + product + "]";
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		os << getNameProduct() << std::endl;
		if (!showDetail) {
			for (size_t i = 0; i < itemNum; i++) {
				os << std::setw(field + 1) << " " << items[i].itemName << std::endl;
			}
		}
		else {
			for (size_t i = 0; i < itemNum; i++) {
				os << "[" << items[i].serialNum << "] " << items[i].itemName << " - " << items[i].fill;
			}
		}
	}
}