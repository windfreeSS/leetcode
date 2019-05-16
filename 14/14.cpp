#include <vector>
#include <string>
using namespace std;

[""]
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        if(strs.size()==1)
        {
            return strs[0];
        }

        int fail_i=0;
        int vec_len = strs.size();
        int first_len = strs[0].size();
        bool end_search=false;
        while(true)   
        {
            if(first_len<=fail_i)
            {
                break;
            }
            char first_ch = strs[0][fail_i];
            for(int i=1;i<vec_len;++i)
            {
                if(strs[i][fail_i]!=first_ch)
                {
                    end_search=true;
                    break;
                }
            }
            if(end_search)
            {
                break;
            }
            ++fail_i;
        }
        if(fail_i==0)
        {
            return "";
        }
        return strs[0].substr(0,fail_i);

    }
};



/**
 * https://leetcode-cn.com/problems/longest-common-prefix/
 */