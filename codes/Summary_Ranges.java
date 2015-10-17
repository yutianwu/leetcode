// 这题涉及到一些字符串的操作，不想用c++来做
// 思路很简单

public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<String>();
        
        int length = nums.length;
        if (length == 0)
            return result;
            
        int first = nums[0];
        String tmp = first + "";
        for (int i = 1; i < length; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                tmp = first + "->" + nums[i];
            } else {
                result.add(tmp);
                first = nums[i];
                tmp = first + "";
            }
        }
        result.add(tmp);
        
        return result;
    } 
}