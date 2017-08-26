class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int locs[256];
	int max = 0;
	int currenthead = -1;
	memset(locs, -1, sizeof(locs));
	for (int i = 0; i < s.size(); i++)
	{
		if (locs[s[i]] > currenthead)
		{
			currenthead = locs[s[i]];
		}
		if (i - currenthead > max)
		{
			max = i - currenthead;
		}
		locs[s[i]] = i;
	}
	return max;
    }
};