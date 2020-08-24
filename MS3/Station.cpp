//Li-Ching, Cheng 143292175 SEE

#include "Station.h"

namespace sict {
	Station::Station(const std::string& str) : itemset(str) {}

	void Station::display(std::ostream& os) const {
		itemset.display(os, true);
	}

	void Station::fill(std::ostream& os) {
		if (!custOrder.empty()) {
			if (!(*custOrder.begin()).isFilled()) {
				(*custOrder.begin()).fillItem(itemset, os);
			}
		}
	}

	const std::string& Station::getName() const {
		return itemset.getName();
	}

	bool Station::Station::hasAnOrderToRelease() const {
		bool release = false;
		if (!custOrder.empty()) {
			if (custOrder.front().isItemFilled(itemset.getName()) || itemset.getQuantity() == 0) {
				release = true;
			}
		}
		return release;
	}

	Station& Station::operator--() {
		--itemset;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		custOrder.push_back(std::move(order));
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		bool fillpart;
		if (!custOrder.empty()) {
			fillpart = (*custOrder.begin()).isFilled();
			CustomerOrder order = std::move(*custOrder.begin());
			custOrder.pop_front();
			ready = std::move(order);
		}
		else {
			fillpart = false;
		}
		return fillpart;
	}

	void Station::validate(std::ostream& os) const {
		os << " getName() : " << itemset.getName() << std::endl;
		os << " getSerialNumber() : " << itemset.getSerialNumber() << std::endl;
		os << " getQuantity() : " << itemset.getQuantity() << std::endl;
	}
}