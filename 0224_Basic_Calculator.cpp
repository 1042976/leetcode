class Solution {
public:
    // int calculate(string &s, int &i){
    //     int res = 0;
    //     char preOperator = '+';
    //     while(i < s.length()){
    //         if(s[i] == ' '){
    //             ++i;
    //         }else if(s[i] == '+' || s[i] == '-'){
    //             preOperator = s[i++];
    //         }else if(s[i] == ')'){
    //             ++i;
    //             break;
    //         }else{
    //             int val = 0;
    //             if(s[i] == '('){
    //                 val = calculate(s, ++i);
    //             }else{
    //                 val = s[i++]-'0';
    //                 while(i < s.length() && isdigit(s[i])){
    //                     val = val*10 + (s[i++]-'0');
    //                 }
    //             }
    //             if(preOperator == '-'){
    //                 res -= val;
    //             }else{
    //                 res += val;
    //             }
    //         }
    //     }
    //     return res;
    // }
    // //Time O(N), Space O(N)
    // int calculate(string s) {
    //     int i = 0;
    //     return calculate(s, i);
    // }
    int update(stack<pair<int, char> >& st, int val){
        if(st.top().second == '-'){
            val = st.top().first-val;
        }else{
            val += st.top().first;
        }
        st.pop();
        return val;
    }
    //Time O(N), Space O(N)
    int calculate(string s){
        stack<pair<int, char> > st;
        int res = 0, i = 0;
        char preOperator = '+';
        while(i < s.length()){
            if(s[i] == ' '){
                ++i;
                continue;
            }else if(s[i] == '-' || s[i] == '+'){
                preOperator = s[i++];
            }else if(s[i] == ')'){
                res = update(st, res);
                ++i;
            }else{
                if(s[i] == '('){
                    st.emplace(make_pair(res, preOperator));
                    res = 0;
                    preOperator = '+';
                    ++i;
                }else{
                    int val = s[i++]-'0';
                    while(i < s.length() && isdigit(s[i])){
                        val = val*10 + (s[i++]-'0');
                    }
                    if(preOperator == '-'){
                        res -= val;
                    }else{
                        res += val;
                    }
                }
            }
        }
        if(!st.empty()){
            res = update(st, res);
        }
        return res;
    }
};
