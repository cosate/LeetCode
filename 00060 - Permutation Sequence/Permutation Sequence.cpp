class Solution {
public:
    string getPermutation(int n, int k) {
        int temp = n;
        int nto1 = 1;
        while(temp > 1)
        {
            nto1 = nto1*temp;
            temp--;
        }
        temp = n;
        vector<int> vectoerase(n+1);
        for(int i = 0; i < n+1; i++)
            vectoerase[i] = i;
        vector<int> vec;
        while(temp >= 1)
        {
            nto1 = nto1/temp;
            vec.push_back(vectoerase[(k-1)/nto1 + 1]);
            vectoerase.erase(vectoerase.begin()+(k-1)/nto1 + 1);
            k = (k-1)%nto1 + 1;
            temp--;
        }
        string res;
        for(int i = 0; i < vec.size(); i++)
        {
            res+=(char)(vec[i]+48);
        }
        return res;
    }
};