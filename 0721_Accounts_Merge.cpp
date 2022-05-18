class Solution {
public:
    class DSU{
      public:
        vector<int> roots;
        DSU(int size):roots(size){
            for(int i = 0; i < size; ++i){
                roots[i] = i;         
            }
        }
        int find(int i){
            if(roots[i] == i){
                return i;
            }
            roots[i] = find(roots[i]);
            return roots[i]; 
        }
        
        void unionGraph(int nodeA, int nodeB){
            int rootA = find(nodeA);
            int rootB = find(nodeB);
            roots[rootB] = rootA;
        }
        
        
    };
    //Time O(NMlog(NM)), Space O(NM)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        unordered_map<string, int> hashMap;
        for(int i = 0; i < accounts.size(); ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                string email = accounts[i][j];
                if(hashMap.count(email)==0){
                    hashMap[email] = i;
                }else{
                    int root = dsu.find(hashMap[email]);
                    dsu.unionGraph(root, i);
                }
            }
        }
        vector<vector<string> > res;
        unordered_map<int, int> idxMap;
        for(auto &[email, i] : hashMap){
            int root = dsu.find(i);
            if(idxMap.count(root) == 0){
                res.emplace_back(vector<string>{accounts[root][0]});
                idxMap[root] = res.size()-1;
            }
            res[idxMap[root]].emplace_back(email);
        }
        for(auto &account : res){
            sort(account.begin()+1, account.end());
        }
        return res;  
    }
    // unordered_map<string, vector<string> >  hashMap;
    // unordered_set<string> visited;
    // void dfs(vector<string> &mergedAccount, string email){
    //     mergedAccount.emplace_back(email);
    //     visited.insert(email);
    //     for(const auto &other : hashMap[email]){
    //         if(visited.count(other) == 0){
    //             dfs(mergedAccount, other);
    //         }
    //     }
    // }
    // //Time O(NMlogNM), Space O(NM)
    // vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    //     for(const auto &account : accounts){
    //         string firstEmail = account[1];
    //         for(int i = 2; i < account.size(); ++i){
    //             hashMap[firstEmail].emplace_back(account[i]);
    //             hashMap[account[i]].emplace_back(firstEmail);
    //         }
    //     }
    //     vector<vector<string> > res;
    //     for(const auto &account : accounts){
    //         vector<string> mergedAccount{account[0]};
    //         if(visited.count(account[1]) == 0){
    //             dfs(mergedAccount, account[1]);
    //             sort(mergedAccount.begin()+1, mergedAccount.end());
    //             res.emplace_back(mergedAccount);
    //         }
    //     }
    //     return res;
    // }
};
