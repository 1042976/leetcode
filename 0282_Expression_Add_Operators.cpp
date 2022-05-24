class Solution {
public:
    // vector<string> arr;
    // long long calculate(long long &last, char &lastOperator, long long &cur){
    //     if(lastOperator == '-'){
    //         return last-cur;
    //     }else if(lastOperator == '+'){
    //         return last+cur;
    //     }else{
    //         return last*cur;
    //     }
    // }
    // void backtrack(string &num, string &expression, int k, long long lastVal, long long lastOperand, char lastOperator, long long curOperand, char curOperator, int target){
    //     long long curOperand2 = curOperand;
    //     long long curDigits = 0;
    //     for(int i = k; i < num.length(); ++i){
    //         int len = i-k+1;
    //         if(len > 1 && num[k] == '0'){
    //             return;
    //         }
    //         curDigits = curDigits*10 + num[i]-'0';
    //         int lastSize = expression.size();
    //         expression.append(num.substr(k, len));
    //         if(curOperator == '*'){
    //             curOperand = curOperand2 * curDigits;
    //         }else{
    //             curOperand = curDigits;
    //         }
    //         //curOperand = calculate(curOperand2, curOperator, curDigits);
    //         if(i < num.length()-1){
    //             expression.push_back('+');
    //             backtrack(num, expression, i+1, lastVal+calculate(lastOperand, lastOperator, curOperand), 0, '+', 0, '+', target);
    //             expression.back() = '-';
    //             backtrack(num, expression, i+1, lastVal+calculate(lastOperand, lastOperator, curOperand), 0, '-', 0, '+', target);
    //             expression.back() = '*';               
    //             backtrack(num, expression, i+1, lastVal, lastOperand, lastOperator, curOperand, '*', target);
    //             expression.pop_back();                    
    //         }else{
    //             lastVal += calculate(lastOperand, lastOperator, curOperand);
    //             if(lastVal == target){
    //                 arr.emplace_back(expression);
    //             }
    //         }
    //         expression.erase(expression.begin()+lastSize, expression.end());
    //     }
    // }
    // //Time O(4^n), Space O(n)
    // vector<string> addOperators(string num, int target) {
    //     string expression;
    //     backtrack(num, expression, 0, 0, 0, '+', 0, '+', target);
    //     return arr;
    // }

    //Time O(4^n), Space O(n)
    vector<string> arr;
    void backtrack(string &num, string &expression, int k, long long val, long long lastOperand, int target){
        if(k == num.length()){
            if(val == target){
                arr.emplace_back(expression);
            }
            return;
        }
        long long curOperand = 0;
        for(int i = k; i < num.length(); ++i){
            int len = i-k+1;
            if(len > 1 && num[k] == '0'){
                return;
            }
            curOperand = curOperand*10+num[i]-'0';
            int lastSize = expression.length();
            expression.append(num.substr(k, len));
            if(k == 0){
                backtrack(num, expression, i+1, val+curOperand, curOperand, target); 
            }else{
                expression.insert(lastSize, "+");
                backtrack(num, expression, i+1, val+curOperand, curOperand, target); 
                expression[lastSize] = '-';
                backtrack(num, expression, i+1, val-curOperand, -curOperand, target);
                expression[lastSize] = '*';
                backtrack(num, expression, i+1, val-lastOperand+lastOperand*curOperand, lastOperand*curOperand, target);
            }
            expression.erase(expression.begin()+lastSize, expression.end());
            
        }
        
    }
    vector<string> addOperators(string num, int target) {
        string expression;
        backtrack(num, expression, 0, 0, 0, target);
        return arr;       
    }
};
