class Solution {
public:
    void perform(int ind,int n, vector<int>&nums, vector<vector<int>>&ans){
        if(ind == n){
            ans.push_back(nums);
            return;
        }
        unordered_set <int> SET;
        for(int i=ind; i<n;i++){
            if(SET.find(nums[i]) != SET.end()) continue;
            SET.insert(nums[i]);
            swap(nums[ind],nums[i]);
            perform(ind+1,n,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        perform(0,n,nums,ans);
        return ans;
    }
};