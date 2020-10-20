vector <int> prefix_function(string s){
    int n = s.size();
    vector <int> pr(n);
    
    for(int i = 1, j = 0; i < n; ++i){
        while (j > 0 and s[i] != s[j])
            j = pr[j-1];
        if (s[i] == s[j])
            j++;
        pr[i] = j;
    }

    return pr;
}

vector <int> find_pattern(string text, string pattern, vector <int> &prefix){

    int n = text.size();
    int j = 0;
    int m = pattern.size();
    vector <int> ans;

    for(int i = 0; i < n; ++i){
        if(pattern[j] == text[i]){
            j++;
        }else{
            while(j > 0 and text[i] != pattern[j])
                j = prefix[j];
            
            if(text[i] == pattern[j]){
                ++j;
            }
        }

        if(j == m){
            ans.push_back(i - (m-1));
            j = prefix[j-1];
        }
    }
    return ans;
}

vector <int> kmp(string text, string pattern){
    vector <int> prefix = prefix_function(pattern);

    return find_pattern(text, pattern, prefix);

}
