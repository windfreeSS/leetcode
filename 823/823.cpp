#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calcDivisor()
    {
        int div = 1;
        for (int i = 0; i < 9; ++i)
        {
            div *= 10;
        }
        return (div + 7);
    }
    int numFactoredBinaryTrees(vector<int>& A) {
        static int base_num = calcDivisor();
        int a_size = A.size();
        vector<long long> bina_count(a_size, 1);

        // use std sort
        std::sort(A.begin(), A.end());

        // dp
        for (int i = 1; i < a_size; ++i)
        {
            long long as_root_count = 0;
            int begin =0;
            int end =i-1;
            long long big_num;
            while(begin<end)
            {
                big_num = (long long )A[begin] * (long long)A[end];
                if(big_num > A[i])
                {
                    --end;
                }
                else if(big_num < A[i])
                {
                    ++begin;
                }
                else
                {
                    as_root_count +=  2 * bina_count[begin]*bina_count[end];
                    ++begin;
                    --end;
                }
            }

            big_num = (long long)A[begin]*(long long)A[begin];
            if(big_num == A[i])
            {
                as_root_count += bina_count[begin]*bina_count[begin];
            }
            bina_count[i] += as_root_count;
        }

        // calc sum
        long long result = 0;
        for (int i = 0; i < bina_count.size(); ++i)
        {
            result += bina_count[i];
        }

        return (int)(result % base_num);
    }
};

int main()
{
    vector<int> data = {2, 4, 5, 10, 20, 40, 80, 100, 160, 200, 400, 640, 800, 1600, 2000, 4000, 6400, 12800, 16000, 20000, 40000, 64000, 128000, 160000, 256000, 320000, 640000, 1280000, 1600000, 2560000, 3200000, 4096000, 5120000, 6400000, 8000000, 16000000, 20480000, 64000000, 80000000, 81920000, 102400000, 128000000, 160000000, 204800000, 256000000, 409600000, 512000000, 819200000, 1024000000};
    Solution s;
    cout << s.numFactoredBinaryTrees(data) << endl;
}
