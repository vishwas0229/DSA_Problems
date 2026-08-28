int singleNumber(int* nums, int numsSize) {
    int singleOne = 0;
    for (int i = 0; i < numsSize; i++) {
        singleOne ^= nums[i];
    }
    return singleOne;
}