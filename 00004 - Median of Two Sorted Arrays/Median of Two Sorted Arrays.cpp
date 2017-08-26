class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if((m+n)%2 != 0)
            return findkth(nums1,0,m,nums2,0,n,(m+n)/2+1);
        else
            return (findkth(nums1,0,m,nums2,0,n,(m+n)/2)+findkth(nums1,0,m,nums2,0,n,(m+n)/2+1))/2;
    }
    
    double findkth(vector<int>& nums1, int s1, int m, vector<int>& nums2, int s2, int n, int k)
    {
        if(m>n)
            return findkth(nums2,s2,n,nums1,s1,m,k);
        if(m == 0)
        {
            return nums2[k-1];
        }
        if(k == 1)
        {
            return min(nums1[s1], nums2[s2]);
        }
        else
        {
            int pa = min(k/2,m);
            int pb = k-pa;
            if(nums1[s1 + pa - 1] < nums2[s2 + pb-1])
            {
                return findkth(nums1,s1+pa,m-pa,nums2,s2,n,k-pa);
            }
            else if(nums1[s1 + pa - 1] > nums2[s2 + pb-1])
            {
                return findkth(nums1,s1,m,nums2,s2+pb,n-pb,k-pb);
            }
            else
            {
                return nums1[s1+pa-1];
            }
        }
    }
};