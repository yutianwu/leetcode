class TrieNode {
public:
    bool isWord;
    vector<TrieNode *> next;
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        next = vector<TrieNode *>(26, NULL);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        insert(word, 0, root);
    }

    void insert(string word, int pos, TrieNode *cur) {
        if (pos == word.size()) {
            cur->isWord = true;
            return;
        }
        char c = word[pos];
        if (cur->next[c - 'a'] == NULL) {
            cur->next[c - 'a'] = new TrieNode();
        }
        insert(word, pos + 1, cur->next[c - 'a']);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if (word.size() == 0) return true;
        return search(word, 0, root);
    }

    bool search(string word, int pos, TrieNode *cur) {
        if (cur == NULL) return false;
        if (word.size() == pos) {
            return cur->isWord == true;
        }

        char c = word[pos];
        if (c != '.')
            return search(word, pos + 1, cur->next[c - 'a']);
        else {
            for (int i = 0; i < 26; i++)
                if (search(word, pos + 1, cur->next[i])) return true;
            return false;
        }
    }
private:
    TrieNode* root;
};

class WordDictionary {
private:
    Trie trie;

public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie.search(word);
    }
};
