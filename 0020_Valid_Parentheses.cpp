class Solution {
public:
    //Time O(n), Space O(n)
    bool isValid(string s) {
        stack<char> st;
        for(const auto &c : s){
            if(c == '(' || c == '{' || c == '['){
                st.emplace(c);
            }else{
                if(st.empty()){
                    return false;
                }
                char opening = st.top();
                bool status = c==')'&& opening == '(' || c=='}' && opening == '{' || c == ']' && opening == '[';
                if(status == false){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
