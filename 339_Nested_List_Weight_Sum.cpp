/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    //Time O(n) Space O(n)
    // int dfs(const vector<NestedInteger>& nestedList, int balance){
    //     int res = 0;
    //     for(const auto &nInt : nestedList){
    //         if(nInt.isInteger()){
    //             res += nInt.getInteger()*balance;
    //         }else{
    //             res += dfs(nInt.getList(), balance+1);
    //         }
    //     }
    //     return res;
    // }
    // int depthSum(vector<NestedInteger>& nestedList) {
    //     return dfs(nestedList, 1);
    // }
    
    //Time O(n) Space O(n)
    int depthSum(vector<NestedInteger>& nestedList){
        queue<NestedInteger> Q;
        int res = 0, depth = 1;
        for(const auto &nInt : nestedList){
            Q.emplace(nInt);
        }
        int size = Q.size();
        while(!Q.empty()){
            while(size--){
                NestedInteger nInt = Q.front();
                Q.pop();
                if(nInt.isInteger()){
                    res += nInt.getInteger()*depth;
                }else{
                    auto list = nInt.getList();
                    for(const auto &nInt2 : list){
                        Q.emplace(nInt2);
                    }
                }
            }
            ++depth;
            size = Q.size();
        }
        return res;
    }
};
