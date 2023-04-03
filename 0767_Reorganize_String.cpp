class Solution {
public:
    //Time O(N), Space O(1)
    // string reorganizeString(string s) {
    //     string res(s.length(), ' ');
    //     priority_queue<pair<int, char>, vector<pair<int, char> >, less<pair<int, char> > > maxHeap;
    //     int arr[26];
    //     memset(arr, 0, sizeof(arr));
    //     for(const auto &c : s){
    //         ++arr[c-'a'];
    //     }
    //     for(int i = 0; i < 26; ++i){
    //         if(arr[i] > 0){
    //             maxHeap.emplace(make_pair(arr[i], 'a'+i));
    //         }
    //     }
    //     int i = 0;
    //     while(maxHeap.size() > 1){
    //         auto [n1, c1] = maxHeap.top();
    //         maxHeap.pop();
    //         auto [n2, c2] = maxHeap.top();
    //         maxHeap.pop();
    //         res[i++] = c1;
    //         res[i++] = c2;
    //         if(--n1 > 0){
    //             maxHeap.emplace(make_pair(n1, c1)); 
    //         }
    //         if(--n2 > 0){
    //             maxHeap.emplace(make_pair(n2, c2));
    //         }
    //     }
    //     if(maxHeap.size() == 1){
    //         auto [n, c] = maxHeap.top();
    //         if(n > 1){
    //             return "";
    //         }else{
    //             res[i] = c;
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(1)
    string reorganizeString(string s){
        int len = s.length();
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for(const auto &x : s){
            ++arr[x-'a'];
        }
        int j = 0;
        for(int i = 1; i < 26; ++i){
            if(arr[i] > arr[j]){
                j = i;
            }
        }
        if(arr[j] > ceil(len/2.0)){
            return "";
        }
        string res(len,'a');
        int i = 0;
        char curChar = 'a'+j;
        while(arr[j] > 0){
            res[i] = curChar;
            --arr[j];
            i += 2;
        }
        for(j = 0; j < 26; ++j){
            curChar = j+'a';
            while(arr[j] > 0){
                if(i >= len){
                    i = 1;
                }
                res[i] = curChar;
                i += 2;
                --arr[j];
            }
        }
        return res;
    }
};
