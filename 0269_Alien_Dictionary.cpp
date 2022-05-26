class Solution {
public:
    //Time O(N), Space O(1)
    // string alienOrder(vector<string>& words) {
    //     unordered_set<char> hashSet;
    //     for(const auto &word : words){
    //         for(const auto &c : word){
    //             hashSet.insert(c);
    //         }
    //     }
    //     if(words.size() == 1){
    //         return string(hashSet.begin(), hashSet.end());
    //     }
    //     unordered_map<char, list<char>::iterator >  hashMapA;
    //     unordered_map<char, char> hashMapB;
    //     list<char> letters;
    //     for(int i = 0; i < words.size()-1; ++i){          
    //         for(int k = 0; k < words[i].length(); ++k){
    //             if(k == words[i+1].length()){
    //                 return "";
    //             }
    //             char c1 = words[i][k];
    //             char c2 = words[i+1][k];
    //             if(c1 != c2){
    //                 int n1 = hashMapA.count(c1);
    //                 int n2 = hashMapA.count(c2);
    //                 if(n1 == 0 && n2 == 0){
    //                     letters.emplace_front(c2);
    //                     letters.emplace_front(c1);
    //                     auto it = letters.begin();
    //                     hashMapA[c1] = it;
    //                     hashMapA[c2] = ++it;
    //                     hashMapB[c1] = c1;
    //                     hashMapB[c2] = c1;
    //                 }else if(n1 == 1 && n2 == 0){
    //                     auto it = hashMapA[c1];
    //                     it = letters.insert(++it, c2);
    //                     hashMapA[c2] = it;
    //                     hashMapB[c2] = hashMapB[c1];
    //                 }else if(n1 == 0 && n2 == 1){
    //                     auto it = hashMapA[c2];
    //                     it = letters.insert(it, c1);
    //                     hashMapA[c1] = it;
    //                     hashMapB[c2] = hashMapB[c2];
    //                 }else{
    //                     auto it = hashMapA[c1];
    //                     while(it != letters.end() && it != hashMapA[c2]){
    //                         ++it;
    //                     }
    //                     if(it !=letters.end()){
    //                         break;
    //                     }                          
    //                     if(hashMapB[c1] == hashMapB[c2]){
    //                         return "";                            
    //                     }else{
    //                         auto it1 = hashMapA[c1];
    //                         auto it2 = hashMapA[c2];
    //                         char c = hashMapB[c2];
    //                         auto it3 = it2;
    //                         while(hashMapB[*it3] == c){
    //                             hashMapB[*it3] = hashMapB[c1];
    //                             ++it3;
    //                         }
    //                         letters.splice(++it1, letters, it2, it3);
    //                     }                    
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    //     unordered_map<char, int> hashMapC;
    //     int priority = 0;
    //     for(auto &letter : letters){
    //         hashMapC[letter] = priority++;
    //     }
    //     for(int i = 0; i < words.size()-1; ++i){          
    //         for(int k = 0; k < words[i].length(); ++k){
    //             char c1 = words[i][k];
    //             char c2 = words[i+1][k];
    //             if(c1 != c2){
    //                 if(hashMapC[c1] > hashMapC[c2]){
    //                     return "";
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    //     string res(letters.begin(), letters.end());
    //     for(const auto &c : res){
    //         hashSet.erase(c);
    //     }
    //     for(const auto &c : hashSet){
    //         res.push_back(c);
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(1)
    string alienOrder(vector<string>& words){
        //build graph
        unordered_map<char, unordered_set<char> > childList;
        unordered_map<char, int> parentNum;
        for(const auto &word: words){
            for(const auto &c : word){
                if(childList.find(c) == childList.end()){
                    childList[c] = unordered_set<char>();
                    parentNum[c] = 0;                    
                }
            }
        }
        
        for(int i = 0; i < words.size()-1; ++i){
            for(int k = 0; k < words[i].length(); ++k){
                if(k == words[i+1].length()){
                    return "";
                }
                char c1 = words[i][k], c2 = words[i+1][k];
                if(c1 != c2){
                    if(childList[c1].find(c2) == childList[c1].end()){
                        childList[c1].insert(c2);
                        ++parentNum[c2];
                    }
                    break;
                }
            }
        }
        
        //bfs
        queue<char> Q;
        auto it = parentNum.begin();
        while(it != parentNum.end()){
            if(it->second == 0){
                Q.emplace(it->first);
            }
            ++it;
        }
        
        string res = "";
        while(!Q.empty()){
            char c = Q.front();
            Q.pop();
            res.push_back(c);
            for(const auto &child : childList[c]){
                if(--parentNum[child] == 0){
                    Q.emplace(child);
                }
            }
        }
        
        return res.length() == childList.size()? res : "";
    }
};
