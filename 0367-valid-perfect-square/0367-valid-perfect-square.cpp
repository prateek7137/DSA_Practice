class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;

        int L = 1;
        int R = num;

        while (L <= R) {
            long long M = L + (R - L) / 2;
            long long sqr = M * M;

            if (sqr == num) return true;
            else if (sqr > num) R = M - 1;
            else L = M + 1;
        }
        return false;
    }
};