class Solution {
public:
    // int getDigitSquare(int k){
    //     int sum = 0;
    //     while(k > 0){
    //         int val = k%10;
    //         sum += val*val;
    //         k /= 10;
    //     }
    //     return sum;
    // }
    // //Time O(logn), Space O(logn)
    // bool isHappy(int n) {
    //     if(n == 1){
    //         return true;
    //     }
    //     unordered_set<int> hashSet;
    //     hashSet.insert(n);
    //     int k = getDigitSquare(n);
    //     while(hashSet.find(k) == hashSet.end()){
    //         if(k == 1){
    //             return true;
    //         }
    //         hashSet.insert(k);
    //         k = getDigitSquare(k);
    //     }
    //     return false;
    // }
    // int getNext(int n){
    //     int res = 0;
    //     while(n > 0){
    //         int a = n%10;
    //         res += a*a;
    //         n /= 10;
    //     }
    //     return res;
    // }
    // //Time O(logn), Space O(1)
    // bool isHappy(int n){
    //     int tortoise = getNext(n), hare = getNext(tortoise);
    //     while(tortoise != hare){
    //         tortoise = getNext(tortoise);
    //         hare = getNext(getNext(hare));
    //     }
    //     return tortoise == 1;
    // }
    
    int getNext(int n){
        int res = 0;
        while(n > 0){
            int a = n%10;
            res += a*a;
            n /= 10;
        }
        return res;
    } 
    //Time O(logn), Space O(1)
    bool isHappy(int n){
        while(n != 4 && n != 1){
            n = getNext(n);
        }
        return n == 1;
    }
};
