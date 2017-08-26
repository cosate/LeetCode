class Solution {
public:
    int countPrimes(int n) {
        n--;
        if (n < 2)
			return 0;
		int result = 0;
		bool * vec = new bool[n+1];
		for (int i = 0; i <= n; i++)
		{
			vec[i] = false;
		}
		for (int i = 2; i*i <= n; i++)
		{
			if (vec[i] == false)
			{
				for (int j = i; i*j <= n; j++)
				{
					vec[i*j] = true;
				}
			}
		}
		for (int s = 0; s <= n; s++)
		{
			if (vec[s] == false)
			{
				result++;
			}
		}
		return result-2;
    }
};