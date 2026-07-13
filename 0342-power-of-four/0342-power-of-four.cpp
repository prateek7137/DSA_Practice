class Solution {
public:
    bool isPowerOfFour(int n) {

        // A power of 4 must be positive
        if (n <= 0) {
            return false;
        }

        // Keep dividing by 4 until n becomes 1
        while (n > 1) {

            // If n is not divisible by 4,
            // it cannot be a power of 4
            if (n % 4 != 0) {
                return false;
            }
            n = n / 4;
        }
        return true;
    }
};