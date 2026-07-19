class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        int left = 1, right = n - 2;

        if(arr[0] > arr[1]) return 0;

        if(arr[n - 1] > arr[n - 2]) return n - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(arr[mid - 1] < arr[mid] &&
               arr[mid] > arr[mid + 1])
            {
                return mid;
            }

            if(arr[mid - 1] < arr[mid])
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};