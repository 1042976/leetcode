class Solution {
public:
    //T-O(maxK*n), S-O(n)
    // string decodeString(string s) {
    //     string res = "";
    //     int i = 0;
    //     while(i < s.length()){
    //         if(isalpha(s[i])){
    //             res.push_back(s[i]);
    //             ++i;
    //         }else{
    //             int k = s.find('[', i);
    //             int n = stoi(s.substr(i, k-i));
    //             int count = 1;
    //             int j = (++k);
    //             while(count != 0){
    //                 if(s[j] == '['){
    //                     ++count;
    //                 }else if(s[j] == ']'){
    //                     --count;
    //                 }
    //                 ++j;
    //             }
    //             i = j--;
    //             string subRes = decodeString(s.substr(k, j-k));
    //             while(n--){
    //                 res.append(subRes);
    //             }
    //         }
    //     }
    //     return res;
    // }
    
    //T-O(maxK * N), S-O(N)
    string decodeString(string s){
        int k = 0;
        string curStr = "";
        stack<int> stN;
        stack<string> stS;
        for(const auto &c : s){
            if(isdigit(c)){
                k = k*10+(c-'0');
            }else if(isalpha(c)){
                curStr.push_back(c);
            }else if(c == '['){
                stN.push(k);
                stS.push(curStr);
                k = 0;
                curStr = "";
            }else{
                int tmpK = stN.top();
                stN.pop();
                string tmpStr = curStr;
                curStr = stS.top();
                stS.pop();
                while(tmpK--){
                    curStr.append(tmpStr);
                }
            }
        }
        return curStr;
    }
};
