//recursive. use array
// class SegmentTree{
// private:
//     void buildTree(vector<int>& nums, int left, int right, int k){
//         if(left == right){
//             arr[k] = nums[left];
//         }else{
//             int mid = left + (right-left)/2;
//             buildTree(nums, left, mid, 2*k);
//             buildTree(nums, mid+1, right, 2*k+1);
//             arr[k] = arr[2*k]+arr[2*k+1];
//         }
//     }
//     void update(int idx, int val, int left, int right, int k){
//         if(left == right){
//             arr[k] = val;
//         }else{
//             int mid = left + (right-left)/2;
//             if(idx > mid){
//                 update(idx, val, mid+1, right, 2*k+1);
//             }else{
//                 update(idx, val, left, mid, 2*k);
//             }
//             arr[k] = arr[2*k]+arr[2*k+1];
//         }
//     }

//     int getSum(int i, int j, int left, int right, int k){
//         if(i > j){
//             return 0;
//         }else if(i == left && j == right){
//             return arr[k];
//         }else{
//             int mid = left + (right-left)/2;
//             return getSum(i, min(mid, j), left, mid, 2*k)+getSum(max(mid+1, i), j, mid+1, right, 2*k+1);
//         }
//     }
// public:
//     int n;
//     vector<int> arr;

//     //Time O(N), Space O(N)
//     SegmentTree(vector<int>& nums):n(nums.size()), arr(4*n){
//         buildTree(nums, 0, n-1, 1);
//     }
//     //Time O(logN), Space O(logN)
//     void update(int index, int val){
//         return update(index, val, 0, n-1, 1);
//     }
    
//     //Time O(logN), Space O(logN)
//     int getSum(int i, int j){
//         return getSum(i, j, 0, n-1, 1);
//     }
// };

//iterative, use array
// class SegmentTree{
// private:
//     int n;
//     vector<int> arr;
// public:
//     SegmentTree(vector<int>& nums): n(nums.size()), arr(2*n){
//         for(int i = 0; i < nums.size(); ++i){
//             arr[i+n] = nums[i];
//         }
//         for(int i = n-1; i >= 1; --i){
//             arr[i] = arr[2*i]+arr[2*i+1];
//         }
//     }
//     void update(int index, int val){
//         int pos = index + n;
//         arr[pos] = val;
//         while(pos > 1){
//             if(pos % 2){
//                 arr[pos/2] = arr[pos-1]+arr[pos];
//             }else{
//                 arr[pos/2] = arr[pos]+arr[pos+1];
//             }
//             pos >>= 1;
//         }
//     }
    
//     int getSum(int left, int right){
//         int sum = 0;
//         left += n;
//         right += n;
//         while(left <= right){
//             if(left % 2){
//                 sum += arr[left++];
//             }
//             if(right % 2 == 0){
//                 sum += arr[right--];
//             }
//             left >>= 1;
//             right >>= 1;
//         }
//         return sum;
//     }
// };

// class NumArray {
// public:
//     SegmentTree tree;
//     //Time O(N), Space O(N)
//     NumArray(vector<int>& nums):tree(nums) {}
    
//     //Time O(logN), Space O(1)
//     void update(int index, int val) {
//         tree.update(index, val);
//     }
//     //Time O(logN), Space O(1)
//     int sumRange(int left, int right) {
//         return tree.getSum(left, right);
//     }
// };

//binary index tree. 
class FenwickTree{
private:
    vector<int> nums;
    vector<int> arr;
    int getParent(int k){
        return k&(k-1);
    }
    int getChild(int k){
        return k+(k&(-k));
    }
    void add(int val, int k){
        while(k < arr.size()){
            arr[k] += val;
            k = getChild(k);
        }
    }
    int sum(int k){
        int res = 0;
        while(k > 0){
            res += arr[k];
            k = getParent(k);
        }
        return res;
    }
public:
    FenwickTree(vector<int>& _nums): nums(_nums), arr(_nums.size()+1, 0){
        for(int i = 0; i < _nums.size(); ++i){
            add(nums[i], i+1);
        }
    }

    void update(int index, int val){
        int dif = val-nums[index];
        nums[index] = val;
        add(dif, index+1);
    }
    
    int sumRange(int left, int right){
        return sum(right+1)-sum(left);
    }
    
};
class NumArray {
public:
    FenwickTree tree;
  
    //Time O(NlogN), Space O(N)
    NumArray(vector<int>& nums):tree(nums) {}
    
    //Time O(logN), Space O(1)
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    //Time O(logN), Space O(1)
    int sumRange(int left, int right) {
        return tree.sumRange(left, right);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
