class Solution {
public:
    //Time O(N), Space O(N)
    // int minJumps(vector<int>& arr) {
    //     int n = arr.size();
    //     unordered_map<int, unordered_set<int> > hashMap;
    //     queue<int> Q;
    //     for(int i = 1; i < n; ++i){
    //         hashMap[arr[i]].insert(i);
    //     }
    //     Q.emplace(0);
    //     int step = 0;
    //     while(!Q.empty()){
    //         int sizeOfLevel = Q.size();
    //         while(sizeOfLevel--){
    //             int top = Q.front();
    //             Q.pop();
    //             if(top == n-1){
    //                 return step;
    //             }else{
    //                 int left = top-1, right = top+1;
    //                 if(left >= 0 && hashMap[arr[left]].count(left)){
    //                     Q.emplace(left);
    //                     hashMap[arr[left]].erase(left);
    //                 }
    //                 if(right < n && hashMap[arr[right]].count(right)){
    //                     Q.emplace(right);
    //                     hashMap[arr[right]].erase(right);
    //                 }
    //                 for(const auto &x : hashMap[arr[top]]){
    //                     Q.emplace(x);
    //                 }
    //                 hashMap.erase(arr[top]);
    //             }
    //         }
    //         ++step;
    //     }
    //     return step;
    // }
    
    //Time O(N), Space O(N)
    int minJumps(vector<int>& arr){
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        unordered_set<int> setA, setB;
        unordered_map<int, unordered_set<int> > hashMap;
        setA.insert(0);
        setB.insert(n-1);
        vector<bool> visited(n, false);
        visited[0] = true;
        visited[n-1] = true;
        for(int i = 0; i < n; ++i){
            hashMap[arr[i]].insert(i);
        }
        int step = 0;
        while(!setA.empty()){
            if(setA.size() > setB.size()){
                swap(setA, setB);
            }
            unordered_set<int> tmpSet;
            ++step;
            for(const auto &idx : setA){
                int left = idx-1, right = idx+1;
                if(setB.count(left) || setB.count(right)){
                    return step;
                }
                if(left >= 0 && visited[left] == false){
                    tmpSet.insert(left);
                    visited[left] = true;
                }
                if(right < n && visited[right] == false){
                    tmpSet.insert(right);
                    visited[right] = true;
                }
                for(const auto &x : hashMap[arr[idx]]){
                    if(setB.count(x)){
                        return step;
                    }
                    if(visited[x] == false){
                        tmpSet.insert(x); 
                        visited[x] = true;
                    }
                }
                hashMap[arr[idx]].clear();
            }
            setA = tmpSet;
        }
        return step;
    }
};
