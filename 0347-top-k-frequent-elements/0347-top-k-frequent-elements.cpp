class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // buckets[i] = elements appearing i times
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        vector<int> result;

        // Traverse from highest frequency to lowest
        for (int count = nums.size(); count >= 1; count--) {
            for (int num : buckets[count]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
