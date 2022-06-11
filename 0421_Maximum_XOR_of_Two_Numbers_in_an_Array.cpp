class Solution {
public:
    class Node{
    public:
        Node* arr[2];
        Node():arr{nullptr, nullptr}{}
        ~Node(){
            delete arr[0];
            delete arr[1];
        }
        bool hasBit(int bit){
            return arr[bit] != nullptr;
        }
        void setBit(int bit){
            arr[bit] = new Node();
        }
        Node* getNext(int bit){
            return arr[bit];
        }
    };
    class BitwiseTrie{
    public:
        Node *root;
        int maxBit;
        int maxXORVal;
        BitwiseTrie(int maxBit):root(new Node()), maxBit(maxBit), maxXORVal(0){}
        ~BitwiseTrie(){
            delete root;
        }
        void insert(int val){
            int curXORVal = 0;
            Node* curA = root;
            Node* curB = root;
            for(int k = maxBit-1; k >= 0; --k){
                int bit = (val >> k)&1;
                int opposite = !bit;
                if(!curA->hasBit(bit)){
                    curA->setBit(bit);
                }
                if(curB->getNext(opposite) != nullptr){
                    curXORVal = (curXORVal << 1 | 1);
                    curB = curB->getNext(opposite);
                }else{
                    curXORVal <<= 1;
                    curB = curB->getNext(bit);
                }
                curA = curA->getNext(bit);                
            }
            maxXORVal = max(maxXORVal, curXORVal);
        }
        
    };
    //Time O(N), Space O(1)
    int findMaximumXOR(vector<int>& nums) {
        int maxVal = INT_MIN;
        for(const auto &val : nums){
            maxVal = max(val, maxVal);
        }
        int k = (1 << 30);
        int maxBit = 31;
        while(k > 0 && (k & maxVal) == 0){
            k >>= 1;
            --maxBit;
        }
        BitwiseTrie trie(maxBit);
        for(const auto &val : nums){
            trie.insert(val);
        }
        return trie.maxXORVal;
    }
};
