class Solution {
public:
    // unordered_map<string, unordered_map<string, double> > graph;
    // unordered_set<string> visited;
    // void backtrack(const string& a, const string& b, double val, vector<double>& res, int& idx){
    //     if(a == b){
    //         res[idx] = val;
    //         return;
    //     }
    //     visited.insert(a);
    //     for(const auto &node : graph[a]){
    //         if(visited.count(node.first) == 0){
    //             backtrack(node.first, b, val*node.second, res, idx);
    //         }
    //     }
    //     visited.erase(a);
    // }
    // //graph+backtrack. Time O(MN), Space O(M), M is the size of array equations otr values while N is the size of queries.
    // vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    //     for(int i = 0; i < equations.size(); ++i){
    //         vector<string>& x = equations[i];
    //         graph[x[0]][x[1]] = values[i];
    //         graph[x[1]][x[0]] = 1.0/values[i];    
    //     }
    //     vector<double> res(queries.size(), -1.0);
    //     int val = 1;
    //     for(int i = 0; i < queries.size(); ++i){
    //         if(graph.count(queries[i][0]) && graph.count(queries[i][1])){
    //             backtrack(queries[i][0], queries[i][1], val, res, i);
    //         }
    //     }
    //     return res;
    // }
    
    class DSU{
    public:
        unordered_map<string, pair<string, double> > weights;
        pair<string, double>& find(const string& a){
            if(weights.count(a) == 0){
                weights[a] = make_pair(a, 1.0);
                return weights[a];
            }
            pair<string, double>& next = weights[a];
            if(next.first != a){
                auto &root = find(next.first);
                next.first = root.first;
                next.second *= root.second;
            }
            return next;
        }
        void Union(const string& a, const string& b, double val){
            auto& [rootA, wA] = find(a);
            auto& [rootB, wB] = find(b);
            if(rootA != rootB){
                weights[rootA] = make_pair(rootB, wB/wA * val);
            }
        }
        double query(const string& a, const string& b){
            if(weights.count(a) == 0 || weights.count(b) == 0){
                return -1;
            }
            auto& [rootA, wA] = find(a);
            auto& [rootB, wB] = find(b);
            return rootA == rootB? wA/wB : -1.0;
        }
    };
    //Time O((M+N)log*N), Space O(M)
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        DSU dsu;
        for(int i = 0; i < equations.size(); ++i){
            vector<string>& x = equations[i];
            dsu.Union(x[0], x[1], values[i]);
        }
        vector<double> res;
        for(const auto& q : queries){
            res.emplace_back(dsu.query(q[0], q[1]));
        }
        return res;
    }
};
