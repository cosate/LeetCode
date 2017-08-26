class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int original = m;
        int i =0, j =0;
        while(i<original && j<n)
        {
            if(nums1[i] >= nums2[j])
            {
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
                original++;
            }
            i++;
        }
        if(j<n)
        {
            nums1.insert(nums1.begin()+i,nums2.begin()+j,nums2.end());
        }
        nums1.erase(nums1.begin()+m+n,nums1.end());
    }
};