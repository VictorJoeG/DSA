class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int ind = 0; ind < 32; ind++) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] & (1 << ind)) {
                    count++;
                }
            }
            if (count % 3 == 1) {
                ans = ans | (1 << ind);
            }
        }
        return ans;
    }
};
