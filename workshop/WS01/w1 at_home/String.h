#ifndef SICT_STRING_H
#define SICT_STRING_H
using namespace std;

namespace sict {
	class String {
		char* string;
	public:
		String(const char*);
        void display(ostream &)const;
		~String();
	};
    ostream& operator<<(ostream &, const String &);
}

#endif // !SICT_STRING_H
