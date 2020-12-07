const int max_len = 100500, max_alpha = 26;

int t[max_len][max_alpha];
int szT;

int root;

int newT() {
    return ++szT;
}

void dfs(int v) {
    bool isLeaf = true; //
    for (int i = 0; i < max_alpha; i++) {
        if (t[v][i] != 0) {
            isLeaf = false;
            int to = t[v][i];
            dfs(to);
        }
    }
    if (isLeaf) {
    }
}


void addTrie(string s) {
    int len = s.size();
    int v = root;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (t[v][c] == 0) t[v][c] = newT();
        v = t[v][c];
    }
}
