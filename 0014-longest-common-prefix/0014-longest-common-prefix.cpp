class Solution {
public:
    string merge(string left, string right) {
        int minLen = std::min(left.length(), right.length());
        for (int i = 0; i < minLen; i++) {
            if (left[i] != right[i]) return left.substr(0, i);
        }
        return left.substr(0, minLen);
    }

    string LCP(vector<string>& strs, int low, int high) {
        if (low == high) {
            return strs[low];
        } else {
            int mid = (low + high) / 2;
            string lcpLeft = LCP(strs, low, mid);
            string lcpRight = LCP(strs, mid + 1, high);
            return merge(lcpLeft, lcpRight);
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        return LCP(strs, 0, strs.size() - 1);
    }
};