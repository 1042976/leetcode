class Solution {
public:
    //Time O(N), Space O(1)
    string originalDigits(string s) {
        int arr[26];
        for(int i = 0; i < 26; ++i){
            arr[i] = 0;
        }
        for(const auto &c : s){
            ++arr[c-'a'];
        }
        int count[10];
        //zero
        count[0] = arr['z'-'a'];
        //two
        count[2] = arr['w'-'a'];
        //four
        count[4] = arr['u'-'a'];
        //six
        count[6] = arr['x'-'a'];
        //eight
        count[8] = arr['g'-'a'];
        //one
        count[1] = arr['o'-'a']-count[0]-count[2]-count[4];
        //three
        count[3] = arr['t'-'a']-count[2]-count[8];
        //five
        count[5] = arr['f'-'a']-count[4];
        //seven
        count[7] = arr['s'-'a']-count[6];
        //nine
        count[9] = (arr['n'-'a']-count[1]-count[7])/2;
        
        
        string res = "";
        for(int i = 0; i <= 9; ++i){
            res.append(string(count[i], i+'0'));
        }
        return res;
    }
};
