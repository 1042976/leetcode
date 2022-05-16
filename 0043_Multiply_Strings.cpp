class Solution {
public:
    //T-O(mn), S-O(1)
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int m = num1.length(), n = num2.length();
        string res(m+n, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int digit1 = num1[j]-'0';
                int digit2 = num2[i]-'0';
                int startIdx = i+j;
                int a = digit1*digit2+(res[startIdx]-'0');
                res[startIdx] = a%10+'0';
                res[startIdx+1] += a/10;
            }
        }
        if(res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
