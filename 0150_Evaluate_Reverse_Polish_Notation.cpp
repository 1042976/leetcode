class Solution {
public:
    //Time O(N), Space O(N)
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const auto &s : tokens){
            if(s == "/" || s == "*" || s == "+" || s == "-"){
                int opB = st.top();
                st.pop();
                int opA = st.top();
                st.pop();
                if(s == "/"){
                    st.emplace(opA/opB);
                }else if(s == "*"){
                    st.emplace(opA*opB);
                }else if(s == "+"){
                    st.emplace(opA+opB);
                }else{
                    st.emplace(opA-opB);
                }
            }else{
                st.emplace(stoi(s));
            }
        }
        return st.top();
    }
};
