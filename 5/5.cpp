#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(const std::string& s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int max_len = 1;
        int start_pos = 0;
        int str_len = s.size();

        for (int i = 0; i < str_len; ++i)
        {
            char edge_ch = s[i];
            size_t next_ch_pos = s.find(edge_ch, i+1);
            while (next_ch_pos != string::npos)
            {

                if(isPalindrome(s,i,next_ch_pos))
                {
                    int new_len = next_ch_pos-i+1;
                    if(new_len>max_len)
                    {
                        max_len = new_len;
                        start_pos = i;
                    }
                }
                next_ch_pos = s.find(edge_ch,next_ch_pos+1);
                
            }
        }
        return s.substr(start_pos,max_len);
    }
};

int main(int argc, char const *argv[])
{
    string str = "babad";
    Solution ss;
    cout<<ss.longestPalindrome(str);
    return 0;
}