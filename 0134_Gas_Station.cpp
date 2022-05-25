class Solution {
public:
    //Time O(n), Space O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int oldBalance = 0;
        int balance = 0;
        int j = -1;
        for(int i = 0; i < gas.size(); ++i){
            int dif = gas[i]-cost[i];
            if(dif < 0){
                balance += dif;
                if(balance < 0){
                    j = -1;
                }
            }else{
                if(j == -1){
                    j = i;
                    oldBalance += balance;
                    balance = dif;
                }else{
                    balance += dif;
                }
            }
        }
        return oldBalance + balance >= 0? j : -1;
    }
};
