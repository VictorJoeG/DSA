class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        bool neg = n < 0;

        while (n != 0) {
            if (n % 2 != 0) {
                ans = ans * x;
            }
            x = x * x;
            n = n / 2;
        }

        if (neg) {
            return 1 / ans;
        }
        return ans;
    }
};