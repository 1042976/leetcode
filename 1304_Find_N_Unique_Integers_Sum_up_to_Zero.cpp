class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int i = n/2;
        while(i){
            res.emplace_back(i--);
        }
        i = -n/2;
        while(i){
            res.emplace_back(i++);
        }
        if(n%2){
            res.emplace_back(0);
        }
        return res;
    }
};
