class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;

        for (auto &row : matrix) {
            for (int x : row)
                nums.push_back(x);
        }

        sort(nums.begin(), nums.end());
        return nums[k - 1];
    }
};