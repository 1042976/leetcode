class Solution {
public:
    //Time O(n*maxWidth), Space O(1)
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int len = 0;
        int start = 0, end = 0;
        while(end < words.size()){
            int lenOfWord = words[end].length();
            if(len+lenOfWord < maxWidth){
                len += (lenOfWord+1);
                ++end;
            }else if(len+lenOfWord == maxWidth){
                res.emplace_back("");
                string &str = res.back();
                for(int i = start; i < end; ++i){
                    str.append(words[i]);
                    str.push_back(' ');
                }
                str.append(words[end]);
                start = end+1;
                end = start;
                if(end == words.size()){
                    return res;
                }
                len = 0;
            }else{
                res.emplace_back("");
                string &str = res.back();
                int numOfIntervals = end-start-1;
                int numOfSpaces = end-start+(maxWidth-len);
                if(numOfIntervals == 0){
                    str = words[start];
                    str.append(string(numOfSpaces, ' '));
                }else{
                    int lenOfInterval = numOfSpaces/numOfIntervals;
                    string interval(lenOfInterval, ' ');
                    int r = numOfSpaces%numOfIntervals;
                    for(int i = start; i < end-1; ++i){
                        str.append(words[i]);
                        str.append(interval);
                        if(r > 0){
                            str.push_back(' ');
                            --r;
                        }
                    }
                    str.append(words[end-1]);
                }
                start = end;
                end = start;
                len = 0;
            }
        }
        res.emplace_back("");
        string &str = res.back();
        for(int i = start; i < end-1; ++i){
            str.append(words[i]);
            str.push_back(' ');
        }
        str.append(words[end-1]);
        int numOfSpacesAtTheEnd = maxWidth-str.length();
        if(numOfSpacesAtTheEnd  > 0){
            str.append(string(numOfSpacesAtTheEnd, ' '));
        }
        return res;
    }
};
