class TrieNode {
public:
    vector<TrieNode *> trie;
    bool isWord;
    // Initialize your data structure here.
    TrieNode() {
        trie = vector<TrieNode *>(26, NULL);
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (cur->trie[ch - 'a'] == NULL) { 
                TrieNode * newNode = new TrieNode();
                cur->trie[ch - 'a'] = newNode;
            }
            cur = cur->trie[ch - 'a'];
            if (i == word.size() - 1) 
                cur->isWord = true;
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) { 
            char ch = word[i];
            if (cur->trie[ch - 'a'] == NULL) 
                return false;

            cur = cur->trie[ch - 'a'];
            if (i == word.size() - 1 && cur->isWord == true) 
                return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (int i = 0; i < prefix.size(); i++) { 
            char ch = prefix[i];
            if (cur->trie[ch - 'a'] == NULL) 
                return false;

            cur = cur->trie[ch - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");