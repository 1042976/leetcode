class Solution {
public:
    //T-O(n), S-O(1)
//     int myAtoi(string s) {
//         if(s.empty()){
//             return 0;
//         }
//         long long res = 0;
//         int sign = 1;
//         int cur = 0;
//         while(cur < s.length() && s[cur] == ' '){
//             ++cur;
//         }
//         if(cur == s.length()){
//             return 0;
//         }
//         if(s[cur] == '-'){
//             sign = -1;
//             ++cur;
//         }else if(s[cur] == '+'){
//             ++cur;
//         }
//         while(cur < s.length() && s[cur] == '0'){
//             ++cur;
//         }
//         if(cur == s.length() || !isdigit(s[cur])){
//             return 0;
//         }
//         while(cur < s.length()){
//             if(isdigit(s[cur])){
//                 res = res*10+(s[cur]-'0');
//                 if(res > INT_MAX){
//                     return sign == 1? INT_MAX : INT_MIN;
//                 }
//             }else{
//                 break;
//             }
//             ++cur;
//         }
//         return sign == 1? res : -res;      
//     }
    class StateMachine{
    public:
        char currentState;
        int res;
        int sign;
        StateMachine(): currentState('A'), res(0), sign(1){}
        void appendDigit(char c){
            if(res > INT_MAX/10 || res == INT_MAX/10 && c-'0' > INT_MAX%10){
                res = sign == 1? INT_MAX : INT_MIN;
                currentState = 'E';
            }else{
                res = res*10+(c-'0');
            }
        }
        int getRes(){
            if(res == INT_MIN){
                return res;
            }           
            return res*sign;
        }
        void handleStateA(char c){
            if(c == ' '){
                return;
            }else if(c == '-' || c == '+'){
                sign = c == '-'? -1 : 1;
                currentState = 'B';
            }else if(isdigit(c)){
                currentState = 'C';
                appendDigit(c);
            }else{
                currentState = 'E';
            }
        }
        void handleStateB(char c){
            if(isdigit(c)){
                currentState = 'C';
                appendDigit(c);
            }else{
                currentState = 'E';
            }
        }
        void handleStateC(char c){
            if(isdigit(c)){
                appendDigit(c);
            }else{
                currentState = 'E';
            }
        }
        void transition(char c){
            if(currentState == 'A'){
                handleStateA(c);
            }else if(currentState == 'B'){
                handleStateB(c);
            }else if(currentState == 'C'){
                handleStateC(c);
            }
        }
    };
    
    //T-O(n), S-O(1)
    int myAtoi(string s){
        StateMachine M;
        for(const auto &c : s){
            M.transition(c);
            if(M.currentState == 'E'){
                break;
            }
        }
        return M.getRes();
    }
};
