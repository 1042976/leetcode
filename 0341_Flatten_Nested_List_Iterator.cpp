/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int cur;
    vector<int> arr;

    void init(const vector<NestedInteger> &nestedList){
        for(const auto &x : nestedList){
            if(x.isInteger()){
                arr.emplace_back(x.getInteger());
            }else{
                init(x.getList());
            }
        }
    }
    //Time O(N+M), Space O(N+M)
    NestedIterator(vector<NestedInteger> &nestedList): cur(0){
        init(nestedList);
    }
    
    //Time O(1), Space O(1)
    int next() {
        return arr[cur++];
    }
    
    //Time O(1), Space O(1);
    bool hasNext() {
        return cur < arr.size();
    }
    
    
    
    
    
//     stack<NestedInteger> st;
//     //Time O(N+M), Space O(N+M)
//     NestedIterator(vector<NestedInteger> &nestedList){
//         for(int i = nestedList.size()-1; i >= 0; --i){
//             st.emplace(nestedList[i]);
//         }
//     }
    
//     //Time O(1), Space O(1)
//     int next() {
//         int val = st.top().getInteger();
//         st.pop();
//         return val;
//     }
    
//     //Time O(M/N), Space O(1);
//     bool hasNext() {
//         while(!st.empty() && !st.top().isInteger()){
//             auto nestedList = st.top().getList();
//             st.pop();
//             for(int i = nestedList.size()-1; i >= 0; --i){
//                 st.emplace(nestedList[i]);
//             }
//         }
//         return !st.empty();
//     }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
