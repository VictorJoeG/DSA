class Solution {
public:
    void backtrack(int ind, string &num, int target, string path,
                   long long eval, long long prev, vector<string> &ans) {
        if (ind == num.size()) {
            if (eval == target)
                ans.push_back(path);
            return;
        }
        long long curr = 0;
        for (int i = ind; i < num.size(); i++) {
            if (i != ind && num[ind] == '0') break;
            curr = curr * 10 + (num[i] - '0');
            string part = num.substr(ind, i - ind + 1);
            if (ind == 0) {
                backtrack(i+1,num,target,part,curr,curr,ans);
            } else {
                backtrack(i+1,num,target,path+"+"+part,eval+curr,curr,ans);
                backtrack(i+1,num,target,path+"-"+part,eval-curr,-curr,ans);
                backtrack(i+1,num,target,path+"*"+part,eval-prev+prev*curr,prev*curr,ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path = "";
        backtrack(0, num, target, path, 0, 0, ans);
        return ans;
    }
};