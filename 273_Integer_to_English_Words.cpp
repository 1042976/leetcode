class Solution {
public:
    //T-O(n), S-O(1)
    string one(int num){
        //num > 0
        if(num == 1){
            return "One";
        }else if(num == 2){
            return "Two";
        }else if(num == 3){
            return "Three";
        }else if(num == 4){
            return "Four";
        }else if(num == 5){
            return "Five";
        }else if(num == 6){
            return "Six";
        }else if(num == 7){
            return "Seven";
        }else if(num == 8){
            return "Eight";
        }else{
            return "Nine";
        }
    }
    
    string lessThanTwenty(int num){
        if(num == 10){
            return "Ten";
        }else if(num == 11){
            return "Eleven";
        }else if(num == 12){
            return "Twelve";
        }else if(num == 13){
            return "Thirteen";
        }else if(num == 14){
            return "Fourteen";
        }else if(num == 15){
            return "Fifteen";
        }else if(num == 16){
            return "Sixteen";
        }else if(num == 17){
            return "Seventeen";
        }else if(num == 18){
            return "Eighteen";
        }else{
            return "Nineteen";
        }
    }
    
    string largerThanTwenty(int num){
        string res = "";
        int ten = num/10;
        int rest = num-ten*10;
        if(ten == 2){
            res += "Twenty";
        }else if(ten == 3){
            res += "Thirty";
        }else if(ten == 4){
            res += "Forty";
        }else if(ten == 5){
            res += "Fifty";
        }else if(ten == 6){
            res += "Sixty";
        }else if(ten == 7){
            res += "Seventy";
        }else if(ten == 8){
            res += "Eighty";
        }else{
            res += "Ninety";
        }
        if(rest > 0){
            if(!res.empty()){
                res.push_back(' ');
            }
            res += one(rest);
        }
        return res;
    }
    string two(int num){
        //num > 0
        if(num < 10){
            return one(num);
        }else if(num >= 10 && num < 20){
            return lessThanTwenty(num);
        }else{
            return largerThanTwenty(num);
        }
    }
    
    string three(int num){
        //num > 0
        string res = "";
        int hundred = num/100;
        int rest = num-hundred*100;
        if(hundred > 0){
            res += one(hundred) + " Hundred";
        }
        if(rest > 0){
            if(!res.empty()){
                res.push_back(' ');
            }
            res += two(rest);
        }
        return res;
        
    }
    string numberToWords(int num) {
        //1e3
        //1e6
        //1e9
        string res = "";
        int billion = num/1e9;
        int million = (num-billion*(int)1e9)/(int)1e6;
        int thousand = (num-billion*(int)1e9-million*(int)1e6)/(int)1e3;
        num %= (int)1e3;
        if(billion >= 1e3){
            res += (numberToWords(num) + " Billion");
        }else if(billion > 0){
            res += (three(billion)+ " Billion");
        }
        if(million > 0){
            if(!res.empty()){
                res.push_back(' ');
            }
            res += (three(million) + " Million");
        }
        if(thousand > 0){
            if(!res.empty()){
                res.push_back(' ');
            }
            res += (three(thousand) + " Thousand");
        }
        if(num > 0){
            if(!res.empty()){
                res.push_back(' ');
            }
           res += three(num); 
        }
        return res == ""? "Zero" : res;
    }
};
