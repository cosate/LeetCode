class Solution {
public:
    string simplifyPath(string path) {
        stack<string> sta;
        path = path+"/";
		int len = path.length();
		string temp;
		for (int i = 1; i < len; i++)
		{
			if (path[i] == '/')
			{
				if (temp == "")
					continue;
				else
				{
					if (temp == ".." )
					{
						if (!sta.empty())
						{
							sta.pop();
						}
						temp = "";
					}
					else if (temp == ".")
					{
						temp = "";
						continue;
					}
					else
					{
						sta.push(temp);
						temp = "";
					}
				}
			}
			else
				temp += path[i];
		}
		string res;
		if (sta.empty())
			return "/";
		while (!sta.empty())
		{
			string s = sta.top();
			sta.pop();
			res = "/" + s + res;
		}
		return res;
	}
};