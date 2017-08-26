class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cn = g.size();
        int cs = s.size();
        vector<bool> as(cs);
        for(int i = 0; i<cs; i++)
        {
            as[i] = false;
        }
        for(int i = 0; i<cn; i++)
        {
            int re = INT_MAX;
            int index = -1;
            for(int j = 0; j<cs; j++)
            {
                int k = s[j]-g[i];
                if(k >= 0 && k < re && as[j] == false)
                {
                    re = k;
                    index = j;
                }
            }
            if(index>-1 && index<cs)
                as[index] = true;
        }
        int res = 0;
        for(int i = 0; i<cs; i++)
        {
            if(as[i] == true)
                res++;
        }
        return res;
    }
};