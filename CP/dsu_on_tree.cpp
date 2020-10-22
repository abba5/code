
/* Using start and ending postion */
/* -------------------------- */

const int N = 1e5 + 5;
int siz[N];
int start[N];
int ending[N];
int ver[N];
int t = 0;

int dfs1(int u, int p){
	start[u] = t;
	ver[t++] = u;

	for(auto c: g[u]){
		if(c == p) continue;
		siz[u] += dfs1(c, u);
	}
	siz[u]++;
	ending[u] = t;
	return siz[u];
}

void dfs(int v, int p, bool keep){

    int mx = -1, bigChild = -1;
    
	for(auto u : g[v])
       if(u != p && siz[u] > mx)
          mx = siz[u], bigChild = u;

    for(auto u : g[v]){
        if(u != p && u != bigChild)
            dfs(u, v, 0);
	}

	if(bigChild != -1)
        dfs(bigChild, v, 1);

	int max_e = 0;
	int ans = 0;

	auto update = [&](int pp){

	};

	auto remove = [&](int pp){
	};

    for(auto u : g[v])
		if(u != p && u != bigChild)
			for(int pp = start[u]; pp < ending[u]; pp++){
				update(pp);
			}

	update(start[v]);
	
	if(keep == 0)
        for(int pp = start[v]; pp < ending[v]; pp++)
	    	remove(pp);

}




/* ---------------------------------------- */
/* Hevy Light Decomposiitona */


int cnt[N];
bool big[N];
int col[N];

int dfs1(int u, int p){

	for(auto c: g[u]){
		if(c == p) continue;
		siz[u] += dfs1(c, u);
	}
	siz[u]++;
	return siz[u];
}

void add(int v, int p, int x){
    
    cnt[ col[v] ] += x;
    
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x)

}

void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    
    for(auto u : g[v])
       if(u != p && siz[u] > mx)
          mx = siz[u], bigChild = u;

    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);

    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;
    
    add(v, p, 1);


    // do something here
    
    if(bigChild != -1)
        big[bigChild] = 0;
    
    if(keep == 0)
        add(v, p, -1);
}