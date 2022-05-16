class Solution {
public:
    int getNumOfSteps(string& abbr, int& j){
        int n = abbr[j++]-'0';
        while(j < abbr.length() && isdigit(abbr[j])){
            n = n*10+(abbr[j++]-'0');
        }
        return n;
    }
    //Time O(m+n) Space O(1)
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while(i < word.length() && j < abbr.length()){
            if(word[i] != abbr[j]){
                if(isalpha(abbr[j]) || abbr[j] == '0'){
                    return false;
                }else{
                    int numOfSteps = getNumOfSteps(abbr, j);
                    i += numOfSteps;
                }
            }else{
                ++i;
                ++j;
            }
        }
        return i == word.length() && j == abbr.length();
    }
};
