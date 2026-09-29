class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string newstring = s+s;
        if(newstring.find(goal) < newstring.size()){
            return true;
        }
        else{
            return false;
        }
    }
};