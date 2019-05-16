#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        int str_len = s.size();
        if (str_len <= numRows || numRows==1)
        {
            return s;
        }
        string z_str;
        //first line
        for (int veh_pos = 0; veh_pos < str_len;)
        {
            z_str += s[veh_pos];
            veh_pos += 2 * numRows - 2;
        }

        for (int line = 1; line < numRows - 1; ++line)
        {   //output line by line
            size_t veh_pos = line;
            size_t slash_pos = 2 * numRows - 2 - line;
            bool is_veh = true;
            while (true)
            {
                if (is_veh)
                {
                    is_veh = false;
                    if(veh_pos>=str_len)
                    {
                        break;
                    }
                    z_str+=s[veh_pos];
                    veh_pos+=2 * numRows - 2;
                }
                else
                {
                    is_veh = true;
                    if(slash_pos>=str_len)
                    {
                        break;
                    }
                    z_str+=s[slash_pos];
                    slash_pos+=2*numRows-2;
                }
            }


        }

        //last line
        for (int veh_pos = numRows - 1; veh_pos < str_len;)
        {
            z_str += s[veh_pos];
            veh_pos += 2 * numRows - 2;
        }
        return z_str;
    }
};
int main()
{
    Solution s;
    cout<<s.convert("LEETCODEISHIRING",3)<<endl;
}


// https://leetcode-cn.com/problems/zigzag-conversion/
// Calculated vertical number and slash number separately