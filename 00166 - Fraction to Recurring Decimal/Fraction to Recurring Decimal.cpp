class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
			return "0";
		bool symbol;
		long long num = (long long)numerator;
		long long den = (long long)denominator;
		if (num < 0 && den >0)
		{
			num = 0 - num;
			symbol = false;
		}
		else if (num > 0 && den < 0)
		{
			den = 0 - den;
			symbol = false;
		}
		else if (num < 0 && den < 0)
		{
			num = 0 - num;
			den = 0 - den;
			symbol = true;
		}
		else
			symbol = true;
		string res = "";
		long long integer = num / den;
		res = res + itos(integer);
		long long decimal = num%den;
		if (decimal != 0)
		{
			string temp = "";
			map<long long, int> mm;
			mm[decimal] = 0;
			int i = 1;
			while (decimal != 0)
			{
				temp += (char)((int)((decimal * 10) / den) + 48);
				decimal = (decimal * 10) % den;
				if (mm.count(decimal))
				{
					break;
				}
				else
				{
					mm[decimal] = i;
					i++;
				}
			}
			if (decimal == 0)
			{
				res = res + "." + temp;
			}
			else
			{
				res += ".";
				temp.insert(mm[decimal], "(");
				temp += ")";
				res += temp;
			}
		}
		if (!symbol)
			res.insert(0, "-");
		return res;
	}

	string itos(long long num)
	{
		if (num == 0)
			return "0";
		stack<int> ss;
		string res = "";
		while (num != 0)
		{
			ss.push(num % 10);
			num = num / 10;
		}
		while (!ss.empty())
		{
			res += (char)(ss.top()+48);
			ss.pop();
		}
		return res;
	}
};