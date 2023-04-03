class Solution {
public:
    // unordered_map<int, int> hashMapLeap{
    //     {1, 0},
    //     {2, 31},
    //     {3, 60},
    //     {4, 91},
    //     {5, 121},
    //     {6, 152},
    //     {7, 182},
    //     {8, 213},
    //     {9, 244},
    //     {10, 274},
    //     {11, 305},
    //     {12, 335}
    // };
    // unordered_map<int, int> hashMapNonLeap{
    //     {1, 0},
    //     {2, 31},
    //     {3, 59},
    //     {4, 90},
    //     {5, 120},
    //     {6, 151},
    //     {7, 181},
    //     {8, 212},
    //     {9, 243},
    //     {10, 273},
    //     {11, 304},
    //     {12, 334}      
    // };   
    // //Time O(1), Space O(1)
    // int dayOfYear(string date) {
    //     int i = date.find('-');
    //     int year = stoi(date.substr(0, i));
    //     bool isLeap = year%4 == 0 && year%100 > 0 || year%400 == 0;
    //     int j = date.find('-', ++i);
    //     return (isLeap? hashMapLeap[stoi(date.substr(i, j))] : hashMapNonLeap[stoi(date.substr(i, j))]) + stoi(date.substr(j+1));
    // }
    
    
    int arr[12]{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    //Time O(1), Space O(1)
    int dayOfYear(string date){
        int i = date.find('-'), j = date.find('-', i+1);
        int year = stoi(date.substr(0, i)), month = stoi(date.substr(i+1, j)), day = stoi(date.substr(j+1));              
        return arr[month-1] + day- ((year%4 == 0 && year%100 > 0 || year%400 == 0)? 0 : month > 2);     
    }
};
