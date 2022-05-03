class Trie{
    public:
    Trie* child[27];
    int index = -1;
};

class WordFilter {
public:
    Trie *trie, *child;
    void insert(string word, int pos) {
        Trie *curr = trie;
        for (char c : word) {
            auto it = curr->child[c - 'a'];
            if (!it) curr->child[c - 'a'] = new Trie();
            curr = curr->child[c - 'a'];
            curr->index = pos;
        }
    }
    
    int search(string word) {
        int index;
        Trie *curr = trie;
        for (char c: word) {
            if (!curr->child[c - 'a']) return -1;
            curr = curr->child[c - 'a'];
        }
        return curr->index;
    }
    
    WordFilter(vector<string>& words) {
        int n = words.size();
        trie = new Trie();
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                string s = words[i].substr(j) + char('z'+1) + words[i];
                insert(s, i);        
            }    
        }
    }
    
    int f(string prefix, string suffix) {
        return search(suffix + char('z'+1) + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */