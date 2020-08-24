// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10
//Li-Ching,Cheng
//143292175
//SEE

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// check for command line errors
	if (argc != 3) exit(1);

	// set for fixed, 2-decimal point output
	std::cout << std::fixed << std::setprecision(2);

	// process price list file
	try {
		KVList<KVPair<std::string, float>> priceList = createList<
			KVList<KVPair<std::string, float>>,
			KVPair<std::string, float>,
			std::string,
			float>
			(argv[1]);
		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));
	}
	catch (int& num) {
		if (num == 1) {
			std::cout << "Parameter < 0." << std::endl;
			exit(2);
		}
		if (num == 2) {
			std::cout << "No room." << std::endl;
			exit(3);
		}
	}

	// process student list file
	auto hello = [](float grade) {
		std::string letter;
		if (grade > 89) {
			letter = "A+";
		}
		else if (grade > 79) {
			letter = "A ";
		}
		else if (grade > 74) {
			letter = "B+";
		}
		else if (grade > 69) {
			letter = "B ";
		}
		else if (grade > 64) {
			letter = "C+";
		}
		else if (grade > 59) {
			letter = "C ";
		}
		else if (grade > 54) {
			letter = "D+";
		}
		else if (grade > 49) {
			letter = "D ";
		}
		else {
			letter = "F ";
		}
		return letter;
	};
	try {
		KVList<KVPair<int, float>> studentList = createList<
			KVList<KVPair<int, float>>, KVPair<int, float>, int, float>
			(argv[2]);
		std::cout << "\nStudent List Letter Grades Included\n===================================\n";
		std::cout << "Student No :      Grade    Letter\n";
		studentList.display(std::cout, hello);
	}
	catch (int& num) {
		if (num == 1) {
			std::cout << "Parameter < 0." << std::endl;
			exit(4);
		}
		if (num == 2) {
			std::cout << "No room." << std::endl;
			exit(5);
		}
	}
}