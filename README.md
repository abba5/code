# code
## competitive programming codes in C++

### Programming setup
#### Geany Editor

**install:**
> sudo apt install geany

**compile:** [F8]
> g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result

**build:** [F9]
> g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG  -DLOCAL

#### Guake Terminal
**open/close:** [F12]

**install:**
> sudo apt install guake

#### Template
> CP/template.cpp
- Not to use (dev = developer) code becase it is working too slow for competitive programming.
I got TLE because of this code.
Use CP code for competitive programming.
