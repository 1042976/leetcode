class Solution {
public:
    //T-O(n), S-O(1)
    int maxDistToClosest(vector<int>& seats) {
        int d = INT_MIN;
        vector<int>::iterator it = find(seats.begin(), seats.end(), 1);
        if(it != seats.begin()){
            d = it-seats.begin();
        }
        vector<int>::iterator lastIt = it;
        ++it;
        while(it != seats.end()){
            it = find(it, seats.end(), 1);
            if(it == seats.end()){
                --it;
                d = max((int)(it-lastIt), d);
                break;
            }else{
                d = max((int)((it-lastIt)/2), d);
                lastIt = it;
                ++it;
            }
        }
        return d;
    }
};
