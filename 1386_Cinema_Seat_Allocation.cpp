class Solution {
public:
    //T-O(n), S-O(k)
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //0000011110, 2-5 empty, 30
        //0001111000, 4-7 empty, 120
        //0111100000, 6-9 empty, 480
        int res = 0;
        unordered_map<int, int> hashMap;
        for(const auto &x : reservedSeats){
            hashMap[x[0]] |= (1<<(x[1]-1));
        }
        res += (n-hashMap.size())*2;
        for(const auto &[row, status] : hashMap){
            bool a = (status&30) == 0;
            bool b = (status&120) == 0;
            bool c = (status&480) == 0;
            res += (a&&c? 2 : (a||b||c? 1 : 0));
        }
        return res;
    }
};
