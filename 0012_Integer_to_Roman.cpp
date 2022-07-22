class Solution {
public:
    vector<pair<string, int> > arr{
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };
    int binarySearch(int start, int end, int num){
        while(start < end){
            int mid = start + ((end-start)>>1)+1;
            if(arr[mid].second > num){
                end = mid-1;
            }else{
                start = mid;
            }
        }
        return start;
    }
    //Time O(1), Space O(1)
    string intToRoman(int num) {
        string res = "";
        int idx = 12;
        while(num > 0){
            idx = binarySearch(0, idx, num);
            int m = num/arr[idx].second;
            for(int i = 0; i < m; ++i){
                res.append(arr[idx].first);
            }
            num %= arr[idx].second;
        }
        return res;
    }
};
