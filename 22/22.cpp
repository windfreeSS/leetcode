// https://leetcode-cn.com/problems/generate-parentheses/
#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
        {
            return vector<string>();
        }
        int str_len = n * 2;
        vector<string> result;

        vector<int> bracket_state(str_len);//0 means left bracket and 1 means right bracket

        char* bracket_str = new char[str_len + 1];
        if (bracket_str == 0)
        {
            return vector<string>();
        }
        memset(bracket_str, 0, str_len + 1);

        int explore_i = 1;
        bracket_str[0] = '(';
        int need_right_count = 1;

        while (true)
        {
            if (explore_i == 0)
            {
                break;
            }
            if (explore_i == str_len)
            {
                if (need_right_count == 0)
                {
                    result.push_back(bracket_str);
                }
                --explore_i;
                continue;
            }

            if (bracket_state[explore_i] > 1)
            {
                if(bracket_str[explore_i]==')')
                {
                     ++need_right_count;
                }
                else
                {
                    --need_right_count;
                }
                bracket_state[explore_i] = 0;
                --explore_i;
                continue;
            }
            if(need_right_count<0)
            {
                --explore_i;
                continue;
            }

            if(bracket_state[explore_i]==0)
            {
                 ++bracket_state[explore_i];
                 bracket_str[explore_i]='(';
                 ++need_right_count;
                 ++explore_i;
            }
            else //state ==1
            {
                if(need_right_count==0)
                {
                    ++bracket_state[explore_i];
                    continue;
                }
                ++bracket_state[explore_i];
                bracket_str[explore_i]=')';
                need_right_count-=2;
                ++explore_i;
            }

            
        }
        delete [] bracket_str;
        return result;
    }
};



int main()
{
    Solution s;
    vector<string> result = s.generateParenthesis(3);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }
}

// backtracking