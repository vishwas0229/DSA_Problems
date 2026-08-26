class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        int temp = x;
        if (x < 0)
            return 0;
        while (temp > 0)
        {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }
        if (rev == x)
            return 1;
        else
            return 0;
    }
};