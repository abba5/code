const int N = 1e6 + 5;
int Trie[N][26][2];
int trie_now = 0;
int ans = 0;

void add(string &s){
    int s_n = s.size();
    int idx = 0;
    for(int i = 0; i < s_n; ++i){
        if(Trie[idx][s[i] - 'A'][0] == 0){
           Trie[idx][s[i] - 'A'][0] = ++trie_now;
        }
        
        Trie[idx][s[i] - 'A'][1]++;
        idx = Trie[idx][s[i] - 'A'][0];
        
    }
}

void dfs(int idx){
    
    for(int i = 0; i < 26; ++i){
        if((Trie[idx][i][0] != 0) and Trie[idx][i][1] >= k){
            ans += (Trie[idx][i][1] / k);
            dfs(Trie[idx][i][0]);
        }
    }
}

int find(string &s){
    int s_n = s.size();
    int idx = 0;
    
    for(int i = 0; i < s_n; ++i){
        if(Trie[idx][s[i] - 'A'][0] == 0){
            return false;
        }
        idx = Trie[idx][s[i] - 'A'][0]; 
    }
    
    return true;
}
