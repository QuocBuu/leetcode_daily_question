class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> hardmap;
        for (int i = 0; i < arr.size(); i++) {
            hardmap[arr[i]].emplace_back(i);
        }

        queue<int> q;
        q.push(0);
        vector<int> minStep(arr.size());

        while (!q.empty()) {
            int k = q.front(); 
            q.pop();

            if (k == arr.size() -1) {
                return minStep[k];
            }

            vector<int>& list = hardmap[arr[k]];

            list.emplace_back(k - 1), list.emplace_back(k + 1);
            for (const auto &i : list) {
                if (i > 0 && i < arr.size() && !minStep[i]) {
                    minStep[i] = 1 + minStep[k];
                    q.push(i);
                }
            }

            list.clear();
        }
        return -1;
    }
};