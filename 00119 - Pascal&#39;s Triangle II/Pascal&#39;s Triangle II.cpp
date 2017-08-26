class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex == 0)
        {
            result.push_back(1);
            return result;
        }
        else
        {
            vector<int> vec = getRow(rowIndex-1);
            for(int i = 0; i<rowIndex+1; i++)
            {
                result.push_back((i-1<0? 0 : vec[i-1])+ (i+1>rowIndex? 0 : vec[i]));
            }
            return result;
        }
    }
};