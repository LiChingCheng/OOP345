//Li-Ching,Cheng
//143292175
//SEE

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <iostream>
#include <iomanip>
#include <string>
namespace sict {
	class Message {
		std::string sender;
		std::string receiver;
		std::string msg;
		bool isEmpty;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}
#endif // !SICT_MESSAGE_H


