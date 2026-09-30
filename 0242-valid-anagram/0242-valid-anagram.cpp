class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> scount;
        unordered_map<char,int> tcount;
        for(int i=0 ; i<s.size(); i++){
            scount[s[i]]+=1;
            tcount[t[i]]+=1;
        }
        if(scount == tcount) return true;
        return false;
    }
};