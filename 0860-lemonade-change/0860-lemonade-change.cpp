class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivedollars=0;
        int tendollars=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fivedollars+=1;
            }
            else if(bills[i]==10){
                if(fivedollars){
                    tendollars+=1;
                    fivedollars-=1;
                }
                else return false;
            }
            else{
                if(tendollars && fivedollars){
                    fivedollars-=1;
                    tendollars-=1;
                }
                else if(fivedollars>=3) fivedollars-=3;
                else return false;
            }
        }
        return true;
    }
};