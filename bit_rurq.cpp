#include <iostream>
#include <vector>
#include <functional>
#include "bit_purq.cpp"

template <class T>
class BIT_RURQ{

	BIT_PURQ <T> bit_add, bit_remove;
	std::function <T(T, T)> decide_fun;
	std::function <T(T, T)> inv_decide_fun;

public:

	BIT_RURQ(int size_of_bit, T defualt_value, std::function <T(T, T)> decide_fun, std::function <T(T, T)> inv_decide_fun,int base = 0){
		
		bit_add = BIT_PURQ<T>(size_of_bit, defualt_value, decide_fun, inv_decide_fun, base);
		bit_remove = BIT_PURQ<T>(size_of_bit, defualt_value, decide_fun, inv_decide_fun, base);

		this -> decide_fun = decide_fun;
		this -> inv_decide_fun = inv_decide_fun;
	}

	void update(int l, int r, T value){
		bit_add.update(l, value);
		bit_add.update(r+1, -value);
		bit_remove.update(l, (l-1)*value);
		bit_remove.update(r+1, -(l-1)*value);
		// because we want to add this value into ans
		bit_remove.update(r+1, (-r+l-1)*value);
	}

	T query(int idx){
		return inv_decide_fun(idx*bit_add.query(idx), bit_remove.query(idx));
	}

	T query(int l, int r){
		return inv_decide_fun(query(r), query(l-1));
	}

};