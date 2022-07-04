class Solution {
public:
    vector<vector<int> > res;
    int getIdx(int val){
        if(res.empty() || res.back()[0] != val){
            res.emplace_back(vector<int>{val, 0});
        }
        return res.size()-1;
    }
    //Time O(M+N), Space O(1)
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i = 0, j = 0;
        while(i < encoded1.size()){
            int val = encoded1[i][0]*encoded2[j][0];
            int k = getIdx(val);
            int fre1 = encoded1[i][1], fre2 = encoded2[j][1];
            if(fre1 == fre2){ 
                res[k][1] += fre1;
                ++i;
                ++j;
            }else if(fre1 < fre2){
                res[k][1] += fre1;
                encoded2[j][1] -= fre1;
                ++i;
            }else{
                res[k][1] += fre2;
                encoded1[i][1] -= fre2;
                ++j;
            }
        }
        return res;
    }
};
