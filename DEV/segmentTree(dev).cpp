#include <iostream>
#include <vector>
#include <functional>

using namespace std;


template <class T>
class SegmentTree{

	// 0 index base segment tree with rang query point upate
	
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

	SegmentTree(std::function <T(T, T)> fun, T default_return){

		// size_of_array: size of array on which want to build tree
		// fun: funtion min, max, addition etc
		// default_retrun: default return when argument false in queary function


		/* 

		SegmentTree <int> seg(n, __min, INT_MAX);
		
		where __min is 

		T __min(T a, T b){
			return std::min(a, b);
		}
		
		seg.build(arr);
		arr is array -> you want to build tree

		*/

		this -> fun = fun;
		this -> default_return = default_return;
	}

	SegmentTree(vector <T> &a, std::function <T(T, T)> fun, T default_return){

		this -> fun = fun;
		this -> default_return = default_return;

		build(a);
	}

	void build(std::vector<T> &a){

		// it will build segment tree 

		this -> arr_size = a.size();
		seg.resize(4*arr_size + 5);

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

		if(ql <= l and r <= qr){
			return seg[pos];
		}

		int m = mid(l, r);
		return fun(query(ql, qr, l, m, left(pos)), query(ql, qr, m+1, r, right(pos)));
	}

	void update(int loc, T value){
		update(0, arr_size-1, loc, 0,value);
	}

	void update(int l, int r, int loc, int pos, T value){
		if(l == r){
			seg[pos] = value;
			return; 
		}

		int m = mid(l, r);

		if(loc <= m){
			update(l, m, loc, left(pos), value);
			seg[pos] = fun(seg[left(pos)], seg[right(pos)]);
		}else{	
			update(m+1, r, loc, right(pos), value);
			seg[pos] = fun(seg[left(pos)], seg[right(pos)]);
		}

	}

	void print(){
		for(int i = 0; i < seg.size(); ++i)
			std::cout << i  << " " << seg[i] << "\n";
	}

};
