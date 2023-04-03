class Solution {
public:
    const int arr[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    const int daysInLeapYear = 366;
    bool isLeap(int year){
        return year%4 == 0 && year%100 > 0 || year%400 == 0;
    }
    int numOfLeapYears(int start, int end){
        while(start%4){
            ++start;
        }
        if(start >= end){
            return 0;
        }
        return (end-start)/4 + ((end-start)%4 > 0) - (end == 2101);
              
    }
    int getDays(int startYear, vector<int>& ymd){
        int total = daysInLeapYear*(ymd[0]-startYear) - (ymd[0]-startYear-numOfLeapYears(startYear, ymd[0]));
        total += arr[ymd[1]-1] + ymd[2] - (isLeap(ymd[0])? 0 : ymd[1] > 2);
        return total;
    }
    
    vector<int> parse(const string& date){
        int i = date.find('-'), j = date.find('-', i+1);
        int year = stoi(date.substr(0, i)), month = stoi(date.substr(i+1, j)), day = stoi(date.substr(j+1));
        return vector<int>{year, month, day};
    }
    
    //Time O(1), Space O(1), D is the year's difference between date1 and date2.
    int daysBetweenDates(string date1, string date2) {
        vector<int> ymd1 = parse(date1), ymd2 = parse(date2);
        if(ymd1[0] > ymd2[0]){
            swap(ymd1, ymd2);
        }
        int days1 = getDays(ymd1[0], ymd1), days2 = getDays(ymd1[0], ymd2);
        return abs(days2-days1);
    }
};
