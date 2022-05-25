class Solution {
public:
    // bool isTransformation(string &str1, string &str2){
    //     for(int i = 0; i < str1.length(); ++i){
    //         if(str1[i] != str2[i]){
    //             for(int j = i+1; j < str1.length(); ++j){
    //                 if(str1[j] != str2[j]){
    //                     return false;
    //                 }
    //             }
    //         }
    //     }
    //     return true;
    // }
    // //Time O(m^2*n), Space O(m) 
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     queue<int> Q1, Q2;
    //     int idxOfEndWord = -1;
    //     for(int i = 0; i < wordList.size(); ++i){
    //         if(wordList[i] == beginWord){
    //             continue;
    //         }else if(wordList[i] == endWord){
    //             idxOfEndWord = i;
    //         }
    //         isTransformation(beginWord,wordList[i])? Q2.emplace(i) : Q1.emplace(i);
    //     }
    //     if(idxOfEndWord == -1){
    //         return 0;
    //     }
    //     int lenOfPath = 1;
    //     while(!Q2.empty()){
    //         ++lenOfPath;
    //         int size2 = Q2.size();
    //         while(size2--){
    //             int i2 = Q2.front();
    //             if(i2 == idxOfEndWord){
    //                 return lenOfPath;
    //             }
    //             Q2.pop();
    //             int size1 = Q1.size();
    //             while(size1--){
    //                 int i1 = Q1.front();
    //                 Q1.pop();
    //                 isTransformation(wordList[i2], wordList[i1])? Q2.emplace(i1) : Q1.emplace(i1);  
    //             }
    //         }
    //     }
    //     return 0;
    // }
    
    //Time O(m^2*n), Space O(mn)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> hashSet;
        bool hasEndWord = false;
        for(const auto &str : wordList){
            if(str == beginWord){
                continue;
            }else{
                if(str == endWord){
                    hasEndWord = true;
                }
                hashSet.insert(str);
            }
        }
        if(!hasEndWord){
            return 0;
        }
        unordered_set<string> hashSetB, hashSetE;
        hashSetB.insert(beginWord);
        hashSetE.insert(endWord);
        int lenB = 1, lenE = 1;
        while(!hashSetB.empty()){
            if(hashSetB.size() > hashSetE.size()){
                swap(hashSetB, hashSetE);
                swap(lenB, lenE);
                swap(beginWord, endWord);
            }
            unordered_set<string> newHashSet;
            for(auto &cur : hashSetB){
                if(cur == endWord){
                    return lenB;
                }
                for(int i = 0; i < cur.length(); ++i){
                    string tmp = cur;
                    for(char c = 'a'; c <= 'z'; ++c){
                        tmp[i] = c;
                        if(hashSetE.find(tmp) != hashSetE.end()){
                            return lenB + lenE;
                        }else if(hashSet.find(tmp) != hashSet.end()){
                            newHashSet.insert(tmp);
                            hashSet.erase(tmp);
                        }
                    }
                }        
            }
            hashSetB = newHashSet;
            ++lenB;
        }
        return 0;
    }
};
