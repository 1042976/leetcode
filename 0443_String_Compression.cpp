class Solution {
public:
    //Time O(N), Space O(1)
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        while(j < chars.size()){
            int k = j;
            while(k+1 < chars.size() && chars[k+1] == chars[j]){
                ++k;
            }
            swap(chars[i++], chars[j]);
            int count = k-j+1;
            if(count > 1){
                string countStr = to_string(count);
                for(const auto &digit : countStr){
                    chars[i++] = digit;
                }
            }
            j = k+1;
        }
        return i;
    }
};
