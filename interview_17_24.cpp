class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if(M == 0){
            return vector<int>();
        }
        int N = matrix[0].size();
        vector<int> b(N, 0);
        vector<int> res(4, 0);
        int maxSum = INT_MIN;
        for(int i = 0; i < M; ++i){
            for(int k = 0; k < N; ++k){
                b[k] = 0;
            }
            for(int j = i; j < M; ++j){
                int start_i = res[0], start_j = res[1];
                int sum = 0; 
                for(int k = 0; k < N; ++k){
                    b[k] += matrix[j][k];
                    if(sum > 0){
                        sum += b[k];
                    }else{
                        sum = b[k];
                        start_i = i;
                        start_j = k;
                    }
                    if(sum > maxSum){
                        maxSum = sum;
                        res[0] = start_i;
                        res[1] = start_j;
                        res[2] = j;
                        res[3] = k;
                    }
                }
            }
        }
        return res;
    }
};
