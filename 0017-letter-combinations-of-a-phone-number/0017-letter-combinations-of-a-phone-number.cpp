class Solution {
public:
    void perform(int ind, string &digits, string &temp,unordered_map<char, string> mp, vector<string> &ans){
        if(ind >= digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch = digits[ind];
        string str = mp[ch];
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            perform(ind+1,digits,temp,mp,ans);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string temp="";
        vector<string> ans;
        perform(0,digits,temp,mp,ans);
        return ans;
    }
};