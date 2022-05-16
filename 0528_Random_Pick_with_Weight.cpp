class Solution {
public:
    vector<int> ranges;
    //Time O(n), Space O(n)
    Solution(vector<int>& w):ranges(vector<int>(w.size()+1, 0)) {
        for(size_t i = 0; i < w.size(); ++i){
            ranges[i+1] = ranges[i]+w[i];
        }
        srand(time(NULL));
    }
    
    //Time O(logn) Space O(1)
    int pickIndex() {
        int a = rand()%ranges.back();
        int l = 0, r = ranges.size()-1;
        while(l < r){
            int m = l+((r-l)>>1);
            if(ranges[m] <= a && ranges[m+1] > a){
                return m;
            }else if(ranges[m] > a){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
