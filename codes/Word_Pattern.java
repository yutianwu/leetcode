/**
    实在不想自己用c++来实现split了。。。就用java吧
*/

public class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] strs = str.split(" ");
        if (strs.length != pattern.length())
            return false;

        Map<String, String> hash = new HashMap<String, String>();
        Map<String, String> set = new HashMap<String, String>();
        for (int i = 0; i < strs.length; i++) {
            String tmp = pattern.substring(i, i + 1);
            if (hash.get(tmp) != null) {
                if (!hash.get(tmp).equals(strs[i]))
                    return false;
            } else {
                if (set.get(strs[i]) == null) {
                     hash.put(tmp, strs[i]);
                     set.put(strs[i], tmp);
                } else 
                    return false;
            }
        }
        return true;
    }
}