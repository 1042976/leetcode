class Solution {
public:
    //Time O(N), Space O(N)
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> res(heights.size(), 0);
        for(int i = heights.size()-1; i >= 0; --i){
            while(!st.empty() && st.top() < heights[i]){
                ++res[i];
                st.pop();
            }
            if(!st.empty()){
                ++res[i];
            }
            st.emplace(heights[i]);
        }
        return res;
    }
};
