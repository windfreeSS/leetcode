#include "../all.cpp"

class Solution {
public:
    void spread_k_area(int k ,vector<int>&len ,const string& s,vector<string>&result)
    {
        if(k==3)
        {
            if((len[0]+len[1]+len[2])>=s.size())
            {
                return ;
            }
            string str1 = s.substr(0,len[0]);
            string str2 = s.substr(len[0],len[1]);
            string str3 = s.substr(len[0]+len[1],len[2]);
            string str4 = s.substr(len[0]+len[1]+len[2]);

            if( (str1.size()>1 && str1[0]=='0')
                ||(str2.size()>1 && str2[0]=='0')
                ||(str3.size()>1 && str3[0]=='0')
                ||(str4.size()>1 && str4[0]=='0')
                )
            {
                return ;
            }

            
            if(atoi(str1.c_str())<=255
                &&atoi(str2.c_str())<=255
                &&atoi(str3.c_str())<=255
                &&atoi(str4.c_str())<=255
                )
            {
                result.push_back(str1+"."+str2+"."+str3+"."+str4);
            }

            return ;

        }

        for(len[k]=1;len[k]<4;++len[k])
        {
            spread_k_area(k+1,len,s,result);
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

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<string> result =s.restoreIpAddresses("0000");

    return 0;
}