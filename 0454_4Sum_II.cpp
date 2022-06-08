class Solution {
public:
    //Time O(n^2), Space O(n^2)
    // int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    //     int res = 0;
    //     unordered_map<int, int> hashMap;
    //     for(const auto &n1 : nums1){
    //         for(const auto &n2 : nums2){
    //             ++hashMap[n1+n2];
    //         }
    //     }
    //     for(const auto &n3 : nums3){
    //         for(const auto &n4 : nums4){
    //             int a = -(n3+n4);
    //             if(hashMap.find(a) != hashMap.end()){
    //                 res += hashMap[a];
    //             }
    //         }
    //     }
    //     return res;
    // }
    unordered_map<int, int> hashMap;
    int res = 0;
    void build(vector<vector<int> >& numsList, int l,  int r, int sum){
        if(l > r){
            ++hashMap[sum];
            return;
        }
        for(const auto &x : numsList[l]){
            build(numsList, l+1, r, sum+x);
        }
    }
    void count(vector<vector<int> >& numsList, int l, int r, int sum){
        if(l > r){
            if(hashMap.find(-sum) != hashMap.end()){
                res += hashMap[-sum];
            }
            return;
        }
        for(const auto &x : numsList[l]){
            count(numsList, l+1, r, sum+x);
        }
    }
    int kSumCount(vector<vector<int> >& numsList){
        int size = numsList.size();
        int m = (size+1)/2;
        build(numsList, 0, m-1, 0);
        count(numsList, m, size-1, 0);
        return res;
    }
    
    //Time O(n^2), Space O(n^2)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
        vector<vector<int> > numsList{nums1, nums2, nums3,nums4};
        return kSumCount(numsList);
        
    }
};
