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
        return search(word, pos + 1, cur->next[c - 'a']);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return startsWith(prefix, 0, root);
    }

    bool startsWith(string prefix, int pos, TrieNode *cur) {
        if (cur == NULL) return false;

        if (prefix.size() == pos) return true;
        char c = prefix[pos];
        return startsWith(prefix, pos + 1, cur->next[c - 'a']);
    }

private:
    TrieNode* root;
};

class Solution {
private:
    vector<vector<bool>> visit;
    vector<string> result;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0 || board[0].size() == 0) return {};

        Trie *root = new Trie();
        for (size_t i = 0; i < words.size(); i++)
            root->insert(words[i]);

        visit = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                string tmp = "";
                tmp += board[i][j];
                dfs(board, tmp, i, j, root);
            }
        }
        return result;
    }

    void dfs(vector<vector<char>> &board, string prefix, int x, int y, Trie *root) {
        if (!root->startsWith(prefix)) return;
        if (root->search(prefix)) {
            bool isExist = false;
            for (int i = 0; i < result.size(); i++) {
                if (result[i] == prefix) isExist = true;
            }
            if (!isExist) result.push_back(prefix);
        }

        visit[x][y] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny]) {
                dfs(board, prefix + board[nx][ny], nx, ny, root);
            }
        }
        visit[x][y] = false;
    }
};
