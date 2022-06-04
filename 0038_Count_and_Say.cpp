class Solution {
public:
    //Time O(n^2), Space O(n^2)
    // string countAndSay(int n) {
    //     if(n == 1){
    //         return "1";
    //     }
    //     string res = "";
    //     string lastStr = countAndSay(n-1);
    //     char curDigit = lastStr[0];
    //     int count = 1;
    //     for(int i = 1; i < lastStr.length(); ++i){
    //         if(lastStr[i] == curDigit){
    //             ++count;
    //         }else{
    //             res.append(to_string(count));
    //             res.push_back(curDigit);
    //             curDigit = lastStr[i];
    //             count = 1;
    //         }
    //     }
    //     res.append(to_string(count));
    //     res.push_back(curDigit);       
    //     return res;
    // }
    
    //Time O(n^2), Space O(n)
    string countAndSay(int n) {
        string str = "1";
        for(int i = 1; i < n; ++i){
            char curDigit = str[0];
            int count = 1;
            string str2 = "";
            for(int j = 1; j < str.length(); ++j){
                if(str[j] == curDigit){
                    ++count;
                }else{
                    str2.append(to_string(count));
                    str2.push_back(curDigit);
                    curDigit = str[j];
                    count = 1;
                }
            }
            str = str2;
            str.append(to_string(count));
            str.push_back(curDigit); 
        }
        return str;
    }
};
