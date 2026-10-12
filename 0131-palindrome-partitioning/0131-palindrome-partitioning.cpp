class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ans;
        backtrack(s, 0, ans, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& ans, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(ans);
            return;
        }
        for (int end = start + 1; end <= s.length(); ++end) {
            if (isPalindrome(s, start, end - 1)) {
                ans.push_back(s.substr(start, end - start));
                backtrack(s, end, ans, result);
                ans.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};