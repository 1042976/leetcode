class Solution {
public:
    //Time O(N), Space O(1)
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = 1, right = 1e+9;
        while(left < right){
            int mid = left + ((right-left)>>1)+1;
            int a = 0, n = 0;
            for(const auto &x : sweetness){
                a += x;
                if(a >= mid){
                    ++n;
                    a = 0;
                }
            }
            if(n >= k+1){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
};
