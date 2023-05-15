class Solution {
public:
    class UnionFind{
    public:
        vector<int> parent;
        vector<int> rank;
        UnionFind(int n): parent(n), rank(n, 0){
            for(int i = 0; i < parent.size(); ++i){
                parent[i] = i;
            }
        }
        int Find(int x){
            if(parent[x] != x){
                parent[x] = Find(parent[x]);
            }
            return parent[x];
        }
        bool Union(int x, int y){
            int rx = Find(x), ry = Find(y);
            if(rx != ry){
                if(rank[rx] > rank[ry]){
                    parent[ry] = rx;
                }else if(rank[rx] < rank[ry]){
                    parent[rx] = ry;
                }else{
                    parent[ry] = rx;
                    ++rank[rx];
                }
                return true;
            }
            return false;
        }
    };
    // Time O(MlogM+N+Mα(N)), Space O(logM+N).
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        UnionFind uf(n);
        for(size_t i = 0; i < logs.size(); ++i){
            if(uf.Union(logs[i][1], logs[i][2]) && --n == 1){
                return logs[i][0];
            }
        }
        return -1;
    }
};
