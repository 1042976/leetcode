class Solution {
public:
    class DSU{
    private:
        vector<int> parent, rank;
    public:
        DSU(int size): parent(size), rank(size, 0){
            for(int i = 0; i < size; ++i){
                parent[i] = i;
            }
        }
        int find(int i){
            if(parent[i] != i){
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }
        void Union(int i, int j){
            int x = find(i), y = find(j);
            if(x != y){
                if(rank[x] < rank[y]){
                    swap(x, y);
                }
                parent[y] = x;
                rank[x] += rank[y];
            }
        }
    };
    //Time O(M+Nsqrt(M)log*M), Space O(M)
    // int largestComponentSize(vector<int>& nums) {
    //     int maxVal = *max_element(begin(nums), end(nums));
    //     DSU dsu(maxVal+1);
    //     for(const auto &val : nums){
    //         for(int i = 2; i*i <= val; ++i){
    //             if(val % i == 0){
    //                 dsu.Union(val, i);
    //                 dsu.Union(val, val/i);
    //             }
    //         }
    //     }
    //     int count[maxVal+1];
    //     memset(count, 0, sizeof(count));
    //     for(const auto &x: nums){
    //         int leader = dsu.find(x);
    //         ++count[leader];
    //     }
    //     int maxCount = 0;
    //     for(int i = 0; i <= maxVal; ++i){
    //         maxCount = max(maxCount, count[i]);
    //     }
    //     return maxCount;
    // }
    
    //Time O(M + Nlog_2(M)*log*M) Space O(M)
    int largestComponentSize(vector<int>& nums){
        int maxVal = *max_element(begin(nums), end(nums));
        DSU dsu(maxVal+1);
        for(const auto &x : nums){
            int val = x, i = 2;
            while(i*i <= val){
                if(val%i == 0){
                    dsu.Union(i, x);
                    val /= i;
                    break;
                }else{
                    ++i;
                }
            }
            int j = i;
            while(i*i <= val){
                if(val%i == 0){
                    dsu.Union(j, i);
                    val /= i;
                    j = i;
                }else{
                    ++i;
                }
            }
            dsu.Union(x, val);              
        }
        int count[maxVal+1];
        memset(count, 0, sizeof(count));
        for(const auto &x : nums){
            int leader = dsu.find(x);
            ++count[leader];
        }
        int maxCount = 0;
        for(int i = 0; i <= maxVal; ++i){
            maxCount = max(maxCount, count[i]);
        }
        return maxCount;
    }
};
