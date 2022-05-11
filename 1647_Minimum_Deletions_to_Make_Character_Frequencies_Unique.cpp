class Solution {
public:
    //Time O(n), Space O(1)
    int minDeletions(string s) {
        vector<int> arr(26, 0);
        for(const auto &c : s){
            ++arr[c-'a'];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int res = 0, maxFrequencyAllowed = s.length();
        for(const auto &x : arr){
            if(x == 0){
                continue;
            }
            if(x > maxFrequencyAllowed){
                res += (x-maxFrequencyAllowed);
                if(maxFrequencyAllowed > 0){
                    --maxFrequencyAllowed;
                }
            }else{
                maxFrequencyAllowed = x-1;
            }
        }
        return res;
    }
};
