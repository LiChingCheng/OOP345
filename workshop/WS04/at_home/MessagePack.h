//Li-Ching,Cheng
//143292175
//SEE

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
#include <iostream>
#include <string>
#include "Message.h"

namespace sict {
	class MessagePack {
		Message* message;
		int num;
	public:
		MessagePack();
		MessagePack(Message** msg, int cnum);
		~MessagePack();
		MessagePack(const MessagePack& msgp);
		MessagePack(MessagePack&& msgp);
		MessagePack& operator=(const MessagePack& msgp);
		MessagePack& operator=(MessagePack&& msgp);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, const MessagePack& msg);

}
#endif // !SICT_MESSAGEPACK_H
