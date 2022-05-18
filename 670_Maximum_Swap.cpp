class Solution {
public:
    int getNum(vector<int> &arr){
        int num = 0;
        for(int i = arr.size()-1; i >= 0; --i){
            num = num*10+arr[i];
        }
        return num;
    }
    //Time O(n), Space O(n)
    int maximumSwap(int num) {
        vector<int> arr;
        int tmp = num;
        while(tmp != 0){
            arr.emplace_back(tmp%10);
            tmp /= 10;
        }
        vector<int> dp(arr.size());
        dp[0] = 0;
        for(int i = 1; i < arr.size(); ++i){
            dp[i] = arr[dp[i-1]] >= arr[i]? dp[i-1] : i;
        }
        for(int i = arr.size()-1; i >= 0; --i){
            if(dp[i] != i && arr[dp[i]] != arr[i]){
                swap(arr[dp[i]], arr[i]);
                return getNum(arr);
            }
        }
        return num;
    }
    
    //Time O(n), Space O(n)
    // int maximumSwap(int num){
    //     vector<int> lastOccurence(10, INT_MIN);
    //     string digits = to_string(num);
    //     for(int i = 0; i < digits.length(); ++i){
    //         lastOccurence[digits[i]-'0'] = i;
    //     }
    //     for(int i = 0; i < digits.length(); ++i){
    //         for(int j = 9; j > digits[i]-'0'; --j){
    //             if(lastOccurence[j] > i){
    //                 swap(digits[i], digits[lastOccurence[j]]);
    //                 return stoi(digits);
    //             }
    //         }
    //     }
    //     return num;
    // }
};
