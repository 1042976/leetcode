class Solution {
public:
    //Time O(N), Space O(N)
    int totalStrength(vector<int>& strength) {
        long long res = 0, mod = 1e+9+7;
        int n = strength.size();
        unsigned long long sumOfSum[n+2];
        sumOfSum[0] = 0;
        for(int i = 0; i < n; ++i){
            sumOfSum[i+1] = (sumOfSum[i]+strength[i]);
        }
        long long pre = 0;
        for(int i = 0; i <= n; ++i){
            long long tmp = sumOfSum[i+1];
            sumOfSum[i+1] = (sumOfSum[i]+pre)%mod;
            pre = tmp;
        }
        stack<int> st;
        st.emplace(-1);
        for(int k = 0; k <= n; ++k){
            while(st.top() != -1 && (k == n || strength[st.top()] >= strength[k])){
                int j = st.top();
                st.pop();
                int i = st.top();
                long long a = sumOfSum[i+1];
                long long b = sumOfSum[j+1];
                long long c = sumOfSum[k+1];
                long long totalSum = ((j-i)*(c-b)-(k-j)*(b-a))%mod;
                res = (res+(strength[j]*totalSum))%mod;
            }
            st.emplace(k);
        }
        return (res+mod)%mod;
    }
};
