#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool match_bracket(char left,char right)
    {
        switch(right)
        {
            case ')':
            return left=='(';
            case ']':
            return left=='[';
            case '}':
            return left=='{';
        }
        return false;
    }
    bool isValid(string s) {
        if(s.empty())
        {
            return true;
        }
        string valid_str;
        for(int i=0;i<s.size();++i)
        {
            int valid_size = valid_str.size();
            if(valid_size==0)
            {
                valid_str += s[i];
                continue;
            }
            if(match_bracket(valid_str[valid_size-1],s[i]))
            {
                valid_str.pop_back();
            }
            else
            {
                valid_str.push_back(s[i]);
            }

        }
        return valid_str.empty();

    }
};

int main()
{
    Solution s;
    cout<<s.isValid("()[")<<endl;
}