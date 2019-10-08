#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 仍然使用 字典序法 生成全排列
// 可以有优化方案的，比如根据k的值，判断从哪里计算比较好，如果k较大，则不从12345开始，而是直接从13245，直接跳过了很多可能
class Solution {
public:

    string getPermutation(int n, int k) {
        string curr_str;
        for (int i = 0; i < n; i++)
        {
            curr_str += i + 1 + '0';
        }

        while (--k > 0)
        {
            int first_less = -1;
            for (int i = n - 2; i >= 0; --i)
            {
                if (curr_str[i] < curr_str[i + 1])
                {
                    first_less = i;
                    break;
                }
            }
            if (first_less == -1)
            {
                break;
            }

            int bigger_pos = -1;
            for (int i = n - 1; i > first_less; --i)
            {
                if (curr_str[i] > curr_str[first_less])
                {
                    bigger_pos = i;
                    break;
                }
            }
            // swap less
            char temp = curr_str[first_less];
            curr_str[first_less] = curr_str[bigger_pos];
            curr_str[bigger_pos] = temp;

            // swap range
            int exch_left =  first_less + 1;
            int exch_right = n - 1;
            while (exch_left < exch_right)
            {
                temp = curr_str[exch_left];
                curr_str[exch_left] = curr_str[exch_right];
                curr_str[exch_right] = temp;
                ++exch_left;
                --exch_right;
            }
        }
        return curr_str;
    }


};


int main()
{

}