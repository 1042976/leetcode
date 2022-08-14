class Solution {
public:
    //int minNum = 16;
    int m;
    unordered_map<string, int> memo;
    vector<string> A;
    const int bound = 16;
    int getOverlap(string& A, string& B){
        int res = 0;
        for(int i = 0; i < 26; ++i){
            if(A[i] > '0'){
                int b = B[i]-'0', a = A[i]-'0';
                res = max(res, (int)ceil(b/(a*1.0)));
            }
        }
        return res;
    }
    void minus(string& B, string& A){
        for(int i = 0; i < 26; ++i){
            int dif = B[i]-'0'-(A[i]-'0');
            B[i] = dif > 0? dif+'0' : '0';
        }
    }
    int dp(string& B){
        if(memo.count(B)){
            return memo[B];
        }
        int minState = bound;
        int tarIdx = 0;
        for(tarIdx = 0; tarIdx < 26; ++tarIdx){
            if(B[tarIdx] > '0'){
                break;
            }
        }
        for(int i = 0; i < m; ++i){
            if(A[i][tarIdx] > '0'){
                string tmp = B;
                minus(tmp, A[i]);
                int state = dp(tmp)+1;
                minState = min(minState, state);
            }
        }
        memo[B] = minState;
        return memo[B];
    }
    //Time O(MN), Space O(M+N), M is the size of stickers while N is the length of target.
    int minStickers(vector<string>& stickers, string target) {
        m = stickers.size();
        A.resize(m, string(26, '0'));
        string B(26, '0');
        memo[B] = 0;
        for(int i = 0; i < m; ++i){
            for(const auto &c : stickers[i]){
                ++A[i][c-'a'];
            }
        }
        for(const auto &c : target){
            ++B[c-'a'];
        }
        int res = dp(B);
        return res == bound? -1 : res;
    }
};
