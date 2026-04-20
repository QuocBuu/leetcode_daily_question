int maxDistance(int* colors, int colorsSize) {
    if (colors[0] != colors[colorsSize-1]) {
        return colorsSize - 1;
    }

    for (int i = 1; i < colorsSize; i++) {
        if (colors[i] != colors[colorsSize-1]) {
            return colorsSize - 1 - i;
        }
        if (colors[0] != colors[colorsSize-1-i]) {
            return colorsSize-1-i;
        }
    }
    return 0;
}