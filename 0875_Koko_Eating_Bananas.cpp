class Solution {
public:
    //Time O(N), Space O(1)
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e+9;
        while(left < right){
            int mid = left + ((right-left)>>1);
            int t = 0;
            for(const auto &x : piles){
                t += (x+mid-1)/mid;
            }
            if(t > h){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
