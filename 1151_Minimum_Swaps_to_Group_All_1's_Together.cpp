class Solution {
public:
    //Time O(N), Space O(1)
    int minSwaps(vector<int>& data) {
        int curN = 0, maxN = 0, total = 0;
        for(const auto &x : data){
            total += x;
        }
        for(int i = 0; i < total; ++i){
            curN += data[i];
        }
        maxN = curN;
        for(int i = total; i < data.size(); ++i){
            curN += data[i]-data[i-total];
            maxN = max(curN, maxN);
        }
        return total-maxN;
    }
};
