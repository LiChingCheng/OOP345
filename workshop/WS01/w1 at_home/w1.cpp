#include <iostream>
#include "process.h"
using namespace std;
using namespace sict;
//extern 
int INITIAL = 3;

int main(int argc, char *argv[]) {
	cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			process(argv[i]);
		}
	}
	else {
		cout << "***Insufficient number of arguments***" << endl;
		return 1;
	}
	return 0;
}

