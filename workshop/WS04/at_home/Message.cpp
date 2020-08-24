//Li-Ching,Cheng
//143292175
//SEE

#include <iostream>
#include "Message.h"
using namespace std;

namespace sict {
	Message::Message() {
		isEmpty = true;
	}
	Message::Message(const string& str) :isEmpty(true) {
		size_t theEnd = string::npos;
		size_t replyAT = str.find('@');
		size_t msg_begin;
		if (replyAT != theEnd) {
			sender = str.substr(0, replyAT - 1);
			msg_begin = str.find(' ', replyAT);
			receiver = str.substr(replyAT + 1, (msg_begin - replyAT - 1));
			msg = str.substr(msg_begin + 1);
			isEmpty = false;
		}
		else {
			msg_begin = str.find(' ');
			if (msg_begin != theEnd) {
				sender = str.substr(0, msg_begin);
				msg = str.substr(msg_begin + 1);
				isEmpty = false;
			}
		}
	}
	bool Message::empty() const {
		return isEmpty;
	}
	void Message::display(ostream& os) const {
		if (!empty()) {
			os.setf(ios::left);
			os << setw(6) << ">User" << " : " << sender << '\n';
			if (receiver.length() != 0) {
				os << " Reply" << " : " << receiver << '\n';
			}
			os << " Tweet" << " : " << msg << '\n';
			os.unsetf(ios::left);
		}
	}
}