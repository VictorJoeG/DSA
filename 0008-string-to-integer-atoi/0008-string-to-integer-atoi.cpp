class Solution {
public:
    int myAtoi(string s) {
        int i=0, sign= 1;
        long ans=0;
        //whitespace
        while(i<s.size() && s[i]==' ') i++;
        if(i==s.size()) return 0;
        //signedness 
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if (s[i] =='+') i++;
        //conversion if nondigit
        while(i<s.size() && isdigit(s[i])){
            ans=ans*10 + (s[i]-'0');
        //rounding
            if(sign*ans >INT_MAX) return INT_MAX;
            if(sign*ans <INT_MIN) return INT_MIN;
        i++;
        }
        return (int)(sign*ans);
    }
};