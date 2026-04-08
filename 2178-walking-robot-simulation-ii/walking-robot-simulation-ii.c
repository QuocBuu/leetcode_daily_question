int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
const char* charDir[] = {"North", "East", "South", "West"};

typedef struct {
    int w;
    int h;
    int x;
    int y;
    int dir; // 0 = N; 1 = E; 2 = S; 3 = W
} Robot;

Robot* robotCreate(int width, int height) {
    if (width < 2 || height < 2) {
        return NULL;
    }
    Robot* newRB = malloc(sizeof(Robot));
    newRB->w = width-1;
    newRB->h = height-1;
    newRB->x = 0;
    newRB->y = 0;
    newRB->dir = 1; // East
    return newRB;
}

void robotStep(Robot* obj, int num) {
    int total = (obj->w + obj->h) * 2;
    int step = num % total;
    if (step == 0 && num > 0) {
        step = total;
    }
    for (int i = 0; i < step; i++) {
        if ((obj->x == obj->w && obj->dir == 1) || (obj->y == obj->h && obj->dir == 0) || (obj->x == 0 && obj->dir == 3) || (obj->y == 0 && obj->dir == 2)) {
            obj->dir = (obj->dir + 3) % 4;
        }
        int rX = dx[obj->dir];
        int rY = dy[obj->dir];
        obj->x += rX;
        obj->y += rY;
    }
}

int* robotGetPos(Robot* obj, int* retSize) {
    int *ret = malloc(sizeof(int)*2);
    ret[0] = obj->x;
    ret[1] = obj->y;
    *retSize = 2;
    return ret;
}

char* robotGetDir(Robot* obj) {
    return charDir[obj->dir];
}

void robotFree(Robot* obj) {
    free(obj);
}

/**
 * Your Robot struct will be instantiated and called as such:
 * Robot* obj = robotCreate(width, height);
 * robotStep(obj, num);
 
 * int* param_2 = robotGetPos(obj, retSize);
 
 * char* param_3 = robotGetDir(obj);
 
 * robotFree(obj);
*/