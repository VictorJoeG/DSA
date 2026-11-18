class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor_all = 0;
        for (int num : nums) {
            xor_all ^= num;
        }
        long rightmost = xor_all & -xor_all;  
        int b1 = 0;
        int b2 = 0;
        for (int num : nums) {
            if (num & rightmost) {
                b1 ^= num;
            } else {
                b2 ^= num;
            }
        }
        return {b1, b2};
    }
};
