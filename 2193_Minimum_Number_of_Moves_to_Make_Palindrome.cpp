class Solution {
public:
    //Time O(N^2), Space O(1)
    // int minMovesToMakePalindrome(string s) {
    //     int res = 0;
    //     int left = 0, right = s.length()-1;
    //     for(int i = s.length()-1; i >= 0; --i){
    //             int k = s.find(s[right], left+1);
    //             int move = k-left;
    //             if(k < right){
    //                 s.erase(k, 1);
    //                 res += move;
    //             }else{
    //                 res += move>>1;
    //             }
    //         s.pop_back();
    //         right = s.length()-1;
    //     }
    //     return res;
    // }
    
    //Time O(N^2), Space O(N)
    // int minMovesToMakePalindrome(string s) {
    //     int res = 0;
    //     list<char> arr(s.begin(), s.end());
    //     auto left = arr.begin();
    //     auto right = --arr.end();
    //     while(arr.size() > 1){
    //         if(*left != *right){
    //             auto it = left;
    //             int move = 0;
    //             while(*it != *right){
    //                 ++it;
    //                 ++move;
    //             }
    //             if(it != right){
    //                 arr.erase(it);
    //                 res += move;
    //             }else{
    //                 res += move>>1;
    //             }
    //         }else{
    //             ++left;
    //             arr.pop_front();
    //         }
    //         --right;
    //         arr.pop_back();
    //     }
    //     return res;
    // }

//     class SegmentTree{
//     private:
//         int n;
//         vector<int> arr;
//     public:
//         SegmentTree(int _n) : n(_n), arr(2*n){
//             arr[0] = 0;
//             for(int i = n; i < 2*n; ++i){
//                 arr[i] = 1;
//             }
//             for(int i = n-1; i > 0; --i){
//                 arr[i] = arr[2*i]+arr[2*i+1];
//             }
//         }
        
//         void addValue(int idx, int val){
//             idx += n;
//             arr[idx] += val;
//             while(idx > 0){
//                 if(idx%2){
//                     arr[idx/2] = arr[idx-1] + arr[idx];
//                 }else{
//                     arr[idx/2] = arr[idx] + arr[idx+1];
//                 }
//                 idx >>= 1;
//             }
//         }
        
//         int getSum(int left, int right){
//             int sum = 0;
//             left += n;
//             right += n;
//             while(left <= right){
//                 if(left%2){
//                     sum += arr[left++];
//                 }
//                 if(right%2 == 0){
//                     sum += arr[right--];
//                 }
//                 left >>= 1;
//                 right >>= 1;
//             }
//             return sum;
//         }    
//     };
    
    //Time O(NlogN), Space O(N)
    // int minMovesToMakePalindrome(string s){
    //     int res = 0, len = s.length();
    //     deque<int> arr[26];
    //     for(int i = 0; i < len; ++i){
    //         arr[s[i]-'a'].emplace_back(i);
    //     }
    //     SegmentTree tree(len);
    //     for(int right = len-1; right >= 0; --right){
    //         if(s[right] != '0'){
    //             int charIdx = s[right]-'a';
    //             int i = arr[charIdx].front();
    //             tree.addValue(i, -1);
    //             int move = tree.getSum(0, i);
    //             if(i < right){
    //                 arr[charIdx].pop_front();
    //                 s[i] = '0';
    //                 res += move;
    //             }else{
    //                 res += move>>1;
    //             }                
    //         }
    //     }
    //     return res;
    // }
    
    class BIT{
    private:
        vector<int> arr;
        int getNext(int idx){
            return idx + (idx & (-idx));
        }
        int getParent(int idx){
            return idx & (idx-1);
        }
    public:
        BIT(int _n):arr(_n+1){
            arr[0] = 0;
            for(int i = 0; i < _n; ++i){
                addValue(i, 1);
            }
        }
        void addValue(int idx, int val){
            ++idx;
            while(idx < arr.size()){
                arr[idx] += val;
                idx = getNext(idx);
            }
        }
        int getSum(int idx){
            int sum = 0;
            ++idx;
            while(idx > 0){
                sum += arr[idx];
                idx = getParent(idx);
            }
            return sum;
        }
    };
    //Time O(NlogN), Space O(N)
    int minMovesToMakePalindrome(string s){
        int res = 0, len = s.length();
        deque<int> arr[26];
        for(int i = 0; i < len; ++i){
            arr[s[i]-'a'].emplace_back(i);
        }
        BIT tree(len);
        for(int right = len-1; right >= 0; --right){
            if(s[right] != '0'){
                int charIdx = s[right]-'a';
                int i = arr[charIdx].front();
                tree.addValue(i, -1);
                int move = tree.getSum(i);
                if(i < right){
                    arr[charIdx].pop_front();
                    s[i] = '0';
                    res += move;
                }else{
                    res += move>>1;
                }                
            }
        }
        return res;
    }
};
