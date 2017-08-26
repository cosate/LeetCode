class Solution {
public:
    int calculate(string s) {
        int len = s.length();
		int i = 0;
		map<string, int> priority;
		priority["*"] = 2;
		priority["/"] = 2;
		priority["+"] = 1;
		priority["-"] = 1;
		vector<string> repo;
		stack<string> oper;
		while (i < len)
		{
			if (s[i] != ' ')
			{
				if (s[i] >= 48 && s[i] <= 57)
				{
					int begin = i;
					while (s[i] >= 48 && s[i] <= 57)
					{
						i++;
					}
					repo.push_back(s.substr(begin, i - begin));
				}
				else
				{
					while (!oper.empty() && priority[s.substr(i, 1)] <= priority[oper.top()])
					{
						repo.push_back(oper.top());
						oper.pop();
					}
					oper.push(s.substr(i, 1));
					i++;
				}
			}
			else
				i++;
		}
		while (!oper.empty())
		{
			repo.push_back(oper.top());
			oper.pop();
		}
		return calrepoland(repo);
	}

	int calrepoland(vector<string>& repoland)
	{
		stack<int> cal;
		for (int i = 0; i < repoland.size(); i++)
		{
			if (repoland[i][0] >= 48)
			{
				cal.push(itos(repoland[i]));
			}
			else
			{
				int n2 = cal.top();
				cal.pop();
				int n1 = cal.top();
				cal.pop();
				int res = 0;
				if (repoland[i] == "+")
					res = n1 + n2;
				else if (repoland[i] == "-")
					res = n1 - n2;
				else if (repoland[i] == "*")
					res = n1 * n2;
				else
					res = n1 / n2;
				cal.push(res);
			}
		}
		return cal.top();
	}

	int itos(string s)
	{
		int res = 0;
		for (int i = 0; i < s.length(); i++)
		{
			res = res * 10 + s[i] - 48;
		}
		return res;
	}
};