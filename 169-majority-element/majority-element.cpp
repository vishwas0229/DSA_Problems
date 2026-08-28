class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            int key = nums[i];
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == key)
                    count++;
            }
            if (count > nums.size() / 2)
                return nums[i];
        }
        return {};
    }
};