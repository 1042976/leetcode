class Solution {
public:
    //Time O(log(max(tx, ty))), Space O(1)
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy){
            if(tx > ty){
                if(ty > sy){
                    tx %= ty; 
                }else{
                    return ((tx-sx) % ty) == 0;
                }
            }else if(tx < ty){
                if(tx > sx){
                    ty %= tx;
                }else{
                    return ((ty-sy) % tx) == 0;
                }
            }else{
                break;
            }
        }
        return tx == sx && ty == sy;
    }
};
