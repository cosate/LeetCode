class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.length();
		int len2 = num2.length();
		vector<string> vec;
		int i = 0;
		while (i < len1)
		{
			string tmp = multiply1digit(num2, num1[len1 - 1 - i]);
			tmp.insert(tmp.length(), i, '0');
			vec.push_back(tmp);
			i++;
		}
		return add(vec, 0, vec.size() - 1);
	}

	string add(vector<string>& nums, int begin, int end)
	{
		if (begin > end)
			return "0";
		else if (begin == end)
			return nums[begin];
		else
		{
			return add2strings(add(nums, begin, begin + (end - begin) / 2), add(nums, begin + (end - begin) / 2 + 1, end));
		}
	}

	string add2strings(string num1, string num2)
	{
		int len1 = num1.length();
		int len2 = num2.length();
		if (len1 > len2)
			return add2strings(num2, num1);

		int i = 0;
		string res;
		int addin = 0;
		int x = 0;
		num1.insert(0, len2 - len1, '0');
		while (i < len2)
		{
			x = (num1[len2 - 1 - i] - 48 + num2[len2 - 1 - i] - 48 + addin) % 10;
			addin = (num1[len2 - 1 - i] - 48 + num2[len2 - 1 - i] - 48 + addin) / 10;
			if (res.length() == 0)
				res += (char)(x + 48);
			else
				res.insert(0, 1, (char)(x + 48));
			i++;
		}
		if (addin != 0)
		{
			if (res.length() == 0)
				res += (char)(addin + 48);
			else
				res.insert(0, 1, (char)(addin + 48));
		}
		return res;
	}

	string multiply1digit(string num, char m)
	{
		int k = m - 48;
		vector<string> vec(k, num);
		return add(vec, 0, k - 1);
	}
};