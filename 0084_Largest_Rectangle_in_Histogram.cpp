class Solution {
public:
    //Time O(N), Space O(N)
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), maxVal = 0;
        stack<int> st;
        st.emplace(-1);
        int topIdx = -1;
        for(int i = 0; i < size; ++i){
            while(topIdx  != -1 && heights[topIdx] > heights[i]){
                int h = heights[topIdx];
                st.pop();
                topIdx = st.top();
                maxVal = max(maxVal, h*(i-topIdx-1));
            }
            st.emplace(i);
            topIdx = i;
        }
        topIdx = st.top();
        while(topIdx != -1){
            int h = heights[topIdx];
            st.pop();
            topIdx = st.top();
            maxVal = max(maxVal, h*(size-topIdx-1));
        }
        return maxVal;
    }
};
