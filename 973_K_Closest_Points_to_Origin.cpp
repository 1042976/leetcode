class Solution {
public:
    // int euclidean(vector<int>& point){
    //     return point[0]*point[0]+point[1]*point[1];
    // }
    // //Time O(nlogk) Space O(k)
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     priority_queue<pair<int, int> > maxHeap;
    //     for(int i = 0; i < k; ++i){
    //         maxHeap.emplace(make_pair(euclidean(points[i]), i));
    //     }
    //     for(int i = k; i < points.size(); ++i){
    //         int d = euclidean(points[i]);
    //         if(d < maxHeap.top().first){
    //             maxHeap.pop();
    //             maxHeap.emplace(make_pair(d, i));
    //         }
    //     }
    //     vector<vector<int> > res;
    //     while(!maxHeap.empty()){
    //         res.emplace_back(points[maxHeap.top().second]);
    //         maxHeap.pop();
    //     }
    //     return res;
    // }
    int euclidean(vector<int>& point){
        return point[0]*point[0]+point[1]*point[1];
    }
    int partition(vector<vector<int> >& points, int l ,int r){
        int idx = l+rand()%(r-l+1);
        swap(points[idx], points[r]);
        int i = l;
        int pivotD = euclidean(points[r]);
        for(int j = l; j < r; ++j){
            if(euclidean(points[j]) < pivotD){
                swap(points[i++], points[j]);
            }
        }
        swap(points[i], points[r]);
        return i;
    }
    void quickSelect(vector<vector<int> >& points, int l, int r, int k){
        while(l < r){
            int pos = partition(points, l, r);
            if(pos == k || pos == k-1){
                return;
            }else if(pos > k){
                r = pos-1;    
            }else{
                l = pos+1;
            }
        }
    }
    //Time avg-O(n), worst-O(n^2). Space O(1)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        srand(time(NULL));
        quickSelect(points, 0, points.size()-1, k);
        vector<vector<int> > res;
        for(int i = 0; i < k; ++i){
            res.emplace_back(points[i]);
        }
        return res;
    }
};
