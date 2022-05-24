class Solution {
public:
    //Time O(n), Space O(1)
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int i = 0;
        while(i < strs[0].length()){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j){
                if(i == strs[j].length() || strs[j][i] != c){
                    return res;
                }
            }
            res.push_back(c);
            ++i;
        }
        return res;
    }
};
