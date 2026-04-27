#include <stdbool.h>
#include <stdlib.h>

enum {
    LEFT = 0,
    TOP,
    RIGHT,
    BOTTOM
};

int street[6][2] = {
    {LEFT,  RIGHT},   // street 1
    {TOP,   BOTTOM},  // street 2
    {LEFT,  BOTTOM},  // street 3
    {RIGHT, BOTTOM},  // street 4
    {LEFT,  TOP},     // street 5
    {TOP,   RIGHT}    // street 6
};

int getOppositeDir(int dir) {
    switch (dir) {
        case LEFT:   return RIGHT;
        case RIGHT:  return LEFT;
        case TOP:    return BOTTOM;
        case BOTTOM: return TOP;
    }

    return -1;
}

bool tryPath(int** grid, int m, int n, int dir) {
    int i = 0;
    int j = 0;

    bool* visited = calloc(m * n, sizeof(bool));

    while (1) {
        // Check if we reached the destination
        if (i == m - 1 && j == n - 1) {
            free(visited);
            return true;
        }

        // If this cell was visited before, we are in a cycle
        if (visited[i * n + j]) {
            free(visited);
            return false;
        }

        visited[i * n + j] = true;

        // Move to the next cell
        switch (dir) {
            case LEFT:   j--; break;
            case RIGHT:  j++; break;
            case TOP:    i--; break;
            case BOTTOM: i++; break;
        }

        // Check out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n) {
            free(visited);
            return false;
        }

        int type = grid[i][j] - 1;
        int inDir = getOppositeDir(dir);

        // Check whether the current street can connect from the incoming direction
        if (street[type][0] == inDir) {
            dir = street[type][1];
        } else if (street[type][1] == inDir) {
            dir = street[type][0];
        } else {
            free(visited);
            return false;
        }
    }
}

bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridSize == 0 ? 0 : gridColSize[0];

    if (m == 0 || n == 0) {
        return false;
    }

    int startType = grid[0][0] - 1;

    // Try both possible directions from the first cell
    if (tryPath(grid, m, n, street[startType][0])) {
        return true;
    }

    if (tryPath(grid, m, n, street[startType][1])) {
        return true;
    }

    return false;
}