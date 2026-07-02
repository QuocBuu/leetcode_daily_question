class Solution {
public:
    int dir[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;

        vector<int> best(total, -1);
        deque<int> dq;

        int startHealth = health - grid[0][0];

        if (startHealth <= 0) {
            return false;
        }

        best[0] = startHealth;
        dq.push_back(0);

        while (!dq.empty()) {
            int val = dq.front();
            dq.pop_front();

            int hel = best[val];

            if (val == total - 1) {
                return hel > 0;
            }

            int x = val / n;
            int y = val % n;

            for (int i = 0; i < 4; i++) {
                int x1 = x + dir[i][0];
                int y1 = y + dir[i][1];

                if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) {
                    continue;
                }

                int val2 = x1 * n + y1;
                int nextHealth = hel - grid[x1][y1];

                if (nextHealth <= 0) {
                    continue;
                }

                if (nextHealth > best[val2]) {
                    best[val2] = nextHealth;

                    if (grid[x1][y1] == 0) {
                        dq.push_front(val2); // cost 0
                    } else {
                        dq.push_back(val2);  // cost 1
                    }
                }
            }
        }

        return false;
    }
};