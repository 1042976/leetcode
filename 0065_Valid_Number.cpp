class Solution {
public:
    class StateMachine{
    public:
        char state;
        int firstPartDigits;
        int secondPartDigits;
        StateMachine():state('A'),firstPartDigits(0),secondPartDigits(0){}
        void handleA(char c){
            if(isdigit(c)){
                ++firstPartDigits;
                state = 'B';
            }else if(c == '+' || c == '-'){
                state = 'B';
            }else if(c == '.'){
                state = 'D';
            }else{
                state = 'E';
            }
        }
        void handleB(char c){
            if(c == '.'){
                state = 'D';
            }else if(tolower(c) == 'e'){
                if(firstPartDigits == 0){
                    state = 'E';
                }else{
                    state = 'C'; 
                    firstPartDigits = 0;
                }
            }else if(isdigit(c)){
                ++firstPartDigits;
            }else{
                state = 'E';
            }
        }
        void handleD(char c){
            if(tolower(c) == 'e'){
                if(firstPartDigits == 0 && secondPartDigits == 0){
                    state = 'E';
                }else{
                    state = 'C';
                    firstPartDigits = 0;
                    //secondPartDigits = 0;
                }
            }else if(isdigit(c)){
                ++secondPartDigits;
            }else{
                state = 'E';
            }
        }
        
        void handleC(char c){
            if(isdigit(c)){
                ++firstPartDigits;
                state = 'F';
            }else if(c == '+' || c == '-'){
                state = 'F';
            }else{
                state = 'E';
            }
        }
        
        void handleF(char c){
            if(isdigit(c)){
                ++firstPartDigits;
            }else{
                state = 'E';
            }
        }
        
        void transition(char c){
            switch(state){
                case 'A': handleA(c);break;
                case 'B': handleB(c);break;
                case 'C': handleC(c);break;
                case 'D': handleD(c);break;
                case 'F': handleF(c);break;
                default: return;
            }
        }
        
        bool isValid(){
            if(state == 'B' || state == 'F'){
                return firstPartDigits > 0;
            }else if(state == 'D'){
                return firstPartDigits > 0 || secondPartDigits > 0;
            }else{
                return false;
            }
        }
    };
    //Time O(n), Space O(1)
    bool isNumber(string s) {
        StateMachine stateMachine;
        for(const auto &c : s){
            stateMachine.transition(c);
            if(stateMachine.state == 'E'){
                return false;
            }
        }
        return stateMachine.isValid();
    }
};
