class Solution {
public:
    //Time O(max(logm, logn)), Space O(1)
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1 = nums1.size(), n2 = nums2.size();
    //     int l1 = 0, r1 =n1-1, l2 = 0, r2 = n2-1;
    //     int rest = (n1+n2-1)/2;
    //     while(rest > 0){
    //         if(l1 > r1){
    //             l2 += rest;
    //             break;
    //         }else if(l2 > r2){
    //             l1 += rest;
    //             break;
    //         }
    //         int m1 = l1+(r1-l1+1)/2;
    //         int m2 = l2+(r2-l2+1)/2;
    //         int k1 = m1-l1+1;
    //         int k2 = m2-l2+1;
    //         int n3 = k1+k2;
    //         if(nums2[m2] >= nums1[m1]){
    //             if(n3 <= rest){
    //                 l1 =  m1+1;
    //                 rest -= k1;
    //             }else{
    //                 r2 = m2-1;
    //             }
    //         }else{
    //             if(n3 <= rest){
    //                 l2 = m2+1;
    //                 rest -= k2;
    //             }else{
    //                 r1 = m1-1;
    //             }
    //         }
    //     }
    //     priority_queue<int, vector<int>, greater<int> > minHeap;
    //     if(l1 < n1){
    //         minHeap.emplace(nums1[l1]);
    //     }
    //     if(l2 < n2){
    //         minHeap.emplace(nums2[l2]);
    //     }
    //     if((n1+n2)%2){
    //         return minHeap.top();
    //     }
    //     if(l1+1 < n1){
    //         minHeap.emplace(nums1[l1+1]);
    //     }
    //     if(l2+1 < n2){
    //         minHeap.emplace(nums2[l2+1]);
    //     }
    //     int median1 = minHeap.top();
    //     minHeap.pop();
    //     return (median1+minHeap.top())/2.0;
    // }
    //Time O(log(m+n)), Space O(log(m+n))
    // int findKthLargest(vector<int> &nums1, int l1, vector<int> &nums2, int l2, int k){
    //     if(l1 == nums1.size()){
    //         return nums2[l2+k-1];
    //     }
    //     if(l2 == nums2.size()){
    //         return nums1[l1+k-1];
    //     }
    //     if(k == 1){
    //         return min(nums1[l1], nums2[l2]);
    //     }
    //     int m = k/2;
    //     int N1 = l1+m-1 < nums1.size()? nums1[l1+m-1] : INT_MAX;
    //     int N2 = l2+m-1 < nums2.size()? nums2[l2+m-1] : INT_MAX;
    //     if(N1 < N2){
    //         return findKthLargest(nums1, l1+m, nums2, l2, k-m);
    //     }else{
    //         return findKthLargest(nums1, l1, nums2, l2+m, k-m);
    //     }
    // }
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    //     int m = nums1.size(), n = nums2.size();
    //     return (findKthLargest(nums1, 0, nums2, 0, (m+n+1)/2)+findKthLargest(nums1, 0, nums2, 0, (m+n+2)/2))/2.0;
    // }
    
    int findKthLargest(vector<int> &nums1, vector<int> &nums2, int k){
        int l1 = 0, l2 = 0;
        while(l1 < nums1.size() && l2 < nums2.size()){
            if(k == 1){
                return min(nums1[l1], nums2[l2]);
            }
            int m = k/2;
            int N1 = l1+m-1 < nums1.size() ? nums1[l1+m-1] : INT_MAX;
            int N2 = l2+m-1 < nums2.size() ? nums2[l2+m-1] : INT_MAX;
            if(N1 < N2){
                l1 = l1+m;
            }else{
                l2 = l2+m;
            }
            k -= m;
        }
        if(l1 == nums1.size()){
            return nums2[l2+k-1];
        }
        if(l2 == nums2.size()){
            return nums1[l1+k-1];
        }
        return min(nums1[l1], nums2[l2]);
    }
    
    //Time O(log(m+n)), Space O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size(), n = nums2.size();
        return (findKthLargest(nums1, nums2, (m+n+1)/2)+findKthLargest(nums1, nums2, (m+n+2)/2))/2.0;        
    }
};
