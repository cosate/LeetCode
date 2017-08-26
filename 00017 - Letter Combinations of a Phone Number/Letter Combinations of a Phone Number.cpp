class Solution {
public:
 map<char, vector<char>> data;
 void setmap()
 {
    		vector<char> vec1;
    
    		vector<char> vec2;
    		vec2.push_back('a');
    		vec2.push_back('b');
    		vec2.push_back('c');
    
    		vector<char> vec3;
    		vec3.push_back('d');
    		vec3.push_back('e');
    		vec3.push_back('f');
    
    		vector<char> vec4;
    		vec4.push_back('g');
    		vec4.push_back('h');
    		vec4.push_back('i');
    
    		vector<char> vec5;
    		vec5.push_back('j');
    		vec5.push_back('k');
    		vec5.push_back('l');
    
    		vector<char> vec6;
    		vec6.push_back('m');
    		vec6.push_back('n');
    		vec6.push_back('o');
    
    		vector<char> vec7;
    		vec7.push_back('p');
    		vec7.push_back('q');
    		vec7.push_back('r');
    		vec7.push_back('s');
    
    		vector<char> vec8;
    		vec8.push_back('t');
    		vec8.push_back('u');
    		vec8.push_back('v');
    
    		vector<char> vec9;
    		vec9.push_back('w');
    		vec9.push_back('x');
    		vec9.push_back('y');
    		vec9.push_back('z');
    
    
    		data.insert(pair<char, vector<char>>('2', vec2));
    		data.insert(pair<char, vector<char>>('3', vec3));
    		data.insert(pair<char, vector<char>>('4', vec4));
    		data.insert(pair<char, vector<char>>('5', vec5));
    		data.insert(pair<char, vector<char>>('6', vec6));
    		data.insert(pair<char, vector<char>>('7', vec7));
    		data.insert(pair<char, vector<char>>('8', vec8));
    		data.insert(pair<char, vector<char>>('9', vec9));
    	}
    	vector<string> letterCombinations(string digits)
    	{
    		setmap();
    		vector<string> result;
    		result = test(digits.size(), digits);
    		return result;
    	}
    	vector<string> test(int depth,string digits)
    	{
    		vector<string> result;
    		if(depth == 0)
    		{return result;}
    		else if (depth == 1)
    		{
    			for (int i = 0; i < data[digits[0]].size(); i++)
    			{
    				string str = "";
    				str += data[digits[0]][i];
    				result.push_back(str);
    			}
    			return result;
    		}
    		else
    		{
    			char last = digits[depth-1];
    			//string newdigit = digits.substr(1);
    			vector<string> temp = test(depth - 1, digits);
    			int x = temp.size();
    			for (int i = 0; i < x; i++)
    			{
    				for (int j = 0; j < data[last].size()-1; j++)
    				{
    					string str = temp[i] + data[last][j];
    					temp.push_back(str);
    				}
    				temp[i] += data[last][data[last].size() - 1];
    			}
    			return temp;
    		}
    	}
};