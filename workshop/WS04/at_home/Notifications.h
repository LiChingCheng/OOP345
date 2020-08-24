//Li-Ching,Cheng
//143292175
//SEE

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
#include <iostream>
#include <string>
#include "Message.h"
using namespace std;

namespace sict {
	class Notifications {
		const Message** message;
		int max;
		int num;
	public:
		Notifications();
		Notifications(int maxNum);
		~Notifications();
		Notifications(const Notifications& ntf);
		Notifications(Notifications&& ntf);
		Notifications& operator=(const Notifications& ntf);
		Notifications& operator=(Notifications&& ntf);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, const  Notifications& msg);
}
#endif // !SICT_NOTIFICATIONS_H


