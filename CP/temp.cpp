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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
// slow but fast ORZ :)
// ----------------------------------

using namespace std;
using namespace __gnu_pbds; 

#define MEM(a, b) memset(a, (b), sizeof(a))
#define ALL(a) a.begin(), a.end()
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)
#define EB(a) emplace_back(a) // care when use
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0),cout << fixed << setprecision(10);
// #define ll long long int
#define int long long int

#define DEBUG

#ifdef DEBUG

    #define debug(args...)(Debugger()) , args

    class Debugger{
        public:
        Debugger(const std::string& _separator = " | ") :
        first(true), separator(_separator){}

        template<typename ObjectType> Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << std::endl;}

        private:
        
        bool first;
        std::string separator;
    };

#else
    #define debug(args...)
#endif


void solve(){
	
}

unsigned main(){

	boost;
	
	int T;
	
	// cin >> T;
	T = 1;
	
	while(T--){
		solve();
	}
}
