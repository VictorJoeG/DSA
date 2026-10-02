class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long N = n;
        bool neg = N < 0;
        if (neg) N = -N;

        while (N > 0) {
            if (N % 2 == 1) {
                ans = ans * x;
                N = N - 1;
            } else {
                x = x * x;
                N = N / 2;
            }
        }

        if (neg) {
            return 1 / ans;
        }
        return ans;
    }
};