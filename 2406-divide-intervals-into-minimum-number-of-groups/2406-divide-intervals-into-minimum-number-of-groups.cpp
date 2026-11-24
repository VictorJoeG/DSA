class Solution {
public:
    int minGroups(vector<vector<int>>&arr) {
        vector<int>start_time,end_time;
        for(int i=0;i<arr.size();i++){
            start_time.push_back(arr[i][0]);
            end_time.push_back(arr[i][1]);
        }
        sort(start_time.begin(),start_time.end());
        sort(end_time.begin(),end_time.end());
        int s=0,e=0,cnt=0;
        while(s<arr.size()){
            if(start_time[s]>end_time[e])e++;
            else cnt++;
            s++;
        }
        return cnt;
    }
};