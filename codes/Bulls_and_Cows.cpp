class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> wrong;
        int bull = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bull++;
            else if (wrong.find(secret[i]) == wrong.end()){
                wrong[secret[i]] = 1;
            } else {
                wrong[secret[i]] += 1;
            }
        }

        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] != guess[i]) {
                if (wrong.find(guess[i]) != wrong.end() && wrong[guess[i]] > 0) {
                    wrong[guess[i]] -= 1;
                    cows++;
                }
            }
        }
        return to_string(bull) + "A" + to_string(cows) + "B";
    }
};
