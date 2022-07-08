class Solution {
public:
    //Time O(N), Space O(1)
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m*k){
            return -1;
        }
        int left = 1, right = 1e+9;
        while(left < right){
            int mid = left + ((right-left)>>1);
            int cur = 0;
            int n = 0;
            for(const auto &x : bloomDay){
                if(x <= mid){
                    if(++cur == k){
                        ++n;
                        cur = 0;
                    }
                }else{
                    cur = 0;
                }
            }
            if(n < m){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
