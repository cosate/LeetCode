class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
        if(n%2 ==1)
        {
            for(int s = 0; s<n/2; s++)
            {
                int temp = matrix[s][n/2];
                matrix[s][n/2] = matrix[n/2][s];
                matrix[n/2][s] = matrix[n-1-s][n/2];
                matrix[n-1-s][n/2] = matrix[n/2][n-1-s];
                matrix[n/2][n-1-s] = temp;
            }
        }
    }
};