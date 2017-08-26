class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end(),less<int>());
        int res = 0;
        for(int i = 0; i < houses.size(); i++)
        {
            if(!binary_search(heaters.begin(),heaters.end(),houses[i]))
            {
                auto index = (upper_bound(heaters.begin(),heaters.end(),houses[i])-heaters.begin());
                int right = (index >= heaters.size() ? INT_MAX : heaters[index] - houses[i]);
                int left = (index <= 0 ? INT_MAX : houses[i] - heaters[index-1]);
                res = max(res, min(right,left));
            }
        }
        return res;
    }
};