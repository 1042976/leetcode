### 315.Count of Smaller Numbers After Self

There are three solutions for this problem: Merge Sort, Segment Tree, and Binary Indexed Tree. Assuming the size of the array nums is N, the time and space complexity for Merge Sort is O(NlogN) and O(N), while for Segment Tree and Binary Indexed Tree, it is O(N) and O(1), respectively.

For the Merge Sort solution, we divide the array into two subarrays and follow these steps:

1. Update the result for each subarray separately.
2. Sort each subarray in descending order.
3. Update the result for the whole array based on the sorted subarrays.
4. Merge the two sorted subarrays.

For the Segment Tree and Binary Indexed Tree solutions, consider an array A of size 20001. The value at index i in this array represents the count of the integer (i - 10000) that appears in the input array nums. First, we use array A to initialize the tree. Then, we iterate over each integer x in nums and obtain the number of all smaller integers preceding x using the tree.

#### 1.Merge Sort (Accepted, faster than 48.80%)

```C++
void mergeArray(vector<int>& nums, vector<int>& indices, int left, int mid, int right){
    vector<int> tmp(right-left+1);
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right){
        tmp[k] = nums[indices[i]] > nums[indices[j]]? indices[i++] : indices[j++];
        ++k;
    }
    while(i <= mid){
        tmp[k++] = indices[i++];
    }
    while(j <= right){
        tmp[k++] = indices[j++];      
    }
    i = left, k = 0;
    while(i <= right){
        indices[i++] = tmp[k++];
    }
}
void mergeCount(vector<int>& nums, vector<int>& indices, vector<int>& count, int left, int right){
    if(left == right){
        return;
    }
    int mid = left + ((right-left)>>1);
    mergeCount(nums, indices, count, left, mid);
    mergeCount(nums, indices, count, mid+1, right);
    int i = left, j = mid+1;
    while(i <= mid){
        if(nums[indices[i]] <= nums[indices[j]]){
            if(++j > right){
                break;
            }
        }else{
            count[indices[i++]] += (right-j+1);
        }
    }
    mergeArray(nums, indices, left, mid, right);
}
//Time O(NlogN), Space O(N)
vector<int> countSmaller(vector<int>& nums) {
    int size = nums.size();
    vector<int> count(size, 0), indices(size);
    for(int i = 1; i < indices.size(); ++i){
        indices[i] = i;
    }
    mergeCount(nums, indices, count, 0, size-1);
    return count;
}
```

#### 2.Segment Tree (Accepted, faster than 77.49%)

```C++
class SegmentTree{
private:
    int m;
    vector<int> arr;
public:
    SegmentTree(int _m, vector<int>& nums): m(_m), arr(2*m, 0){
        for(const auto &x : nums){
            ++arr[x+10000+m];
        }
        for(int i = m-1; i > 0; --i){
            arr[i] = arr[2*i] + arr[2*i+1];
        }
    }
    void addValue(int idx, int val){
        idx += m;
        arr[idx] += val;
        while(idx > 1){
            idx >>= 1;
            arr[idx] = arr[2*idx] + arr[2*idx+1];
        }
    }
    int getSum(int right){
        int count = 0;
        int left = m;
        right += m;
        while(left <= right){
            if(left%2){
                count += arr[left++];
            }
            if(right%2 == 0){
                count += arr[right--];
            }
            left >>= 1;
            right >>= 1;
        }
        return count;
    }
};
//Time O(N), Space O(1)
vector<int> countSmaller(vector<int>& nums){
    vector<int> count(nums.size());
    SegmentTree tree(20001, nums);
    for(int i = 0; i < nums.size(); ++i){
        int idx = nums[i]+10000;
        tree.addValue(idx, -1);
        count[i] = tree.getSum(idx-1);
    }
    return count;
}
```

#### 3.Binary Indexed Tree (Accepted, faster than 91.12%)

```C++
class BIT{
private:
    int m;
    vector<int> arr;
    int getNext(int idx){
        return idx + (idx & (-idx));
    }
    int getParent(int idx){
        return idx & (idx-1);
    }
public:
    BIT(int _m, vector<int>& nums): m(_m), arr(m+1, 0){
        for(const auto &x : nums){
            addValue(x+10000, 1);
        }
    }
    void addValue(int idx, int val){
        ++idx;
        while(idx <= m){
            arr[idx] += val;
            idx = getNext(idx);
        }
    }
    int getSum(int idx){
        int count = 0;
        ++idx;
        while(idx > 0){
            count += arr[idx];
            idx = getParent(idx);
        }
        return count;
    }
};
//Time O(N), Space O(1)
vector<int> countSmaller(vector<int>& nums){
    vector<int> count(nums.size());
    BIT tree(20001, nums);
    for(int i = 0; i < nums.size(); ++i){
        int idx = nums[i]+10000;
        tree.addValue(idx, -1);
        count[i] = tree.getSum(idx-1);
    }
    return count;
}
```

