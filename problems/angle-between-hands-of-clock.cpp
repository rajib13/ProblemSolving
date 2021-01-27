class Solution {
public:
    double angleClock(int hr, int m) {
        // Idea: For every hour (resp. minute) the covered angle is 30 (resp. 6) degree;
        double ret; 
	// Angle covered by hour (hour hand plus the minutes hand)
        double hrAngle = (double) (hr % 12) * 30 + (double) m/60 * 30;
        double minAngle = m * 6;  
        ret = abs(minAngle - hrAngle);
        
        return min(ret, 360-ret);
    }
};

/*
	Complexity analysis:
	Time: O(1), as every step of the program takes constant time.
	Space: O(1), since we did not use any exrta space.
*/
