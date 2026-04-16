class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size(), sz = nums.size();
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); i++){
            indices[nums[i]].push_back(i);
        }
        for (auto& pair : indices){
            auto arr = pair.second;
            int m = arr.size();
            if (m == 1){
                nums[arr[0]] = -1;
                continue;
            }
            for (int i = 0; i < m; i++){
                int f = arr[(i + 1) % m], b = arr[(i - 1 + m) % m];
                int forward = min(sz - arr[i] + f, abs(arr[i] - f));
                int backward = min(abs(b - arr[i]), arr[i] + sz - b);
                nums[arr[i]] = min(backward, forward);
            }
        }
        for (int i = 0; i < n; i++)
            queries[i] = nums[queries[i]];
        return queries;
    }
};