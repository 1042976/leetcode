### 315.Count of Smaller Numbers After Self

We have three solutions: Merge Sort, Segment Tree, and Binary Indexed Tree. They all have a time complexity of O(NlogN) and space complexity of O(N), where N is the size of the given input array.

For Merge Sort, we divide the array into two subarrays, and the workflow is:

1. Update the result for subarrays separately.
2. Sort each subarray by decreasing order.
3. Update the result for the whole array based on sorted subarrays.
4. Merge the two sorted subarrays.

For Segment Tree and Binary Indexed Tree, we initialize the result array "count" the same as the input array "nums" and sort the nums by ascending order. We build up the tree structure based on the size of the array and add value 1 to the corresponding node that covers the value in the array "nums." After that, we traverse the array "count" from the beginning, and we use the lower_bound method to find the first index in the array "nums" for the current value we are on. We remove the current value's weight from the tree to avoid taking it into account in subsequent traversal and then use the tree structure to calculate the count of values ahead of the current value and update the array "count" in place.

#### 1.Merge Sort (Accepted, faster than 43.36%)

```C++
void mergeArray(vector<int>& nums, vector<int>& indices, int left, int mid, int right){
    vector<int> tmp(right-left+1);
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right){
        if(nums[indices[i]] > nums[indices[j]]){
            tmp[k] = indices[i++];
        }else{
            tmp[k] = indices[j++];
        }
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

#### 2.Segment Tree (Accepted, faster than 68.27%)

```C++
class SegmentTree{
private:
    int n;
    vector<int> arr;
public:
    SegmentTree(int size): n(size), arr(2*size){
        arr[0] = 0;
        for(int i = n; i < 2*n; ++i){
            arr[i] = 1;
        }
        for(int i = n-1; i > 0; --i){
            arr[i] = arr[2*i] + arr[2*i+1];
        }
    }
    void addValue(int idx, int val){
        idx += n;
        arr[idx] += val;
        while(idx > 1){
            idx >>= 1;
            arr[idx] = arr[2*idx] + arr[2*idx+1];
        }
    }
    int getSum(int right){
        int count = 0;
        int left = n;
        right += n;
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
//Time O(NlogN), Space O(N)
vector<int> countSmaller(vector<int>& nums){
    int size = nums.size();
    vector<int> count(nums.begin(), nums.end());
    sort(nums.begin(), nums.end());
    SegmentTree tree(size);
    for(int i = 0; i < size; ++i){
        int idx = lower_bound(nums.begin(), nums.end(), count[i])-nums.begin();
        tree.addValue(idx, -1);
        count[i] = tree.getSum(idx-1);
    }
    return count;
}

```

#### 3.Binary Indexed Tree (Accepted, faster than 82.27%)

```C++
class BIT{
private:
    int n;
    vector<int> arr;
    int getNext(int idx){
        return idx + (idx & (-idx));
    }
    int getParent(int idx){
        return idx & (idx-1);
    }
public:
    BIT(int size): n(size), arr(size+1, 0){
        arr[0] = 0;
        for(int i = 0; i < n; ++i){
            addValue(i, 1);
        }
    }
    void addValue(int idx, int val){
        ++idx;
        while(idx <= n){
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
//Time O(NlogN), Space O(N)
vector<int> countSmaller(vector<int>& nums){
    vector<int> count(nums.begin(), nums.end());
    sort(nums.begin(), nums.end());
    int size = nums.size();
    BIT tree(size);
    for(int i = 0; i < size; ++i){
        int idx = lower_bound(nums.begin(), nums.end(), count[i])-nums.begin();
        tree.addValue(idx, -1);
        count[i] = tree.getSum(idx-1);
    }
    return count;
}
```

