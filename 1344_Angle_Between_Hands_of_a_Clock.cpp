class Solution {
public:
    //T-O(1), S-O(1)
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double hourHandAngle = hour*30 + minutes/2.0;
        double minHandAngle = minutes*6.0;
        double res = 0;
        if(hourHandAngle >= minHandAngle){
            res = hourHandAngle-minHandAngle;
        }else{
            res = minHandAngle-hourHandAngle;
        }
        if(res > 180.0){
            res = 360.0-res;
        }
        return res;
    }
};
