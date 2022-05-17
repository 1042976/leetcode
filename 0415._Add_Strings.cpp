class Solution {
public:
    //Time O(max(n+m)) Space O(1)
    string addStrings(string num1, string num2) {
        int i = num1.length()-1, j = num2.length()-1;
        string res = "";
        int carry = 0;
        while(i >= 0 || j >= 0){
            int a = i >= 0 ? num1[i]-'0' : 0;
            int b = j >= 0 ? num2[j]-'0' : 0;
            int val = a+b+carry;
            res.push_back(val%10+'0');
            carry = val/10;
            --i;
            --j;
        }
        if(carry > 0){
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
