// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <string>
#include <memory.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int str_len = s.size();
        if (str_len < 2)
        {
            return str_len;
        }

        int latest_occur_map[300];// assume all ascii char
        for(int i=0;i<300;++i)
        {
            latest_occur_map[i]=-1;
        }

        int max_len = 0;
        int observe_left = 0;
        int observe_right = 1;

        while (observe_left < str_len)
        {
            int left_max_len = str_len - observe_left;
            if (left_max_len <= max_len)
            {
                break;
            }
            latest_occur_map[s[observe_left]] = observe_left;

            for (; observe_right < str_len; ++observe_right)
            {
                int latest_occur = latest_occur_map[s[observe_right]];

                if (latest_occur < observe_left)
                {
                    latest_occur_map[s[observe_right]] = observe_right;
                    continue;
                }
                break;
            }
            int curr_len = observe_right - observe_left;
            if (curr_len > max_len)
            {
                max_len = curr_len;
            }

            if(observe_right>=str_len)// end of string
            {
                break;
            }

            observe_left = latest_occur_map[s[observe_right]] + 1;
            latest_occur_map[s[observe_right]] = observe_right;
            ++observe_right;

        }

        return max_len;
    }
};

int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")<<endl;
    // cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
    // cout<<s.lengthOfLongestSubstring("bbbbb")<<endl;
    // cout<<s.lengthOfLongestSubstring("pwwkew")<<endl;
    
}
