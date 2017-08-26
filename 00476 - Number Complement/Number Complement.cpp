class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int flag = 1;
        while(temp)
        {
            temp >>= 1;
            flag <<= 1;
        }
        num = num^(flag-1);
        return num;
    }
};