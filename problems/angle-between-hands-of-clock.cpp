class Solution {
public:
    double angleClock(int hr, int m) {
        double ret;
        double hrAngle = (double) (hr % 12) * 30 + (double) m/60 * 30;
        double minAngle = m * 6; 
        
        ret = abs (minAngle - hrAngle);
        
        return min(ret, 360-ret);
    }
};
