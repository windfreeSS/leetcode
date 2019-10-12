#include "../all.cpp"


// dp 

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        if (num == 0)
        {
            return ret;
        }
        for (int i = 1; i <= num; ++i)
        {
            if (i % 2 == 1)
            {
                ret[i] = ret[i - 1] + 1;
                continue;
            }
            if( (i^(i-1)) == ((i<<1)-1))
            { //eg (i-1)=0111,(i)=1000
                ret[i]=1;
            }
            else
            {// eg (i-1)=110111(binary),(i)=111000(binary)
                ret[i] = ret[i-1]-ret[i^(i-1)]+2;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> result = s.countBits(100);
    print(result);
}