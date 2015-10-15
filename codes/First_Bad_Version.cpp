// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 0, end = n;
        while (end - begin > 1) {
            int mid = begin + (end - begin) / 2;   
        
            if (isBadVersion(mid)) 
                end = mid;
            else 
                begin = mid;
        }
        return end;
    }
};