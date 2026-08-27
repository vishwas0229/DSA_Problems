class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (int val : nums) {
            single = single ^ val;
        }
        return single;
    }
};