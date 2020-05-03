#include <iostream>
#include <vector>
#include <functional>

template <class T>
class BIT_PURQ{

	int arr_size;

	int max_limit;
	int min_limit;

	T default_ans;
	T default_bit_value; 

	std::vector<T> bit;
	
	std::function <int(int)> increment_fun;
	std::function <int(int)> decrement_fun;

	std::function <T(T, T)> decide_fun;
	std::function <T(T, T)> inv_decide_fun;

	static int one_base_index_increment(int x){
		return (x + (x & (-x)));
	}

	static int one_base_index_decrement(int x){
		return (x - (x & (-x)));
	}

	static int zero_base_index_increment(int x){
		return x | (x + 1);
	}

	static int zero_base_index_decrement(int x){
		return (x & (x + 1)) - 1;
	}

public:

	BIT_PURQ(){}

	BIT_PURQ(int size_of_bit, T defualt_value, std::function <T(T, T)> decide_fun, std::function <T(T, T)> inv_decide_fun,int base = 0){

		this -> arr_size = size_of_bit;
		bit.resize(size_of_bit, defualt_value);
		
		this -> decide_fun = decide_fun;
		this -> inv_decide_fun = inv_decide_fun;
		
		this -> default_ans = defualt_value;

		if(base){
			increment_fun = one_base_index_increment;
			decrement_fun = one_base_index_decrement;
			max_limit = arr_size+1;
			min_limit = 0;
			bit.push_back(defualt_value);
		}else{
			increment_fun = zero_base_index_increment;
			decrement_fun = zero_base_index_decrement;
			max_limit = arr_size;
			min_limit = -1;
		}
	}

	void update(int x, T value){
		while(x < max_limit){
			bit[x] = decide_fun(bit[x], value);
			x = increment_fun(x);
		}
	}

	T query(int x){
		T res = default_ans;
		while(x > min_limit){
			res = decide_fun(bit[x], res);
			x = decrement_fun(x);
		}
		return res;
	}

	T query(int l, int r){
		return inv_decide_fun(query(r), query(l-1));
	}

	void print(){
		for(T value: bit){
			std::cout << value << " ";
		}
		std::cout << "\n";
	}
};
