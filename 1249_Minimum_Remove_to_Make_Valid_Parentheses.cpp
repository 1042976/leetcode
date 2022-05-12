class Solution {
public:
    //Time O(n), Space O(n)
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int> > st;
        unordered_set<int> hashSet;
        string res = "";
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            if(c == '('){
                st.emplace(make_pair(c, i));
            }else if(c == ')'){
                if(!st.empty() && st.top().first == '('){
                    st.pop();
                }else{
                    st.emplace(make_pair(c, i));
                }
            }
        }
        while(!st.empty()){
            hashSet.insert(st.top().second);
            st.pop();
        }
        for(int i = 0; i < s.length(); ++i){
            if(!hashSet.count(i)){
                res.push_back(s[i]);
            }
        }
        return res;
    }
    
    //Time O(n) Space O(n)
    // string minRemoveToMakeValid(string s){
    //     int b = 0;
    //     string mid = "", res = "";
    //     for(const auto &c : s){
    //         if(c == ')'){
    //             if(b > 0){
    //                 mid.push_back(c);
    //                 --b;
    //             }
    //             continue;
    //         }else if(c == '('){
    //             ++b;
    //         }
    //         mid.push_back(c);
    //     }
    //     int len = mid.length();
    //     b = 0;
    //     for(int i = len-1; i >= 0; --i){
    //         char c = mid[i];
    //         if(c == '('){
    //             if(b < 0){
    //                 res.push_back(c);
    //                 ++b;
    //             }
    //             continue;
    //         }else if(c == ')'){
    //             --b;
    //         }
    //         res.push_back(c);
    //     }
    //     reverse(res.begin(), res.end());
    //     return res;
    // }

};
