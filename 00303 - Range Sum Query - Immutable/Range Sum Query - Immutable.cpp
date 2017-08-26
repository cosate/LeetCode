class NumArray {
public:
    NumArray(vector<int> nums) {
        int s = nums.size();
        if(s != 0)
        {
            accu.resize(s);
            accu[0] = nums[0];
            for(int i = 1; i < s; i++)
            {
                accu[i] = accu[i-1]+nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return accu[j];
        else
            return accu[j]-accu[i-1];
    }
    vector<int> accu;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */