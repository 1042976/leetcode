class Solution {
public:
    // int minCount = INT_MAX;  
    // void dfs(int n, int largest, int count){
    //     if(++count > minCount){
    //         return;
    //     }
    //     for(int i = largest; i >= 1; --i){
    //         int rest = n-i*i;
    //         if(rest == 0){
    //             minCount = min(minCount, count);
    //         }else if(rest > 0){
    //             dfs(rest, i, count);
    //         }
    //     }
    // }
    // //Time O(N * sqrt(N)), Space O(N)
    // int numSquares(int n) {
    //     dfs(n, sqrt(n), 0);
    //     return minCount;
    // }
    bool isSquare(int n){
        int a = sqrt(n);
        return n == a*a;
    }
    //Time O(sqrt(n)), Space O(1)
    int numSquares(int n){
        while(n%4 == 0){
            n /= 4;
        }
        if(n%8 == 7){
            return 4;
        }
        int a = sqrt(n);
        if(a*a == n){
            return 1;
        }
        for(int i = 1; i <= a; ++i){
            if(isSquare(n-i*i)){
                return 2;
            }
        }
        return 3;
    }
};
