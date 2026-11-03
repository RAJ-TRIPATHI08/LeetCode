class Trie {
public:
    bool isEnd;
    Trie* children[26];

    Trie() {
        this->isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;    
    }
    
    void insert(string word) {
        Trie* node = this;

        for(char ch : word)
        {
            int idx = ch - 'a';

            if(node->children[idx] == NULL)
                node->children[idx] = new Trie();

            node = node->children[idx];
        }
        node->isEnd = true;
        return;
    }
    
    bool search(string word) {
        Trie* node = this;

        for(char ch : word)
        {
            int idx = ch - 'a';

            if(node->children[idx] == NULL)
                return false;

            node = node->children[idx];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;

        for(char ch : prefix)
        {
            int idx = ch - 'a';

            if(node->children[idx] == NULL)
                return false;

            node = node->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */