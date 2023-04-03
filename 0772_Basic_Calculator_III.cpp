class Solution {
public:
    int calculate(string &s, int &i){
        vector<int> arr;
        char preOperator = '+';
        while(i < s.length()){
            if(isdigit(s[i]) || s[i] == '('){
                int val;
                if(s[i] == '('){
                    val = calculate(s, ++i);                  
                }else{
                    val = s[i]-'0';
                    int j = i+1;
                    while(j < s.length() && isdigit(s[j])){
                        val = val*10+s[j++]-'0';
                    }
                    i = j;
                }
                switch(preOperator){
                    case '*': arr.back() *= val; break;
                    case '/': arr.back() /= val; break;
                    case '-': arr.emplace_back(-val); break;
                    default: arr.emplace_back(val);
                };
            }else if(s[i] == ')'){
                ++i;
                break;
            }else{
                preOperator = s[i++];
            }
        }
        int res = 0;
        for(const auto &x : arr){
            res += x;
        }
        return res;
    }
    //Time O(N), Space O(N)
    int calculate(string s) {
        int i = 0;
        return calculate(s, i);
    }
};
