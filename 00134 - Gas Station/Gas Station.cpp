class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int  n = gas.size();
        if(n < 1)
            return -1;
        int sum = 0;
        int total = 0;
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            sum += gas[i]-cost[i];
            total += gas[i]-cost[i];
            if(sum < 0)
            {
                sum = 0;
                j = i+1;
            }
        }
        if(total < 0)
            return -1;
        return j;
    }
};