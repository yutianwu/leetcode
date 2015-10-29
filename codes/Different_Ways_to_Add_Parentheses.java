public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        if (input == null) 
            return new ArrayList<Integer>();
        
        return helper(input, 0, input.length() - 1);
    }

    public List<Integer> helper(String input, int start, int end) {
        List<Integer> result = new ArrayList<Integer>();

        // 判断是否为数字
        try {
            result.add(Integer.parseInt(input.substring(start, end + 1)));
            return result;
        } catch (Exception e) {

        }

        for (int i = start; i <= end; i++) {
            char operator = input.charAt(i);
            if (operator == '+' || operator == '-' || operator == '*') {
                List<Integer> lefts = helper(input, start, i - 1);
                List<Integer> rights = helper(input, i + 1, end);

                for (Integer left : lefts) {
                    for (Integer right : rights) {
                        int tmp = 0;
                        if (operator == '+')
                            tmp = left + right;
                        else if (operator == '-')
                            tmp = left - right;
                        else if (operator == '*')
                            tmp = left * right;
                            
                        result.add(tmp);
                    }
                }
            }
        }
        return result;
    }
}