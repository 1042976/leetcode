class Solution {
public:
    //Time O(N), Space O(N)
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0, mod = 1e+9+7;
        stack<int> st;
        st.emplace(-1);
        arr.emplace_back(0);
        for(int i = 0; i < arr.size(); ++i){
            while(st.top() != -1 && arr[st.top()] > arr[i]){
                int j = st.top();
                st.pop();
                sum += (long long)arr[j] * (j-st.top())*(i-j);
                sum %= mod;
            }
            st.emplace(i);
        }
        return sum;
    }
};
