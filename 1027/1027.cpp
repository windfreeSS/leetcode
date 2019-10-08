#include "../all.cpp"

struct seq_info
{
    int len;
    int val;
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<seq_info> datas(n);
        
        for(int i=n-2;i>=0;--i)
        {
            seq_info si;
            si.len = 0;
            si.val = 0;
            for(int j=i+1;j<n;++j)
            {
                int tmp_len = 0;
                if(j==(n-1))
                {
                    tmp_len = 2;
                }
                else if( datas[j].val == (A[i]-A[j]) )
                {
                    tmp_len = datas[j].len+1;
                }
                if(tmp_len>si.len)
                {
                    si.len=tmp_len;
                    si.val = A[i]-A[j];
                }
            }
            datas[i] = si;
        }
        int ret = 0;
        for(int i=0;i<n-1;++i)
        {
            if(datas[i].len>ret)
            {
                ret = datas[i].len;
            }
        }
        return ret;
    }
};