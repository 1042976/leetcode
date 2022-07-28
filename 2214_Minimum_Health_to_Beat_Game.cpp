class Solution {
public:
    //Time O(N), Space O(1)
    long long minimumHealth(vector<int>& damage, int armor) {
        long long sum = 0;
        int a = 0;
        for(const auto &x : damage){
            if(x >= armor){
                a = armor;
                break;
            }else if(x < armor){
                a = max(a, x);
            }
        }
        for(const auto &x : damage){
            sum += x;
        }
        return sum-a+1;
    }
};
