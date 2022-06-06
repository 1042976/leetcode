class Solution {
public:
    //Time O(M) Space O(M), M is the lengrh of the substring after
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0){
            res.push_back('-');
        }
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        long long quotient = n/d;
        n -= quotient*d;
        res.append(to_string(quotient));
        if(n == 0){
            return res;
        }else{
            res.push_back('.');
        }
        unordered_map<int, int> hashMap;
        while(n != 0){
            if(hashMap.count(n)){
                res.insert(hashMap[n], 1, '(');
                res.push_back(')');
                break;
            }
            hashMap[n] = res.length(); 
            n *= 10;
            int q = n/d;
            if(q == 0){
                res.push_back('0');
            }else{
                res.push_back(q+'0');
                n-= q*d;
            }
        }
        return res;
    }
};
