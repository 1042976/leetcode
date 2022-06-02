class Solution {
public:
    //Time O(LNlogN), Space O(LlogN)
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b)->bool{
            string strA = to_string(a), strB = to_string(b);
            return strA+strB > strB+strA;
        });
        string res = "";
        for(const auto &a : nums){
            res.append(to_string(a));
        }
        if(res[0] == '0'){
            return "0";
        }
        return res;
    }
};
