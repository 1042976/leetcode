class Solution {
public:
    //T-O(n), S-O(n). with stack.
    // int calculate(string s) {
    //     stack<int> st;
    //     int curN = 0;
    //     char op = '+';
    //     s.push_back('+');
    //     for(const auto &c : s){
    //         if(isdigit(c)){
    //             curN = curN*10+ (c-'0');
    //         }else if(c == ' '){
    //             continue;
    //         }else{
    //             if(op == '+'){
    //                 st.push(curN);
    //             }else if(op == '-'){
    //                 curN = -curN;
    //                 st.push(curN);
    //             }else if(op == '*'){
    //                 st.top() *= curN;
    //             }else if(op == '/'){
    //                 st.top() /= curN;
    //             }
    //             curN = 0;
    //             op = c;
    //         }
    //     }
    //     while(!st.empty()){
    //         curN += st.top();
    //         st.pop();
    //     }
    //     return curN;
    // }
    
    //T-O(n), S-O(1)
    int calculate(string s){
        int res = 0;
        int k = 0;
        int lastNum = 0;
        char op = '+';
        s.push_back('+');
        for(const auto &c : s){
            if(isdigit(c)){
                k = k*10 + (c-'0');
            }else if(c == ' '){
                continue;
            }else{
                if(op == '+'){
                    res += lastNum;
                    lastNum = k;
                }else if(op == '-'){
                    res += lastNum;
                    lastNum = -k;
                }else if(op == '*'){
                    lastNum *= k;
                }else{
                    lastNum /= k;
                }
                k = 0;
                op = c;
            }
        }
        res += lastNum;
        return res;
    } 
};
