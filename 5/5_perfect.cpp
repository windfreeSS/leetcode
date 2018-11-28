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
       
    }
};

int main(int argc, char const *argv[])
{
    string str = "babad";
    Solution ss;
    cout<<ss.longestPalindrome(str);
    return 0;
}