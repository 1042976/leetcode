class Solution {
public:
    //Time O(nloglogn), Space O(n)
    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }
        int numOfComposites = 0;
        vector<bool> arr(n, true);
        int sqrtN = sqrt(n);
        for(int prime = 2; prime <= sqrtN; ++prime){
            if(arr[prime] == false){
                continue;
            }
            int numOfMultiples = (n-1)/prime;
            for(int j = prime; j <= numOfMultiples; ++j){
                int val = prime*j;
                if(arr[val]){
                    arr[prime*j] = false; 
                    ++numOfComposites;
                }
            }
        }
        return n-2-numOfComposites;
    }
};
