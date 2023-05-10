/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int getHalf(int low, int high){
        return low + ((high-low)>>1);
    }
    string toStr(vector<int> p1, vector<int> p2){
        return to_string(p1[0])+","+to_string(p1[1])+","+to_string(p2[0])+","+to_string(p2[1]);
    }
    // Time O(MN), Space O(log(max(M, N)). M and N is the length and width of the sea area.
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if(topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1]){
            return 0;
        }
        if(!sea.hasShips(topRight, bottomLeft)){
            return 0;
        }
        if(topRight == bottomLeft){
            return 1;
        }
        vector<int> half = vector<int>{getHalf(bottomLeft[0], topRight[0]), getHalf(bottomLeft[1], topRight[1])};
        unordered_set<string> memo;
        int partialSum = 0;
        // memo.insert(toStr(half, bottomLeft));
        partialSum += countShips(sea, half, bottomLeft);
        if(partialSum == 10){
            return 10;
        }
        partialSum += countShips(sea, topRight, vector<int>{bottomLeft[0], half[1]+1});
        if(partialSum == 10){
            return 10;
        }
        partialSum += countShips(sea, vector<int>{topRight[0], half[1]}, vector<int>{half[0]+1, bottomLeft[1]});
        if(partialSum == 10){
            return 10;
        }
        return partialSum;
    }
};
