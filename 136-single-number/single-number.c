int singleNumber(int* nums, int numsSize) {
    int sn = 0;
    for (int i = 0; i < numsSize; i++) {
        sn ^= nums[i];
    }
    return sn;
}