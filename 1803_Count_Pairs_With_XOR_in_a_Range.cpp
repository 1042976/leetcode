class Solution {
public:
    class Node{
    public:
        Node* arr[2] = {nullptr};
        int count = 1;
        ~Node(){
            delete arr[0];
            delete arr[1];
        }
    };
    class Trie{
    public:
        Node* root = new Node();
        int level = 16;
        ~Trie(){
            delete root;
        }
        void insert(int a){
            int b = level;
            Node* cur = root;
            while(b > 0){
                --b;
                int k = (a>>b)&1;
                if(cur->arr[k] == nullptr){
                    cur->arr[k] = new Node();
                    cur = cur->arr[k];
                    --b;
                    while(b >= 0){
                        k = (a>>b)&1;
                        cur->arr[k] = new Node();
                        cur = cur->arr[k];
                        --b;
                    }
                }else{
                    cur = cur->arr[k];
                    ++(cur->count);
                }               
            }
        }
        int countLess(int a, int high){
            int res = 0;
            int b = level;
            Node* cur = root;
            while(cur != nullptr && b > 0){
                --b;
                int y = (a>>b)&1;
                int z = (high>>b)&1;
                if(z == 0){
                    cur = cur->arr[y];
                }else{
                    if(cur->arr[y] != nullptr){
                        res += cur->arr[y]->count;
                    }
                    cur = cur->arr[1-y];
                }
            }
            return res;
        }
    };
    //Time O(N), Space O(1)
    int countPairs(vector<int>& nums, int low, int high) {
        int res = 0;
        Trie trie;
        for(const auto &num : nums){
            res += trie.countLess(num, high+1)-trie.countLess(num, low);
            trie.insert(num);
        }
        return res;
    }
};
