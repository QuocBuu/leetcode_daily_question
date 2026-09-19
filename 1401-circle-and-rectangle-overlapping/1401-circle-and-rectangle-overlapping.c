bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    int x = xCenter > x2 ? x2 : xCenter;
    x = x > x1 ? x : x1;
    x -= xCenter;

    int y = yCenter > y2 ? y2 : yCenter;
    y = y > y1 ? y : y1;
    y -= yCenter;

    return x*x + y*y <= radius*radius;
}