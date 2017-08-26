class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        int count = 0;
        for(int i = 0; i < len; i++)
        {
            if(count == 0)
            {
                if(data[i]>>5 == 6)
                    count = 1;
                else if(data[i]>>4 == 14)
                    count = 2;
                else if(data[i]>>3 == 30)
                    count = 3;
                else if((data[i]&128) != 0)
                    return false;
            }
            else
            {
                if(data[i]>>6 == 2)
                    count--;
                else
                    return false;
            }
        }
        if(count == 0)
            return true;
        else
            return false;
    }
};