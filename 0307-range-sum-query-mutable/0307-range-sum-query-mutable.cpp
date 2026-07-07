class NumArray {
    int n;
    vector<int> seg;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(2 * n);

        // Store elements as leaf nodes
        for (int i = 0; i < n; i++)
            seg[n + i] = nums[i];

        // Build the segment tree
        for (int i = n - 1; i > 0; i--)
            seg[i] = seg[2 * i] + seg[2 * i + 1];
    }

    void update(int index, int val) {
        int pos = index + n;
        seg[pos] = val;

        while (pos > 1) {
            pos /= 2;
            seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
        }
    }

    int sumRange(int left, int right) {
        int l = left + n;
        int r = right + n;
        int sum = 0;

        while (l <= r) {
            if (l % 2 == 1)
                sum += seg[l++];

            if (r % 2 == 0)
                sum += seg[r--];

            l /= 2;
            r /= 2;
        }

        return sum;
    }
};