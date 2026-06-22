class Solution {
public:
    double angleClock(int hour, int minutes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        double minute_angle = minutes * 6.0;
        double hour_angle = (hour % 12) * 30.0 + (minutes * 0.5);
        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360.0 - diff);
    }
};