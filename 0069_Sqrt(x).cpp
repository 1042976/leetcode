class Solution {
public:
    //Time O(logx), Space O(1)
    // int mySqrt(int x) {
    //    int l = 0, r = x;
    //    while(l < r){
    //        int m = r - ((r-l)>>1);
    //        int q = x/m;
    //        if(m == q){
    //            return m;
    //        }else if(m > q){
    //            r = m-1;
    //        }else{
    //            l = m;
    //        }
    //    }
    //    return l;
    // }
    
    //Newton's method
    //Time O(logx), Space O(1)
    int mySqrt(int x) {
        double y = x;
        int yn = x;
        while(yn > 0){
            if(yn <= x/yn){
                return yn;
            }else{
                y = yn;
                y = 0.5*(y+x/y);
                yn = y;
            }
        }
        return yn;
    }
};
