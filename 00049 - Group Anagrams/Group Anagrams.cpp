class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> vec = strs;
        for(int i = 0; i < vec.size(); i++)
        {
            sort(vec[i].begin(), vec[i].end());
        }
        
        map<string, int> mm;
        for(int i = 0; i < strs.size(); i++)
        {
            if(mm.count(vec[i]) == 0)
            {
                mm[vec[i]] = res.size();
                vector<string> newvec;
                newvec.push_back(strs[i]);
                res.push_back(newvec);
            }
            else
            {
                res[mm[vec[i]]].push_back(strs[i]);
            }
        }
        return res;
    }
};