class RangeModule {
private:
    map<int, int> ranges;
public:
    RangeModule() {
        
    }
    //Time Avg-O(logN), worst-O(N); Space O(1)
    void addRange(int left, int right) {
        auto it1 = ranges.upper_bound(left);
        auto it2 = ranges.upper_bound(right);
        if(it1 != ranges.begin() && (--it1)->second < left){
            ++it1;
        }
        if(it1 != it2){
            left = min(it1->first, left);
            right = max((--it2)->second, right);
            ranges.erase(it1, ++it2);
        }
        ranges[left] = right;
    }
    
    //Time O(logN); Space O(1)
    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound(left);     
        return it != ranges.begin() && (--it)->second >= right;
    }
    
    //Time Avg-O(logN), worst-O(N); Space O(1)
    void removeRange(int left, int right) {
        auto it1 = ranges.upper_bound(left);
        auto it2 = ranges.upper_bound(right);
        if(it1 != ranges.begin() && (--it1)->second < left){
            ++it1;
        }
        if(it1 != it2){
            int a = min(it1->first, left);
            int b = max((--it2)->second, right);
            ranges.erase(it1, ++it2);
            if(a < left){
                ranges[a] = left;
            }
            if(b > right){
                ranges[right] = b; 
            }
        }
    }
};


/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
