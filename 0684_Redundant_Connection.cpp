class Solution {
public:
    class DSU{
    private:
        vector<int> parent, rank;
    public:
        DSU(int n): parent(n), rank(n, 0){
            for(int i = 0; i < n; ++i){
                parent[i] = i;
            }
        }
        int find(int i){
            if(parent[i] != i){
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }
        int unite(int i, int j){
            int x = find(i), y = find(j);
            if(x == y){
                return false;
            }else{
                if(rank[x] < rank[y]){
                    parent[x] = y;
                }else if(rank[x] > rank[y]){
                    parent[y] = x;
                }else{
                    parent[y] = x;
                    ++rank[x];
                }
                return true;
            }
        }
    };
    //Time O(N*a(N)), Space(N)
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(const auto &edge : edges){
            if(!dsu.unite(edge[0]-1, edge[1]-1)){
                return edge;
            }
        }
        return vector<int>();
    }
};
