//Li-Ching, Cheng 143292175 SEE

#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	size_t ItemSet::field = 0u;

	ItemSet::ItemSet(const std::string& str) {
		size_t pos = 0u;
		Utilities temp;
		std::string tempstr, tempstr2;
		if (!str.empty()) {
			item = temp.extractToken(str, pos);
			pos = (item.length() + 1);
			if (field < item.length()) {
				field = item.length();
			}
			if (pos != std::string::npos) {
				tempstr = temp.extractToken(str, pos);
				serialNum = std::stoi(tempstr);
				pos += (tempstr.length() + 1);
			}
			if (pos != std::string::npos) {
				tempstr2 = temp.extractToken(str, pos);
				remainNum = std::stoi(tempstr2);
				pos += (tempstr2.length() + 1);
			}
			if (pos != std::string::npos) {
				descript = temp.extractToken(str, pos);
			}
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