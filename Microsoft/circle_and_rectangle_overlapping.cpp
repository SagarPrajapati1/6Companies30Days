#include<bits/stdc++.h>
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        double a = abs(xCenter - (double) (x1 + x2) / 2) - (double) (x2-x1)/2;

        double b = abs(yCenter - (double) (y1 + y2) / 2) - (double) (y2 - y1) / 2;

        return max((double)0, a) * max((double)0, a) + max((double)0, b) * max((double)0 , b) <= radius * radius;
        
    }
};
