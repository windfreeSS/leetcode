#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        vector<int> vals;

        while(m>0)
        {
            if(m==n && (m&0x01))
            {
                vals.push_back(1);
            }
            else
            {
                vals.push_back(0);
            }
            m>>=1;
            n>>=1;

        }


        int val = 0;
        for(int i=vals.size()-1;i>=0;--i)
        {
            val <<=1;
            val += vals[i];
        }
        return val;
    }
};

int main()
{
    Solution s;
    cout<<s.rangeBitwiseAnd(100,100)<<endl;
}