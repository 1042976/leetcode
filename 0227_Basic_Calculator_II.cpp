class Solution {
public:
    //Time O(N), Space O(1)
    // int calculate(string s) {
    //     int res = 0, a = 0, b = 0;
    //     char op = '+';
    //     s.push_back('+');
    //     int sign = 1;
    //     for(const auto &c : s){
    //         if(isdigit(c)){
    //             b = b*10 + (c-'0');
    //         }else if(c != ' '){
    //             if(op == '*'){
    //                 b *= a;
    //             }else if(op == '/'){
    //                 b = a/b;
    //             }
    //             if(c == '+' || c == '-'){
    //                 res += b*sign;
    //                 a = 0;
    //                 sign = c == '+'? 1 : -1;
    //             }else{
    //                 a = b;
    //             }
    //             b = 0;
    //             op = c;
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(1)
    int calculate(string s){
        int res = 0, a = 0, b = 0;
        char op = '+';
        s.push_back('+');
        for(const auto &x : s){
            if(isdigit(x)){
                b = b*10 + (x-'0');
            }else if(x != ' '){
                if(op == '+'){
                    res += a;
                    a = b;
                }else if(op == '-'){
                    res += a;
                    a = -b;
                }else if(op == '*'){
                    a *= b;
                }else{
                    a /= b;
                }
                b = 0;
                op = x;
            }
        }
        return res+a;
    }
};
