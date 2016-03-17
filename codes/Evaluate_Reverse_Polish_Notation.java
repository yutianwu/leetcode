public class Solution {
    public int evalRPN(String[] tokens) {
        if (tokens == null || tokens.length == 0) return 0;

        Stack<Integer> st = new Stack<Integer>();
        for (int i = 0; i < tokens.length; i++) {
            if (isOperator(tokens[i])) {
                int right = st.pop();
                int left = st.pop();
                if (tokens[i].equals("+")) {
                    st.push(left + right);
                } else if (tokens[i].equals("-")) {
                    st.push(left - right);
                } else if (tokens[i].equals("*")) {
                    st.push(left * right);
                } else {
                    st.push(left / right);
                }
            } else {
                st.push(Integer.parseInt(tokens[i]));
            }
        }
        return st.pop();
    }

    public boolean isOperator(String op) {
        if (op.equals("+") || op.equals("-") || op.equals("*") || op.equals("/")) return true;
        else return false;
    }
}
