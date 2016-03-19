class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> stk;
        stringstream ss(preorder);
        string node;
        while(getline(ss, node, ',')) {
            if (stk.size() == 1 && stk.top() == "#") return false;

            if (node == "#") {
                if (stk.empty()) stk.push(node);
                else stk.pop();
            } else {
                stk.push(node);
            }
        }

        if (stk.size() == 1 && stk.top() == "#") return true;
        else return false;
    }
};
