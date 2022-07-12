class Solution {
public:
    //Time O(N), Space O(1)
    bool isStrobogrammatic(string num) {
        int len = num.length();
        for(int i = 0; i <= (len-1)/2; ++i){
            if(num[i] == '2' || num[i] == '3' || num[i] == '4' || num[i] == '5' || num[i] == '7'){
                return false;
            }else if(num[i] == '1' && num[len-i-1] != '1' || num[i] == '8' && num[len-i-1] != '8'){
                return false;
            }else if(num[i] == '6' && num[len-i-1] != '9' || num[i] == '9' && num[len-i-1] != '6'){
                return false;
            }
        }
        return true;
    }
};
