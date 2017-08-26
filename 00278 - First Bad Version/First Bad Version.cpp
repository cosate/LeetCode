// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return find(n,1,n);
    }
    
    int find(int n, int begin, int end)
    {
        while(begin<end)
        {
            int mid = begin+(end-begin)/2;
            if(isBadVersion(mid) == true)
                end = mid;
            else
                begin = mid+1;
        }
        return begin;
    }
};