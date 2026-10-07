class Solution {
public:
    void perform(int ind, int k, int target, int sum,vector<int>& temp,vector<vector<int>>& ans) {
        if(temp.size() > k || sum > target)
            return;
        if(ind > 9) {
            if(temp.size() == k && sum == target)
                ans.push_back(temp);
            return;
        }
        temp.push_back(ind);
        perform(ind + 1, k, target, sum + ind, temp, ans);
        temp.pop_back();
        perform(ind + 1, k, target, sum, temp, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        perform(1, k, n, 0, temp, ans);
        return ans;
    }
};