class Solution {
public:
    //Time O(NlogM), Space O(1)
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = 0;
        for(int i = 0; i < stations.size()-1; ++i){
            double dist = stations[i+1]-stations[i];
            right = max(right, dist);
        }
        while(right-left >= 1e-5){
            double mid = left + ((right-left)/2.0);
            int count = 0;
            for(int i = 0; i < stations.size()-1; ++i){
                int dist = stations[i+1]-stations[i];
                count += ceil(dist/mid)-1;
            }
            if(count > k){
                left = mid + 1e-5;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
