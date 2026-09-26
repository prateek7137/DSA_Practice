
class Solution {
public:
int totalHammingDistance(const vector<int>& nums) { 
    int n = nums.size();
    int total = 0;
    // For each bit position (0 to 31)
    for (int bit = 0; bit < 32; ++bit) {
        int countOnes = 0;
        for (int num : nums) {
            countOnes += (num >> bit) & 1;
        }
        int countZeros = n - countOnes;
        total += countOnes * countZeros;
    }
    return total;
}
};
