//Li-Ching,Cheng
//143292175
//SEE

#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H
#include <iostream>
#include <iomanip>
extern int fieldWidth;
namespace sict {
	
	template< typename K, typename V >
	class KVPair {
		K pairKey;
		V pairValue;
		bool empty = true;
	public:
		KVPair() {};
		KVPair(const K& key, const V& value) :pairKey{ key }, pairValue{ value }, empty{ false }{};
		template<typename F>
		void display(std::ostream& os, F f) const {
			if (!empty) {
				os.setf(std::ios::left);os.width(fieldWidth);
				os << pairKey << " : ";
				os.unsetf(std::ios::left);
				os.unsetf(std::ios::right);os.width(fieldWidth);
				os << pairValue;
				os.width(fieldWidth);
				os << f(pairValue) << std::endl;
				os.unsetf(std::ios::right);
			}
		}
	};
}
#endif // !SICT_KVPAIR_H

