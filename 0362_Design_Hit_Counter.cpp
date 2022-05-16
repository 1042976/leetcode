class HitCounter {
public:
    int count;
    queue<pair<int, int> > Q;
    HitCounter():count(0) { 
    }
    
    //T-O(1), S-O(1)
    void hit(int timestamp) {
        if(!Q.empty() && Q.back().first == timestamp){
            ++Q.back().second;
        }else{
            Q.push(make_pair(timestamp, 1));
        }
        ++count;
    }
    
    //T-O(N), S-O(1)
    int getHits(int timestamp) {
        int start = timestamp-299;
        while(!Q.empty() && Q.front().first < start){
            count -= Q.front().second;
            Q.pop();
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
