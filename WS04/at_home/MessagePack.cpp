//Li-Ching,Cheng
//143292175
//SEE

#include <iostream>
#include "Message.h"
#include "MessagePack.h"
using namespace std;

namespace sict {
	MessagePack::MessagePack() {
		message = nullptr;
		num = 0;
	}
	MessagePack::MessagePack(Message** msg, int cnum) {
		if (cnum > 0 && msg != nullptr) {
			message = new Message[cnum];
			num = 0;
			for (int i = 0; i < cnum; i++) {
				if (!msg[i]->empty()) {
					message[num++] = *msg[i];
				}
			}
		}	
		else {
			message = nullptr;
			num = 0;
		}
	}
	MessagePack::~MessagePack() {
		delete[]message;
		message = nullptr;
	}
	MessagePack::MessagePack(const MessagePack& msgp) {
		*this = msgp;
	}
	MessagePack::MessagePack(MessagePack&& msgp) {
		*this = move(msgp);
	}
	MessagePack& MessagePack::operator=(const MessagePack& msgp) {
		if (&msgp != this){ //&& msgp.message != nullptr) {
			if (message != nullptr) {
				delete[]message;
			}
			message = nullptr;
			num = msgp.num;
			message = new Message[num];
			for (int i = 0; i < num; i++) {
				message[i] = msgp.message[i];
			}
		}
		return *this;
	}
	MessagePack& MessagePack::operator=(MessagePack&& msgp) {
		if (&msgp != this) {
			//if (message != nullptr) {
				delete[]message;
			//}
			//message = nullptr;
			message = msgp.message;			
			num = msgp.num;
			msgp.message=nullptr;
			msgp.num = 0;
		}
		return *this;
	}
	void MessagePack::display(std::ostream& os) const {
		for (int i = 0; i < num; i++) {
			message[i].display(os);
		}
	}
	size_t MessagePack::size() const {
		return num;
	}
	ostream& operator<<(ostream& os, const MessagePack& msg) {
		msg.display(os);
		return os;
	}
};
