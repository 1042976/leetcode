class Solution {
public:
//     map<long long, int> win;
//     map<long long, int>::iterator it;
//     int delta;
//     bool isOdd;
//     void insert(int toAdd){
//         ++win[toAdd];
//         if(toAdd < it->first){
//             if(isOdd){
//                 if(delta == 1){
//                     --it;
//                     delta = it->second;
//                 }else{
//                     --delta;
//                 }
//             }
//         }else{
//             if(!isOdd){
//                 if(delta == it->second){
//                     ++it;
//                     delta = 1;
//                 }else{
//                     ++delta;
//                 }
//             }
//         }
//     }
    
//     void remove(int toRemove){
//         if(!isOdd){
//             if(toRemove >= it->first){
//                 if(delta == 1){
//                     --it;
//                     delta = it->second;
//                 }else{
//                     --delta;
//                 }
//             }            
//         }else{
//             if(toRemove <= it->first){
//                 if(delta == it->second){
//                     ++it;
//                     delta = 1;
//                 }else{
//                     if(toRemove < it->first){
//                         ++delta;
//                     }
//                 }
//             }
//         }
//         if(--win[toRemove] == 0){
//             win.erase(toRemove);
//         }
//     }
//     double getMedian(){
//         if(isOdd || delta < it->second){
//             return it->first;
//         }else{
//             auto nextIt = it;
//             ++nextIt;
//             return (it->first+nextIt->first)/2.0;
//         }
//     }
//     //Time O(nlogk), Space O(k)
//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<double> res;
//         isOdd = k%2;
//         for(int i = 0; i < k; ++i){
//             ++win[nums[i]];
//         }
//         it = win.begin();
//         delta = 1;
//         for(int i = 0; i < (k-1)/2; ++i){
//             if(delta == it->second){
//                 ++it;
//                 delta = 1;
//             }else{
//                 ++delta;
//             }
//         }
//         res.emplace_back(getMedian());
//         for(int i = k; i < n; ++i){
//             insert(nums[i]);
//             remove(nums[i-k]);
//             res.emplace_back(getMedian());
//         }
//         return res;
//     }
    
    //priority queue. T-O(nlogn), Space O(n), n is the size of the nums
//     vector<double> medianSlidingWindow(vector<int>& nums, int k){
//         unordered_map<int, int> hashMap;
//         priority_queue<int> lo;
//         priority_queue<int, vector<int>, std::greater<int> > hi;
//         int n = nums.size();
//         vector<double> medians(n-k+1);
//         for(int i = 0; i < k; ++i){
//             lo.emplace(nums[i]);
//         }
//         for(int i = 0; i < k/2; ++i){
//             hi.emplace(lo.top());
//             lo.pop();
//         }
        
//         for(int i = k; i <= n; ++i){
//             int balance = 0;
//             medians[i-k] = k&1? lo.top() : ((double)lo.top()+(double)hi.top())/2.0;
//             if(i == n){
//                 break;
//             }
//             ++hashMap[nums[i-k]];
//             balance += (nums[i-k] <= lo.top()? -1 : 1); 
//             if(!lo.empty() && nums[i] <= lo.top()){
//                 lo.emplace(nums[i]);
//                 ++balance;
//             }else{
//                 hi.emplace(nums[i]);
//                 --balance;
//             }
//             if(balance < 0){
//                 lo.emplace(hi.top());
//                 hi.pop();
//             }else if(balance > 0){
//                 hi.emplace(lo.top());
//                 lo.pop();
//             }

//             while(hashMap[lo.top()] > 0){
//                 --hashMap[lo.top()];
//                 lo.pop();
//             }
//             while(!hi.empty() && hashMap[hi.top()] > 0){
//                 --hashMap[hi.top()];
//                 hi.pop();
//             } 
//         }
//         return medians;
//     }
    
    double getMedian(const multiset<int>& lo, const multiset<int>& hi){
        return lo.size() > hi.size()? *lo.rbegin() : ((double)*lo.rbegin()+*hi.begin())/2.0;
            
    }
    //Time O(nlogk), Space O(k)
    // vector<double> medianSlidingWindow(vector<int>& nums, int k){
    //     multiset<int> lo, hi;
    //     vector<double> medians;
    //     for(int i = 0; i < k; ++i){
    //         lo.insert(nums[i]);
    //     }
    //     while(lo.size() > hi.size()+1){
    //         hi.insert(*lo.rbegin());
    //         lo.erase(prev(lo.end()));
    //     }
    //     medians.emplace_back(getMedian(lo, hi));
    //     for(int i = k; i < nums.size(); ++i){
    //         nums[i-k] <= *lo.rbegin()? lo.erase(lo.find(nums[i-k])) : hi.erase(hi.find(nums[i-k]));
    //         lo.insert(nums[i]);
    //         hi.insert(*lo.rbegin());
    //         lo.erase(prev(lo.end()));
    //         if(lo.size() < hi.size()){
    //             lo.insert(*hi.begin());
    //             hi.erase(hi.begin());
    //         }
    //         medians.emplace_back(getMedian(lo, hi));
    //     }
    //     return medians;
    // }
    
    double getMedian(multiset<int>::iterator& it, int& k) const{
        return ((double)*it + *(next(it, 1-k&1)))/2.0;
    }
    //Time O(nlogk), Space O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k){
        vector<double> medians;
        multiset<int> window;
        for(int i = 0; i < k; ++i){
            window.insert(nums[i]);
        }
        auto it = next(window.begin(), (k-1)/2);
        medians.emplace_back(getMedian(it, k));
        for(int i = k; i < nums.size(); ++i){
            window.insert(nums[i]);
            if(nums[i] < *it){
                --it;
            }
            if(nums[i-k] <= *it){
                ++it;
            }
            window.erase(window.lower_bound(nums[i-k]));
            medians.emplace_back(getMedian(it, k));
        }
        return medians;
    }
};
