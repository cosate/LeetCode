class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        if((num&(num-1)) != 0)
            return false;
        else
        {
            if((num-1)%3 == 0)
                return true;
            else
                return false;
        }
            
    }
};