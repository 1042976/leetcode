class Solution {
public:
    //T-O(maxK*n), S-O(n)
    string decodeString(string s) {
        string res = "";
        int i = 0;
        while(i < s.length()){
            if(isalpha(s[i])){
                res.push_back(s[i]);
                ++i;
            }else{
                int k = s.find('[', i);
                int n = stoi(s.substr(i, k-i));
                int count = 1;
                int j = (++k);
                while(count != 0){
                    if(s[j] == '['){
                        ++count;
                    }else if(s[j] == ']'){
                        --count;
                    }
                    ++j;
                }
                i = j--;
                string subRes = decodeString(s.substr(k, j-k));
                while(n--){
                    res.append(subRes);
                }
            }
        }
        return res;
    }
};
