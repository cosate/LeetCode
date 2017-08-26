class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res(2);
        int i = 1;
        int j = area;
        int width = i, length = j;
        while(i<j)
        {
            if(i*j == area)
            {
                res[0] = j;
                res[1] = i;
                i++;
                j--;
            }
            else if(i*j > area)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        if(i == j && i*j == area)
        {
            res[0] = i;
            res[1] = i;
        }
        return res;
    }
};