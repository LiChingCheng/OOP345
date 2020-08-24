//Li-Ching,Cheng
//143292175
//SEE

#include <iostream>
#include "Message.h"
#include "Notifications.h"
using namespace std;

namespace sict {
	Notifications::Notifications() {
		max = 0;
		num = 0;
		message = nullptr;
	}
	Notifications::Notifications(int maxNum) {
		if (maxNum > 0) {
			max = maxNum;
			num = 0;
			message = new const Message*[max];
		}
		else {
			max = 0;
			num = 0;
			message = nullptr;
		}
	}
	Notifications::~Notifications() {
		delete[] message;
		message = nullptr;
	}
	Notifications::Notifications(const Notifications& ntf) {
		*this = ntf;
	}
	Notifications::Notifications(Notifications&& ntf) {
		*this = move(ntf);
	}
	Notifications& Notifications::operator=(const Notifications& ntf) {
		if (&ntf != this) {
			if (message != nullptr) {
				delete[]message;
			}
			message = nullptr;
			max = ntf.max;
			num = 0;
			message = new const Message*[max];
			for (int i = 0; i < num; i++) {
				message[num++] = ntf.message[i];
			}
		}
		return *this;
	}
	Notifications& Notifications::operator=(Notifications&& ntf) {
		if (&ntf != this) {
			message = nullptr;
			max = ntf.max;
			num = ntf.num;
			message = ntf.message;
			ntf.message = nullptr;
			ntf.max = 0;
			ntf.num = 0;
		}		
		return *this;
	}
	Notifications& Notifications::operator+=(const Message& msg) {
		if ((num < max) && !msg.empty()) {
			message[num++] = &msg;
		}	
		return *this;
	}
	Notifications& Notifications::operator-=(const Message& msg) {
		int count;
		bool found = false;
		if (!msg.empty()) {
			for (int i = 0; i < num; i++) {
				if (message[i] == &msg) {
					count = i;
					found = true;
				}
			}
			if (found) {
				for (int i = count; i < (num - 1); i++) {
					message[i] = message[i + 1];
				}
					message[num - 1] = nullptr;
					num--;
			}
		}
		return *this;
	}
	void Notifications::display(std::ostream& os) const {
		for (int i = 0; i < num; i++) {
			message[i]->display(os);
		}
	}
	size_t Notifications::size() const {
		return num;
	}
	ostream& operator<<(ostream& os, const Notifications& msg) {
		msg.display(os);
		return os;
	}
}
