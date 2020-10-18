#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cstring>

// ---------- PBDS -----------------

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>

// ----------------------------------

using namespace std;
using namespace __gnu_pbds; 

#define MEM(a, b) memset(a, (b), sizeof(a))
#define ALL(a) a.begin(), a.end()
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0),cout << fixed << setprecision(10);
#define ll long long int
// #define int long long int

#define sim template < class c
#define ris return * this
#define dor > debuged & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debuged&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debuged {
#ifdef LOCAL
~debuged() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) (__VA_ARGS__)
// debuged & operator << (debuged & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	debuged() << *it << ": " << imie(a);
	err(++it, args...);
}

void solve(){

}

int32_t main(){

	boost;

	int T;
	
	// cin >> T;
	T = 1;
	
	for(int i = 1; i <= T; ++i){
		solve();
		// cout << "\n";
	}
	return 0;
}

