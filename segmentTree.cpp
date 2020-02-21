#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <class T>
class SegmentTree{
	
	int arr_size;
	
	T default_return;

	std::vector<T> seg;
	std::function <T(T, T)> fun;

	inline int left(int pos){
		return 2*pos + 1;
	}

	inline int right(int pos){
		return 2*pos + 2;
	}

	inline int mid(int l, int r){
		return (l + ((r-l) >> 1));
	}

public:

	SegmentTree(){}

	SegmentTree(int size_of_array, std::function <T(T, T)> fun, T default_return){

		// size_of_array: size of array on which want to build tree
		// fun: funtion min, max, addition etc
		// default_retrun: default return when argument false in queary function

		this -> arr_size = size_of_array;
		seg.resize(4*arr_size + 5);

		this -> fun = fun;
		this -> default_return = default_return;
	}

	void build(std::vector<T> &a){

		// it will build segment tree 

		build(a, 0, arr_size-1, 0);
	}

	void build(std::vector<T> &a, int l, int r, int pos){
		if(l == r){
			seg[pos] = a[r];
			return;
		}

		int m = mid(l, r);

		build(a, l, m, left(pos));
		build(a, m+1, r, right(pos));

		seg[pos] = fun(seg[left(pos)], seg[right(pos)]);
	}


	T query(int l, int r){
		return query(l, r, 0, arr_size-1, 0);
	}

	T query(int ql, int qr, int l, int r, int pos){

		if(qr < l or r < ql){
			return default_return;
		}

		if(l <= ql and qr <= r){
			return seg[pos];
		}

		int m = mid(l, r);
		return fun(query(ql, qr, l, m, left(pos)), query(ql, qr, m+1, r, right(pos)));
	}

};

int main(){

	return 0;
}