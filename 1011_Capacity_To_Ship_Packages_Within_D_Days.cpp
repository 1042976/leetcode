class Solution {
public:
    //Time O(NlogN), Space O(1)
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for(const auto& w : weights){
            left = max(w, left);
            right += w;
        }
        while(left < right){
            int mid = left + ((right-left)>>1);
            int curWeight = 0;
            int curDay = 0;
            for(const auto &w : weights){
                if(curWeight+w > mid){
                    if(++curDay == days){
                        left = mid+1;
                        break;
                    }
                    curWeight = w;
                }else{
                    curWeight += w;
                }
            }
            if(curDay < days){
                right = mid;
            }
        }
        return left;
    }
};
