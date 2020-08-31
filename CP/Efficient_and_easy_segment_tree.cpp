// original post: https://codeforces.com/blog/entry/18051

const int N = 1e5 + 5;
int n;
int seg[N];

// to use user function
inline int combine(int a, int b){ 
    return a + b;
} 

// build the tree
void build(vector <int> arr){ 
    
    for(int i = 0; i < n; ++i) 
        seg[i+n] = arr[i];
        
    for(int i = n - 1; i > 0; --i) 
        seg[i] = combine(seg[i<<1], seg[i<<1|1]);
}

// point update
void update(int p, int val){
    for(seg[p += n] = val; p > 1; p >>= 1) 
        seg[p>>1] = combine(seg[p], seg[p^1]);
}

// range update
void update(int l, int r, int val) {
  for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) seg[l++] = combine(seg[l], val);
    if (r&1) seg[--r] = combine(seg[r], val);
  }
}

// sum on interval [l, r)
int query(int l, int r) {  
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = combine(seg[l++], res);
    if (r&1) res = combine(seg[--r], res);
  }
  return res;
}


