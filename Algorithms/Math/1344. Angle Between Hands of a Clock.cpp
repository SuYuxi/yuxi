class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hAngel = hour * 30 + minutes * 0.5;
        double mAngel = minutes * 6;
        return min(abs(hAngel - mAngel), 360 - abs(hAngel - mAngel));
    }
};
