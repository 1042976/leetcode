class Solution {
public:
    bool check(vector<int> &ribbons, int l, int r, int divided, int k){
        int count = 0;
        while(l <= r){
            count += ribbons[l]/divided;
            if(count >= k){
                return true;
            }
            ++l;
        }
        return false;
    }
    //Time O(nlogm), Space O(1)
    int maxLength(vector<int>& ribbons, int k) {
        int r = ribbons.size();
        int largestCandidate = accumulate(ribbons.begin(), ribbons.end(), 0l)/k;
        if(largestCandidate == 0){
            return 0;
        }
        int smallestCandidate = 1;
        int maxLen = 1;
        while(smallestCandidate <= largestCandidate){
            int candidate = smallestCandidate+((largestCandidate-smallestCandidate)>>1);
            bool isValid = check(ribbons, 0, r-1, candidate, k);
            if(isValid){
                maxLen = max(maxLen, candidate);
                smallestCandidate = candidate+1;
            }else{
                largestCandidate = candidate-1;
            }
        }
        return maxLen;
    }
};
