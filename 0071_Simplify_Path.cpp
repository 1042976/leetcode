class Solution {
public:
    class StateMachine{
      public:
        string canonicalPath;
        char state;
        int numOfPeriods;
        StateMachine():canonicalPath("/"), state('A'), numOfPeriods(0){}
        void handleA(char c){
            if(c == '/'){
                return;
            }else if(c == '.'){
                ++numOfPeriods;
                state = 'C';
            }else{
                canonicalPath.push_back(c);
                state = 'B';
            }
        }
        void handleB(char c){
            canonicalPath.push_back(c);
            if(c == '/'){
                state = 'A';
            }
        }
        void handleC(char c){
            if(c == '.'){
                if(++numOfPeriods >= 3){
                    state = 'B';
                    canonicalPath.append("...");
                    numOfPeriods = 0;
                }
            }else if(c == '/'){
                state = 'A';
                if(numOfPeriods == 2){
                    if(canonicalPath.length() > 1){
                        canonicalPath.pop_back();
                        size_t idx = canonicalPath.rfind('/');
                        canonicalPath.erase(canonicalPath.begin()+idx+1,canonicalPath.end());
                    } 
                }
                numOfPeriods = 0;
            }else{
                canonicalPath.append(string(numOfPeriods, '.'));
                numOfPeriods = 0;
                canonicalPath.push_back(c);
                state = 'B';
            }
        }
        void transition(char c){            
            if(state == 'A'){
                handleA(c);
            }else if(state == 'B'){
                handleB(c);
            }else{
                handleC(c);
            }
        }
        string getCanonicalPath(){
            return canonicalPath.back() == '/' && canonicalPath.size()>1? canonicalPath.substr(0, canonicalPath.size()-1) : canonicalPath;
        }
    };
    //Time O(n) Space O(n)
    string simplifyPath(string path) {
        StateMachine stateMachine;
        for(const auto &c : path){
            stateMachine.transition(c);
        }
        stateMachine.transition('/');
        return stateMachine.getCanonicalPath();
    }
    
    //Timr O(n), Space O(n)
    // string simplifyPath(string path){
    //     path.push_back('/');
    //     stack<char> st;
    //     st.emplace('/');
    //     int numOfPeriods = 0;
    //     for(const auto &c : path){
    //         if(c == '/'){
    //             if(numOfPeriods == -1 || numOfPeriods >= 3){
    //                 st.emplace(c);
    //             }else if(numOfPeriods == 1){
    //                 st.pop();
    //             }else if(numOfPeriods == 2){
    //                 st.pop();
    //                 st.pop();
    //                 if(st.size() == 1){
    //                     numOfPeriods = 0;
    //                     continue;
    //                 }
    //                 st.pop();
    //                 while(st.top() != '/'){
    //                     st.pop();
    //                 }
    //             }
    //             numOfPeriods = 0;
    //         }else if(c == '.'){
    //             if(numOfPeriods != -1){
    //                 ++numOfPeriods;
    //             }
    //             st.emplace(c);
    //         }else{
    //             numOfPeriods = -1;
    //             st.emplace(c);
    //         }
    //     }
    //     while(st.size() > 1 && st.top() == '/'){
    //         st.pop();
    //     }
    //     string res = "";
    //     while(!st.empty()){
    //         res.push_back(st.top());
    //         st.pop();
    //     }
    //     reverse(res.begin(), res.end());
    //     return res;
    // }
};
