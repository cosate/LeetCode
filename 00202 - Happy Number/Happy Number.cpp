class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        do
        {
            int temp = 0;
            while(n != 0)
            {
                temp += ((n%10)*(n%10));
                n = n/10;
            }
            if(s.count(temp))
                break;
            else
            {
                s.insert(temp);
                n = temp;
            }
        }while(n != 1);
        if(n == 1)
            return true;
        else
            return false;
    }
};