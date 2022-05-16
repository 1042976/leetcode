/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    //Time O(n), Space O(1).
    int findCelebrity(int n) {
        int potential = 0;
        int other = 1;
        while(other < n){
            if(knows(potential, other)){
                potential = other;
            }
            ++other;
        }
        for(other = 0; other < n; ++other){
            if(other == potential){
                continue;
            }
            if(!knows(other, potential) || knows(potential, other)){
                return -1;
            }
        }
        return potential;
    }
};
