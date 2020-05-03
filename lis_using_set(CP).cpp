#include <iostream>
#include <set>
#include <vector>

int LIS(vector <int> &v){

	// beautiful!!! isn't it ?
	// https://codeforces.com/blog/entry/13225

	const int n = v.size();
	for(int i = 0; i < n; ++i){
	    s.insert(a[i]);
	    
	    it = s.upper_bound(a[i]);

	    if(it != s.end())
	        s.erase(it);

	}

	// return length of lis
	return s.size();
}
