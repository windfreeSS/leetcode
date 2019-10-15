#include "../all.cpp"

class Solution {
public:

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; ++i)
        {
            if (i > n)
            {
                break;
            }
            int base_num = i;
            int sub_num = 1;
            while (base_num <= n)
            {
                base_num *= 10;
                sub_num *= 10;
            }
            base_num /= 10;
            sub_num /= 10;
            sub_num -= 1;

            for (int sub = 0; sub <= sub_num; ++sub)
            {
                int seq = base_num + sub;
                vector<int> zero_seqs;
                int tmp = seq;
                while(tmp%10==0) //比如碰到19000，则可以分别算出1900,190,19
                {
                    tmp/=10;
                    zero_seqs.push_back(tmp);
                }
                for(int zs =zero_seqs.size()-1;zs>=0;--zs)
                {
                    result.push_back(zero_seqs[zs]);
                }

                if ( seq > n)
                {
                    continue;
                }

                result.push_back(seq);
            }

        }

        return result;
    }
};