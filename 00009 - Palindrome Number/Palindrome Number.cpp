class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
    		return false;
    	if (x == 0)
    		return true;
    	int base = 1;
    	while (x / base >= 10)
    		base = base * 10;
    	while (x != 0)
    	{
    		int max = x / base;
    		int min = x % 10;
    		if (max != min)
    			return false;
    		x -= max*base;
    		x = x / 10;
    		base = base / 100;
    	}
    	return true;
    }
};