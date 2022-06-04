class Solution {
public:
    //Time O(n^2), Space O(n^2)
    // int maxPoints(vector<vector<int>>& points) {
    //     double infinity = std::numeric_limits<double>::infinity();
    //     unordered_map<double, unordered_map<double, int> > hashMap;
    //     int numberOfPairs = 0;     
    //     for(int i = 0; i < points.size(); ++i){
    //         for(int j = i+1; j < points.size(); ++j){
    //             int x1 = points[i][0], y1 = points[i][1];
    //             int x2 = points[j][0], y2 = points[j][1];
    //             double k = x1 == x2? infinity : (y2-y1)*1.0/(x2-x1);
    //             double b = x1 == x2? x1 : ((x2-x1)*y1-(y2-y1)*x1)/((x2-x1)*1.0);
    //             numberOfPairs  = max(numberOfPairs , ++hashMap[k][b]);
    //         }
    //     }
    //     return (1+sqrt(1+8*numberOfPairs))/2;
    // }
    
    //Time O(n^2), Space O(n)
    // int maxPoints(vector<vector<int>>& points) {
    //    
    //     unordered_map<double, int> hashMap;
    //     int maxVal = 0; 
    //     for(int i = 0; i < points.size(); ++i){
    //         int x1 = points[i][0], y1 = points[i][1];
    //         hashMap.clear();
    //         int numberOfPoints = 0;
    //         for(int j = i+1; j < points.size(); ++j){
    //             int x2 = points[j][0], y2 = points[j][1];
    //             double k = x1 == x2? infinity : (y2-y1)*1.0/(x2-x1);
    //             numberOfPoints  = max(numberOfPoints , ++hashMap[k]);
    //         }
    //         maxVal = max(maxVal, numberOfPoints+1);
    //     }
    //     return maxVal;
    // }
    
    //Time O(n^2), Space O(n)
    // int maxPoints(vector<vector<int>>& points) {
    //     unordered_map<string, int> hashMap;
    //     int maxVal = 0; 
    //     for(int i = 0; i < points.size(); ++i){
    //         int x1 = points[i][0], y1 = points[i][1];
    //         hashMap.clear();
    //         int numberOfPoints = 0;
    //         for(int j = i+1; j < points.size(); ++j){
    //             int x2 = points[j][0], y2 = points[j][1];
    //             int deltaX = x2-x1, deltaY = y2-y1;
    //             int coPrimeX = 0;
    //             int coPrimeY = 0;
    //             if(deltaX == 0){
    //                 coPrimeX = INT_MAX;
    //                 coPrimeY = INT_MAX;
    //             }else if(deltaY == 0){
    //                 coPrimeX = 0;
    //                 coPrimeY = 0;
    //             }else{
    //                 int commonDivisor = gcd(deltaX, deltaY);
    //                 coPrimeX = deltaX/commonDivisor;
    //                 coPrimeY = deltaY/commonDivisor;
    //                 if(coPrimeX < 0){
    //                     coPrimeX = -coPrimeX;
    //                     coPrimeY = -coPrimeY;
    //                 }
    //             }
    //             string key = to_string(coPrimeX)+","+to_string(coPrimeY);
    //             numberOfPoints  = max(numberOfPoints , ++hashMap[key]);
    //         }
    //         maxVal = max(maxVal, numberOfPoints+1);
    //     }
    //     return maxVal;
    // }
    
    int gcd(int a, int b){
        a = abs(a);
        b = abs(b);
        if(a < b){
            swap(a, b);
        }
        int r = a%b;
        while(r != 0){
            a = b;
            b = r;
            r = a%b;
        }
        return b;
    }
    //Time O(n^2), Space O(n)
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<string, int> hashMap;
        int maxVal = 0; 
        for(int i = 0; i < points.size(); ++i){
            int x1 = points[i][0], y1 = points[i][1];
            hashMap.clear();
            int numberOfPoints = 0;
            for(int j = i+1; j < points.size(); ++j){
                int x2 = points[j][0], y2 = points[j][1];
                int deltaX = x2-x1, deltaY = y2-y1;
                int coPrimeX = 0;
                int coPrimeY = 0;
                if(deltaX == 0){
                    coPrimeX = INT_MAX;
                    coPrimeY = INT_MAX;
                }else if(deltaY == 0){
                    coPrimeX = 0;
                    coPrimeY = 0;
                }else{
                    int commonDivisor = gcd(deltaX, deltaY);
                    coPrimeX = deltaX/commonDivisor;
                    coPrimeY = deltaY/commonDivisor;
                    if(coPrimeX < 0){
                        coPrimeX = -coPrimeX;
                        coPrimeY = -coPrimeY;
                    }
                }
                string key = to_string(coPrimeX)+","+to_string(coPrimeY);
                numberOfPoints  = max(numberOfPoints , ++hashMap[key]);
            }
            maxVal = max(maxVal, numberOfPoints+1);
        }
        return maxVal;
    }
};
