class Solution {
public:
    //T-O(a+b+c), S-O(1)
    string longestDiverseString(int a, int b, int c) {
        auto compare = [](const pair<int, char> &a, const pair<int, char> &b)->bool{
          return a.first < b.first;  
        };
        priority_queue<pair<int, char>, vector<pair<int, char> >, decltype(compare)> maxHeap(compare);
        if(a != 0){
            maxHeap.emplace(make_pair(a, 'a'));
        }
        if(b != 0){
            maxHeap.emplace(make_pair(b, 'b'));
        }
        if(c != 0){
            maxHeap.emplace(make_pair(c, 'c'));
        }
        string res = "";
        int r = -1;
        while(!maxHeap.empty()){
            auto p = maxHeap.top();
            maxHeap.pop();
            if(r >= 1 && res[r] == p.second && res[r-1] == p.second){
                if(maxHeap.empty()){
                    return res;
                }else{
                    auto p1 = maxHeap.top();
                    maxHeap.pop();
                    res.push_back(p1.second);
                    if(--p1.first != 0){
                        maxHeap.emplace(p1);
                    }
                    maxHeap.emplace(p);
                }
            }else{
                res.push_back(p.second);
                if(--p.first != 0){
                    maxHeap.emplace(p);
                }
            }
            ++r;
        }
        return res;
    }
};
