#include <iostream>
#include <vector>
#include <functional>

template <class T>
class BIT_PURQ{

	int arr_size;
	
	T default_ans;
	T default_bit_value; 

	std::vector<T> bit;
	
	std::function <T(T, T)> increment_fun;
	std::function <T(T, T)> decrement_fun;

	inline one_base_index_increment(int x){
		return (x + (x & (-x)));
	}

	inline one_base_index_decrement(int x){
		return (x - (x & (-x)));
	}

	inline zero_base_index_increment(int x){
		return x | (x + 1);
	}

	inline one_base_index_decrement(int x){
		return (x & (x + 1)) - 1;
	}

public:

	BIT_PURQ(){}

	BIT_PURQ()

}