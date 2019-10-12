#include "../all.cpp"

class Solution {
public:
    struct WordInfo
    {
        long long len;
        int flag;
    };
    int maxProduct(vector<string>& words) {
        vector<int> bases = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864};
        int n = words.size();
        if(n<2)
        {
            return 0;
        }
        vector<WordInfo> vw;
        for(int i=0;i<n;++i)
        {
            WordInfo wi={};
            wi.len = words[i].size();
            wi.flag = 0;
            for(int j=0;j<words[i].size();++j)
            {
                wi.flag |= bases[words[i][j]-'a'];
            }
            vw.push_back(wi);
        }

        long long ret = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if( (vw[i].flag^vw[j].flag) !=( vw[i].flag+vw[j].flag) )
                {
                    continue;
                }
                long long mul = vw[i].len * vw[j].len;
                if(mul>ret)
                {
                    ret = mul;
                }
            }
        }
        return ret;


    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}