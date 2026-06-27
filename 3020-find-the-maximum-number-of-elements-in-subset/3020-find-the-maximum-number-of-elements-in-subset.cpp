class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ret = 0;
        unordered_map<long long, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]]++;
        }

        ret = hash_map[1];
        if (ret % 2 == 0) {
            // printf("sdd");
            ret--;
        }
        hash_map.erase(1);

        for (auto& [num, cnt] : hash_map) {
            long long x = num;
            int sum = 0;
            for (; hash_map.contains(x) && hash_map[x] > 1; x *= x) {
                sum += 2;
            }
            ret = max(ret, sum + (hash_map.contains(x) ? 1 : -1));
        }

        return ret;
    }
};