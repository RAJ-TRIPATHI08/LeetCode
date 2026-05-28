class Trie {
public:
    class trieNode{
    public:
        bool isEndOfWord;
        trieNode* children[26];

        ~trieNode()
        {
            for(int i = 0; i < 26; i++)
                delete children[i];
        }
    };

    trieNode* getNode()
    {
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;

        for(int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }

        return newNode;
    }
    
    trieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crowl = root;

        for(char ch : word)
        {
            int idx = ch - 'a';
            if(crowl->children[idx] == NULL)
                crowl->children[idx] = getNode();

            crowl = crowl->children[idx];
        }
        crowl->isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* crowl = root;

        for(char ch : word)
        {
            int idx = ch - 'a';
            if(crowl->children[idx] == NULL)
                return false;

            crowl = crowl->children[idx];
        }

        if(crowl != NULL && crowl->isEndOfWord)
            return true;

        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crowl = root;
        int i = 0;
        for(char ch : prefix)
        {
            int idx = ch - 'a';
            if(crowl->children[idx] == NULL)
                return false;

            crowl = crowl->children[idx];
            i++;
        }

        if(i == prefix.size())
            return true;
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */