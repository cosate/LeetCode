class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        int bits[60];
        bits[0] = 0;
        for(int i = 1; i<60; i++)
        {
            if(i%2 == 0)
                bits[i] = bits[i/2];
            else
                bits[i] = bits[i-1]+1;
        }
        vector<vector<string>> hour(4);
        vector<vector<string>> minute(6);
        char a[5];
        for(int i = 0; i<12; i++)
        {
            switch(bits[i])
            {
                case 0:
                {
                    sprintf(a,"%d",i);
                    hour[0].push_back((string)a+":");
                    break;
                }
                case 1:
                {
                    sprintf(a,"%d",i);
                    hour[1].push_back((string)a+":");
                    break;
                }
                case 2:
                {
                    sprintf(a,"%d",i);
                    hour[2].push_back((string)a+":");
                    break;
                }
                case 3:
                {
                    sprintf(a,"%d",i);
                    hour[3].push_back((string)a+":");
                    break;
                }
                default:
                    break;
            }
        }
        for(int i = 0; i<60; i++)
        {
            switch(bits[i])
            {
                case 0:
                {
                    sprintf(a,"%02d",i);
                    minute[0].push_back((string)a);
                    break;
                }
                case 1:
                {
                    sprintf(a,"%02d",i);
                    minute[1].push_back((string)a);
                    break;
                }
                case 2:
                {
                    sprintf(a,"%02d",i);
                    minute[2].push_back((string)a);
                    break;
                }
                case 3:
                {
                    sprintf(a,"%02d",i);
                    minute[3].push_back((string)a);
                    break;
                }
                case 4:
                {
                    sprintf(a,"%02d",i);
                    minute[4].push_back((string)a);
                    break;
                }
                case 5:
                {
                    sprintf(a,"%02d",i);
                    minute[5].push_back((string)a);
                    break;
                }
                default:
                    break;
            }
        }
        for(int i = 0; i<=num && i<4; i++)
        {
            if(num-i<6)
            {
                for(int j = 0; j<hour[i].size(); j++)
                {
                    for(int k = 0; k<minute[num-i].size(); k++)
                    {
                        string s = hour[i][j] + minute[num-i][k];
                        res.push_back(s);
                    }
                }
            }
        }
        return res;
    }
};