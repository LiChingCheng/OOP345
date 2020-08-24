//Li-Ching, Cheng 143292175 SEE

#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	size_t ItemSet::field = 0u;

	ItemSet::ItemSet(const std::string& str) {
		size_t pos = 0u;
		Utilities temp;
		std::string tempstr;
		if (!str.empty()) {
			item = temp.extractToken(str, pos);
			if (field < item.length()) {
				field = item.length();
			}
			if (pos != std::string::npos) {
				tempstr = temp.extractToken(str, pos);
				serialNum = std::stoi(tempstr);
			}
			if (pos != std::string::npos) {
				tempstr = temp.extractToken(str, pos);
				remainNum = std::stoi(tempstr);
			}
			if (pos != std::string::npos) {
				descript = temp.extractToken(str, pos);
			}
		}
	}

	ItemSet::ItemSet(ItemSet&& itemSet) {
		if (this != &itemSet)
		{
			item = itemSet.item;
			serialNum = itemSet.serialNum;
			remainNum = itemSet.remainNum;
			descript = itemSet.descript;
			itemSet.item = "";
			itemSet.serialNum = 0;
			itemSet.remainNum = 0;
			itemSet.descript = "";
		}
	}

	const std::string& ItemSet::getName() const {
		return item;
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return serialNum;
	}

	const unsigned int ItemSet::getQuantity() const {
		return remainNum;
	}

	ItemSet& ItemSet::operator--() {
		if (remainNum > 0) {
			remainNum--;
			serialNum++;
		}
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {
		os << std::setw(field) << std::left << item
			<< " [" << std::setfill('0') << std::setw(5) << std::right << serialNum << "]" << std::setfill(' ');
		if (full) {
			os << " Quantity " << std::setw(3) << std::left << remainNum
				<< " Description: " << descript << std::endl;
		}
	}
}