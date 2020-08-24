#ifndef SICT_LIST_H
#define SICT_LIST_H
#include <iostream>
using namespace std;

namespace sict {
	template <typename T, size_t N>
	class List {
		T a[N];
		size_t num{ 0u };
	public:
		size_t size() const { return num; };
		const T& operator[](size_t i) const { return a[i]; };
		void operator+=(const T&t) { if (num < N) { a[num] = t; num++; } };
	};
}
#endif // !SICT_LIST_H

