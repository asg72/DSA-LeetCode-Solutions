class Solution {
public:
    /**
     * Calculates the smaller angle (in degrees) formed between the hour and minute hand.
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    double angleClock(int hour, int minutes) {
        // Hour hand moves 30 degrees per hour, plus 0.5 degrees per minute.
        // Minute hand moves 6 degrees per minute.
        // Formula simplified: abs(30 * hour + 0.5 * minutes - 6 * minutes)
        double angle = abs((30.0 * hour) - (5.5 * minutes));
        
        // If the angle is reflex (greater than 180), take the smaller side
        if (angle > 180.0) {
            angle = 360.0 - angle;
        }
        
        return angle;
    }
};