class Solution {
public:
    //Time O(N), Space O(N)
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0){
            return true;
        }else if(arr[start] < 0){
            return false;
        }else{
            int a = start-arr[start], b = start+arr[start];
            arr[start] = -arr[start];
            return a >= 0 && canReach(arr, a) || b < arr.size() && canReach(arr, b);
        }        
     }
    
    //Time O(N), Space O(N)
    // bool canReach(vector<int>& arr, int start){
    //     queue<int> Q;
    //     Q.emplace(start);
    //     while(!Q.empty()){
    //         start = Q.front();
    //         Q.pop();
    //         if(arr[start] == 0){
    //             return true;
    //         }else{
    //             int left = start-arr[start];
    //             int right = start+arr[start];
    //             arr[start] = -arr[start];
    //             if(left >= 0 && arr[left] >= 0){
    //                 Q.emplace(left);
    //             }
    //             if(right < arr.size() && arr[right] >= 0){
    //                 Q.emplace(right);
    //             }
    //         }
    //     }
    //     return false;
    // }
};
