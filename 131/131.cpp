#include "../all.cpp"




class Solution {
private:
    vector<vector<string>>  result;
    vector<string> curr;
public:
    bool is_palindrome(const string&s, const int& start, const int& end )
    {
        size_t h_len = (end-start) / 2;
        for (size_t i = 0; i < h_len; ++i)
        {
            if (s[i + start] != s[end - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    void backtrack_part(const string& s, int parted_len)
    {
        if (parted_len >= s.size())
        {
            result.push_back(curr);
            return ;
        }

        for (int i = 1; i <= (s.size() - parted_len); ++i)
        {
            if (!is_palindrome(s, parted_len, i + parted_len))
            {
                continue;
            }
            curr.push_back(s.substr(parted_len, i));
            backtrack_part(s, parted_len + i);
            curr.pop_back();

        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        curr.clear();
        backtrack_part(s, 0);
        return result;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> result = s.partition("aaabcdaaa");
    for (int i = 0; i < result.size(); ++i)
    {
        print(result[i]);
    }
    return 0;
}

// 使用回溯法，依次改变字符的长度