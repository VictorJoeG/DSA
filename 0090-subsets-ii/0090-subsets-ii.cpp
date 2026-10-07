class Solution {
public:
    void backtrack(int i, vector<int>& temp, vector<int>& nums,
        vector<vector<int>>& ans) {
        int n = nums.size();
        if(i >= n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        backtrack(i + 1, temp, nums, ans);
        temp.pop_back();
        while(i+1 < n && nums[i]==nums[i+1]) i++;
        backtrack(i + 1, temp, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(0, temp, nums, ans);
        return ans;
    }
};