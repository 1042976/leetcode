class Solution {
public:
    //Time O(N), Space O(1)
    int largestVariance(string s) {
        int largest = 0;
        unordered_set<char> hashSet;
        for(const auto &c : s){
            hashSet.insert(c);
        }
        for(const auto &a : hashSet){
            for(const auto &b : hashSet){
                if(b == a){
                    continue;
                }
                bool hasA = false, aIsFirst = false;
                int var = 0;
                for(const auto &c : s){
                    if(c == b){
                        ++var;
                    }else if(c == a){
                        hasA = true;
                        if(aIsFirst && var != -1){
                            aIsFirst = false;
                        }else if(!aIsFirst && --var == -1){
                            aIsFirst = true;
                        }
                    }
                    if(hasA){
                        largest = max(largest, var);
                    }
                }
            }
        }
        return largest;
    }
};
