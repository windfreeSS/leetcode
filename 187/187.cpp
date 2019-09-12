#include "../all.cpp"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int kown_repeat_len = 0;
        int s_len = s.size();
        vector<string> result;
        int pos = 0;

        while (pos < (s_len - 20))
        {
            int i;
            for ( i = kown_repeat_len; i < 10; ++i)
            {
                if(s[i]!=s[10+i])
                {
                    break;
                }
            }
            if(i==10)
            {
                result.push_back(s.substr(pos,10));
            }
            kown_repeat_len = i-1;
            if(kown_repeat_len<0)
            {
                kown_repeat_len = 0;
            }
            ++pos;
        }
        return result;

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}