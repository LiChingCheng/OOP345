//Li-Ching,Cheng
//143292175
//SEE

#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H
#include <iostream>

namespace sict {
	template<typename T>
	class KVList {
		T* pair;
		int max;
		int count;
		bool empty = true;
	public:
		KVList() {}
		KVList(int n) {
				if (n > 0) {
					max = n;
					pair = new T[max];
					count = 0;
					empty = false;
				}
				else {
					throw(1);
				}
		}
		KVList(KVList&& list) {
			if (this != &list) {
				pair = list.pair;
				max = list.max;
				count = list.count;
				empty = false;
				list.pair = nullptr;
				list.max = 0;
				list.count = 0;
			}
		}
		~KVList() {
			delete[]pair; 
			pair = nullptr;
		}
		const T& operator[](size_t i) const {
			return  pair[i];
		}
		template<typename F>
		void display(std::ostream& os, F f) const {
			if (!empty) {
				if (count > 0) {
					for (int i = 0; i < count; i++) {
						pair[i].display(os, f);
					}
				}
			}
		}
		void push_back(const T& t) {
				int a;
				a = max - count;
				if (a > 0) {
					pair[count++] = t;
				}
				else
				{
					throw(2);
				}
		}
	};
}
#endif // !SICT_KVLIST_H

