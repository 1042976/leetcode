class Solution {
public: 
//     bool addLink(int pN, int cN, int parent[]){
//          if(cN != -1){
//             if(cN == pN){
//                 return false;
//             }
//             if(parent[cN] != -1){
//                 return false;
//             }else{
//                 if(parent[pN] == cN){
//                     return false;
//                 }else{
//                     parent[cN] = pN;
//                 }
//             }
//         }
//         return true;
//     }
//     int findRoot(int original, int i, int parent[]){
//         if(parent[i] == original){
//             return original;
//         }else if(parent[i] == -1){
//             return parent[i] = i;
//         }else if(parent[i] == i){
//             return i;
//         }else{
//             return parent[i] = findRoot(original, parent[i], parent);
//         }
//     }
    
//     //Union. Time O(N), Space O(N), N is the number of nodes in the tree
//     bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
//         int size = leftChild.size();
//         int parent[size];
//         memset(parent, -1, sizeof(parent));
//         for(int i = 0; i < size; ++i){
//             bool state = addLink(i, leftChild[i], parent);
//             if(!state){
//                 return false;
//             }
//             state = addLink(i, rightChild[i], parent);
//             if(!state){
//                 return false;
//             }
//         }
//         for(int i = 0; i < size; ++i){
//             if(parent[i] == i){
//                 return false;
//             }
//         }
//         int root = -1;
//         for(int i = 0; i < size; ++i){
//             int root1 = findRoot(i, i, parent);
//             if(root != -1 && root1 != root){
//                 return false;
//             }
//             root = root1;
//         }
//         return true;
//     }
    
    int countNodes(int root, vector<int>& leftChild, vector<int>& rightChild){
        if(root == -1){
            return 0;
        }
        return 1 + countNodes(leftChild[root], leftChild, rightChild) + countNodes(rightChild[root], leftChild, rightChild);
    }
    ////dfs. Time O(N), Space O(N)
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){
        int size = leftChild.size();
        int indegree[size];
        memset(indegree, 0, sizeof(indegree));
        for(int i = 0; i < size; ++i){
            if(leftChild[i] != -1 && ++indegree[leftChild[i]] > 1){
                return false;
            }
            if(rightChild[i] != -1 && ++indegree[rightChild[i]] > 1){
                return false;
            }
        }
        int root = -1;
        for(int i = 0; i < size; ++i){
            if(indegree[i] == 0){
                if(root != -1){
                    return false;
                }else{
                    root = i;
                }
            }
        }
        return countNodes(root, leftChild, rightChild) == size;
    }
};
