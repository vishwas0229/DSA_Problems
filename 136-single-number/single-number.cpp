class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleOne = 0;
        for (int val : nums) {
            singleOne ^= val;
        }
        return singleOne;
    }
};