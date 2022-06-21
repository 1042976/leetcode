### 327.Count of Range Sum

So far we have three solutions: Merge Sort, Segment Tree and Binary Indexed Tree. Each of them  has time complexity O(NlogN) and space complexity O(N), where N is the size of the input array nums. To understand these solutions,  just remember that the sum of values from index i to j is 

​																			sum(i,j) = sum(0,j)-sum(0,i-1), where i <= j

and the question to count all sum(i,j) that satisfy

​																			lower <= sum(i, j) <= upper

becomes the question to count all sum(0, j) that satisfy

​																			lower+sum(0,i-1) <= sum(0,j) <= upper+sum(0, i-1)

#### 1.Merge Sort (Accepted, faster than 54.19%)

```c++
void mergeArray(vector<long long>& sum, int left, int mid, int right){
    vector<long long> tmp(right-left+1);
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right){
        tmp[k++] = sum[i] <= sum[j]? sum[i++] : sum[j++];
    }
    while(i <= mid){
        tmp[k++] = sum[i++];
    }
    while(j <= right){
        tmp[k++] = sum[j++];
    }
    i = left, k = 0;
    while(i <= right){
        sum[i++] = tmp[k++];
    }
}
int mergeCount(vector<long long>& sum, int left, int right, int lower, int upper){
    if(left == right){
        return sum[left] >= lower && sum[right] <= upper? 1 : 0;
    }
    int count = 0;
    int mid = left + ((right-left)>>1);
    int leftCount = mergeCount(sum, left, mid, lower, upper);
    int rightCount = mergeCount(sum, mid+1, right, lower, upper);
    int i = left, k = mid+1, j = mid+1;
    while(i <= mid){
        long long lowerBound = sum[i]+lower, upperBound = sum[i]+upper;
        while(j <= right && sum[j] <= upperBound){
            ++j;
        }
        while(k <= right && sum[k] < lowerBound){
            ++k;
        }
        count += (j-k);
        ++i;
    }
    mergeArray(sum, left, mid, right);
    return leftCount+rightCount+count;
}
//Time O(NlogN), Space O(N)
int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long long> sum(nums.size(), 0);
    sum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        sum[i] = sum[i-1]+nums[i];
    }
    return mergeCount(sum, 0, sum.size()-1, lower, upper);
}
```



#### 2.Segment Tree (Accepted, faster than 72.90%)

```C++
class SegmentTree{
private:
    int n;
    vector<int> arr;
public:
    SegmentTree(int size): n(size), arr(2*size){
        arr[0] = 0;
        for(int i = 0; i < n; ++i){
            arr[i+n] = 1;
        }
        for(int i = n-1; i > 0; --i){
            arr[i] = arr[2*i]+arr[2*i+1];
        }
    }
    void addValue(int idx, int val){
        idx += n;
        arr[idx] += val;
        while(idx > 1){
            if(idx%2){
                arr[idx/2] = arr[idx-1] + arr[idx];
            }else{
                arr[idx/2] = arr[idx] + arr[idx+1];
            }
            idx >>= 1;
        }
    }
    int getSum(int left, int right){
        int count = 0;
        left += n;
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
int countRangeSum(vector<int>& nums, int lower, int upper){
    vector<long long> sum(nums.size()+1, 0);
    for(int i = 0; i < nums.size(); ++i){
        sum[i+1] = sum[i]+nums[i];
    }
    vector<long long> A(sum.begin(), sum.end());
    sort(A.begin(), A.end());
    SegmentTree tree(A.size());
    int count = 0;
    for(const auto &x : sum){
        int idx = lower_bound(A.begin(), A.end(), x)-A.begin();
        int lowerIdx = lower_bound(A.begin(), A.end(), x+lower)-A.begin();
        int upperIdx = upper_bound(A.begin(), A.end(), x+upper)-A.begin()-1;
        tree.addValue(idx, -1);
        count += tree.getSum(lowerIdx, upperIdx);
    }
    return count;
}
```



#### 3.Binart Indexed Tree (Accepted, faster than 84.68%)

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
    BIT(int _n):n(_n), arr(_n+1){
        arr[0] = 0;
        for(int idx = 0; idx < n; ++idx){
            addValue(idx, 1);
        }

    }
    void addValue(int idx, int val){
        ++idx;
        while(idx < arr.size()){
            arr[idx] += val;
            idx = getChild(idx);                
        }
    }
    int getSum(int idx){
        ++idx;
        int sum = 0;
        while(idx > 0){
            sum += arr[idx];
            idx = getParent(idx);
        }
        return sum;
    }
};
//Time O(NlogN), Space O(N)
int countRangeSum(vector<int>& nums, int lower, int upper){
    int size = nums.size();
    vector<long long> sum(nums.size()+1, 0);
    for(int i = 0; i < size; ++i){
        sum[i+1] = sum[i]+nums[i];
    }
    vector<long long> A(sum.begin(), sum.end());
    sort(A.begin(), A.end());       
    BIT tree(A.size());
    int count = 0;
    for(const auto &x : sum){
        int idx = lower_bound(A.begin(), A.end(), x)-A.begin();
        int lowerIdx = lower_bound(A.begin(), A.end(), x+lower)-A.begin();
        int upperIdx = upper_bound(A.begin(), A.end(), x+upper)-A.begin()-1;
        tree.addValue(idx, -1);
        count += tree.getSum(upperIdx)-tree.getSum(lowerIdx-1);
    }
    return count;
}
```

