class Solution {
public:
    int n;
    vector<int> memo;
    int dfs(vector<int>& arr, int i, int d){
        if(memo[i] < 0){
            memo[i] = 0;
            int maxNum = 1;
            for(int j = i-1; j >= max(i-d, 0); --j){
                if(arr[j] < arr[i]){
                    maxNum = max(maxNum, 1+dfs(arr, j, d));
                }else{
                    break;
                }
            }
            for(int j = i+1; j <= min(i+d, n-1); ++j){
                if(arr[j] < arr[i]){
                    maxNum = max(maxNum, 1+dfs(arr, j, d));
                }else{
                    break;
                }
            }
            memo[i] = maxNum;
        }
        return memo[i];
    }
    //Time O(N*d), Space O(N)
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memo.resize(n, -1);
        for(int i = 0; i < n; ++i){
           dfs(arr, i, d); 
        }
        return *max_element(begin(memo), end(memo));
    }
};
