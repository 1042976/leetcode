class Solution {
public:
    //Time O(N), Space O(1)
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1; i <= n; ++i){
            string str = "";
            if(i%3 == 0){
                str.append("Fizz");
            }
            if(i%5 == 0){
                str.append("Buzz");
            }
            res[i-1] = str == ""? to_string(i) : str;
        }
        return res;
    }
};
