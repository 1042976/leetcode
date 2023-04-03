class Solution {
public:
    vector<string> segment;
    vector<string> res;
    int len;
    string getAddress(){
        return segment[0]+"."+segment[1]+"."+segment[2]+"."+segment[3];
    }
    void backtrack(string& s, int i, int dots){
        if(i == len){
            return;
        }
        if(dots == 0){
            int lenOfSub = len-i;
            if(lenOfSub <= 3){
                string sub = s.substr(i, lenOfSub);
                int val = stoi(sub);
                if(lenOfSub == 1 || sub[0] != '0' && val <= 255){
                    segment.emplace_back(sub);
                    res.emplace_back(getAddress());
                    segment.pop_back();
                }
            }
            return;
        }
        segment.emplace_back(string(1, s[i]));
        backtrack(s, i+1, dots-1);
        if(s[i] != '0'){
            if(i+1 < len){
                segment.back().push_back(s[i+1]);
                backtrack(s, i+2, dots-1);
                if(i+2 < len && stoi(s.substr(i, 3)) <= 255){         
                    segment.back().push_back(s[i+2]);
                    backtrack(s, i+3, dots-1); 
                    segment.back().pop_back();
                }
                segment.back().pop_back();
            }
        }
        segment.pop_back();
    }
    //Time O(N), Space O(1)
    vector<string> restoreIpAddresses(string s) {
        len = s.length();
        backtrack(s, 0, 3);
        return res;
    }
};
