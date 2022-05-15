class Solution {
public:
    int partition(vector<pair<int, int> > &fre, int l, int r){
        int idx = l+rand()%(r-l+1);
        swap(fre[idx], fre[r]);
        int i = l;
        for(int j = l; j < r; ++j){
            if(fre[j].second > fre[r].second){
                swap(fre[i++], fre[j]);
            }
        }
        swap(fre[i], fre[r]);
        return i;
    }
    void quickSelect(vector<pair<int,int> > &fre, int l, int r, int k){
        while(l < r){
            int pos = partition(fre, l , r);
            if(pos == k-1 || pos == k){
                return;
            }else if(pos > k){
                r = pos-1;
            }else{
                l = pos+1;
            }
        }
    }
    
    //Time avg-O(n) worst O(n^2), Space O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        srand(time(NULL));
        vector<pair<int, int> > fre;
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); ++i){
            ++hashMap[nums[i]];
        }
        for(const auto &[u, f] : hashMap){
            fre.emplace_back(make_pair(u, f));
        }
        quickSelect(fre, 0, fre.size()-1, k);
        vector<int> res;
        for(int i = 0; i < k; ++i){
            res.emplace_back(fre[i].first);
        }
        return res;
    }
    //Time O(nlogk) Space O(n)
    // vector<int> topKFrequent(vector<int>& nums, int k){
    //     unordered_map<int, int> hashMap;
    //     for(const auto &x : nums){
    //         ++hashMap[x];
    //     }
    //     auto compare = [](const pair<int, int> &a, const pair<int, int> &b)->bool{
    //       return a.second > b.second;  
    //     };
    //     priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(compare)> minHeap(compare);
    //     for(const auto &[u, f] : hashMap){
    //         if(minHeap.size() < k){
    //             minHeap.emplace(make_pair(u,f));
    //         }else{
    //             if(minHeap.top().second < f){
    //                 minHeap.pop();
    //                 minHeap.emplace(make_pair(u, f));
    //             }
    //         }
    //     }
    //     vector<int> res;
    //     while(!minHeap.empty()){
    //         res.emplace_back(minHeap.top().first);
    //         minHeap.pop();
    //     }
    //     return res;
    // }
};
