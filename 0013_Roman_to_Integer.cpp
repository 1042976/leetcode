class Solution {
public:
    unordered_map<char, int> hashMapA{
        {'I', 1}, 
        {'V', 5}, 
        {'X', 10}, 
        {'L', 50}, 
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    unordered_map<string, int> hashMapB{
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900}        
    };
    //Time O(1), Space O(1)
    int romanToInt(string s) {
        int res = 0;
        int i = 0;
        while(i < s.length()-1){
            string b = s.substr(i, 2);
            if(hashMapB.count(b)){
                res += hashMapB[b];
                i += 2;
            }else{
                res += hashMapA[s[i++]];
            }
        }
        if(i == s.length()-1){
            res += hashMapA[s[i]];
        }
        return res;
    }
};
