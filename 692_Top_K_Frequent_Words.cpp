class Solution {
public:
    //T-O(N*logK), S-O(N)
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashMap;
        auto compare = [&](const string &a, const string &b)->bool{
            return hashMap[a] > hashMap[b] || (hashMap[a] == hashMap[b] && a < b);
        };
        priority_queue<string, vector<string>, decltype(compare)> Q(compare);
        for(const auto &word : words){
            ++hashMap[word];
        }
        unordered_map<string, int>::iterator it =  hashMap.begin();
        while(it != hashMap.end()){
            Q.push(it->first);
            if(Q.size() > k){
                Q.pop();
            }
            ++it;
        }
        vector<string> res;
        while(!Q.empty()){
            res.emplace_back(Q.top());
            Q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
