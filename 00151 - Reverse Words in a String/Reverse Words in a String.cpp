class Solution {
public:
    void reverseWords(string &s) {
		int len = s.length();
		reverse(s, 0, len - 1);
		int start, end;
		for (int i = 0; i<len; i++)
		{
			if (s[i] != ' ')
			{
				start = i;
				int j;
				for (j = i; s[j] != ' ' && j<len; j++) {}
				reverse(s, start, j - 1);
				i = j;
			}
		}
		string temp;
		bool flag = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				flag = true;
				temp = temp + s[i];
			}
			else
			{
				if (flag == true)
				{
					temp = temp + ' ';
					flag = false;
				}
			}
		}
		if (temp[temp.length() - 1] == ' ')
			temp.erase(temp.length() - 1);
		s = temp;
	}

	void reverse(string& s, int begin, int end)
	{
		if (begin <= end)
		{
			int len = end - begin + 1;
			for (int i = 0; i<len / 2; i++)
			{
				char temp = s[begin + i];
				s[begin + i] = s[begin + len - 1 - i];
				s[begin + len - 1 - i] = temp;
			}
		}
	}
};