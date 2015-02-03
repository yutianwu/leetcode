class Solution {
public:
    /*
     找出旋转的点后，就可以判断需要找的数和第一个数的关系，如果要比第一个数大，那么
     就从[0, pivot - 1]范围内找，否则就在[pivot, n - 1]范围内找
     */
    int search(int A[], int n, int target) {
        int pivot = findPivot(A, n);
        if (pivot >= n) {
            return binarySearch(A, target, 0, n - 1);
        } else if (A[0] > target) {
            return binarySearch(A, target, pivot, n - 1);
        } else {
            return binarySearch(A, target, 0, pivot - 1);
        }
    }
    
    //找出旋转的点
    //比如4, 5, 6, 7, 0, 1, 2
    //旋转的点在0
    //其实还有一个规律，就是把数组的第一个数作为哨兵的话，旋转点前面的数都比哨兵大，
    //后面的数都比哨兵小，根据这个规律就可以找出旋转的点
    int findPivot(int A[], int n) {
        int sentinel = A[0];
        int first = 0, last = n - 1;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (A[mid] >= sentinel) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        
        return first;
    }
    
    int binarySearch(int A[], int target, int first, int last) {
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] > target)
                last = mid - 1;
            else
                first = mid + 1;
        }
        return -1;
    }
};
