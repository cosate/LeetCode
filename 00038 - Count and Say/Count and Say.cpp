class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)
            return NULL;
            else if(n == 1)
                return "1";
        string before = countAndSay(n-1);
        int *record = new int [before.length()]();
        int current = 0;
        record[0] = 1;
        string result;
        for(int i = 1; i<before.length();i++)
        {
            if(before[current] != before[i])
            {
                current = i;
            }
            record[current]++;
        }
        for(int j = 0; j<before.length();j++)
        {
            if(record[j] != 0)
            {
                string str = to_string(record[j]);
                result.append(str);
                result.append(1,before[j]);
            }
        }
        return result;
    }
};