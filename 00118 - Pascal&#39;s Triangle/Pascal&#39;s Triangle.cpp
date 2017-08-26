class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
    	if (numRows <= 0)
    		return result;
    	else
    	{
    		vector<int> *vec = new vector<int>();
    		vec->push_back(1);
    		result.push_back(*vec);
    	}
    	vector<int> *vec = NULL;
    	for (int i = 1; i < numRows; i++)
    	{
    		 vec= new vector<int>();
    		for (int j = 0; j < i+1; j++)
    		{
    			int m = j - 1 < 0 ? 0 : result[i - 1][j - 1];
    			int n = j + 1 > i ? 0 : result[i - 1][j];
    			vec->push_back(m+n);
    		}
    		result.push_back(*vec);
    		vec = NULL;
    	}
    	return result;
    }
};