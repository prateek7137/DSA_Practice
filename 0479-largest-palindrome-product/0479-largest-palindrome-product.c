#include <math.h>

int largestPalindrome(int n) {
    if (n == 1) return 9;

    long long hi = (long long)pow(10, n) - 1;
    long long lo = (long long)pow(10, n - 1);
    long long top = (hi / 11) * 11;

    for (long long left = hi; left >= lo; left--) {

        long long x = left, res = left;

        while (x > 0) {
            res = res * 10 + (x % 10);
            x /= 10;
        }

        for (long long d = top; d >= left; d -= 11) {
            if (res % d == 0) {
                long long q = res / d;

                if (q >= lo && q <= hi) {
                    return (int)(res % 1337);
                }
            }
        }
    }

    return -1; 
}