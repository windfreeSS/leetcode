#include "../all.cpp"

class Solution {
public:
    void spread_k_area(int k ,vector<int>&len ,const string& s,vector<string>&result)
    {
        if(k==3)
        {
            string str1 = s.substr(0,len[0]);
            string str2 = s.substr(len[0],len[1]);
            string str3 = s.substr(len[1],len[2]);
            string str4 = s.substr(len[2]);
        

            return ;

        }

        for(len[k]=1;len[k]<4;++len[k])
        {
            spread_k_area(k+1,len,result);
        }
    }   
    vector<string> restoreIpAddresses(string s) {
        vector<int> len(3);
        vector<string> result;

        if(s.size()> 12)
        {
            return vector<string>();
        }
        spread_k_area(0,len,s,result);

        return result;
    }
};