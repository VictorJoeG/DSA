class Solution {
public:
    void Perform(int ind, int target, vector<int>&nums, vector<vector<int>> &ans, vector<int> &temp, int n){
    if(ind==n){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }
    
    if(nums[ind] <=target){
        temp.push_back(nums[ind]);
        Perform(ind,target - nums[ind],nums,ans,temp,n);
        temp.pop_back();
    }
    Perform(ind+1,target,nums,ans,temp,n);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        Perform(0,target,candidates,ans,temp,n);
        return ans;
    }
};