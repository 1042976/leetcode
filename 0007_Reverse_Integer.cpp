class Solution {
public:
    //Time O(logx), Space O(1)
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int y = x%10;
            if(x < 0){
                if(INT_MIN/10 > res || INT_MIN-y > res*10){
                    return 0;
                }
            }else{
                if(INT_MAX/10 < res || INT_MAX-y < res*10){
                    return 0;
                }
            }
            res = res*10+y;
            x /= 10;
        }
        return res;
    }
};
