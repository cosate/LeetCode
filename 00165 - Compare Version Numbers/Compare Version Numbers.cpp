class Solution {
public:
    int compareVersion(string version1, string version2) {
        int begin1 = 0;
        int begin2 = 0;
        int len1 = version1.length();
        int len2 = version2.length();
        int i1 = 0;
        int i2 = 0;
        int numofdot1 = 0;
        int numofdot2 = 0;
        for(int i = 0; i <len1; i++)
        {
            if(version1[i] == '.')
                numofdot1++;
        }
        for(int i = 0; i < len2; i++)
        {
            if(version2[i] == '.')
                numofdot2++;
        }
        if(numofdot1 < numofdot2)
        {
            for(int i = 0; i < numofdot2-numofdot1; i++)
                version1 += ".0";
        }
        else if(numofdot2 < numofdot1)
        {
            for(int i = 0; i < numofdot1-numofdot2; i++)
                version2 += ".0";
        }
        len1 = version1.length();
        len2 = version2.length();
        while(i1 < len1 && i2 <len2)
        {
            while(i1 < len1 && version1[i1] != '.')
                i1++;
            while(i2 < len2 && version2[i2] != '.')
                i2++;
            int v1 = getversion(version1, begin1, i1-1);
            int v2 = getversion(version2, begin2, i2-1);
            if(v1 < v2)
                return -1;
            else if(v1 > v2)
                return 1;
            begin1 = i1 + 1;
            begin2 = i2 + 1;
            i1++;
            i2++;
        }
        return 0;
    }
    
    int getversion(string& strs, int begin, int end)
    {
        int res = 0;
        for(int i = begin; i <= end; i++)
        {
            res = res*10 + strs[i]-48;
        }
        return res;
    }
};