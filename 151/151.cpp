#include "../all.cpp"

class Solution {
public:
    void reverse_str(string& s,int begain,int end)
    {
        int half_len = (end-begain)/2;
        for (size_t i = 0; i < half_len; ++i)
        {
            char tmp = s[i+begain];
            s[i+begain] = s[end-i-1];
            s[end-i-1]= tmp;
        }
    }
    string reverseWords(string s) {
        // remove head space 
        size_t pos = s.find_first_not_of(' ');
        if(pos==string::npos)
        {
            return "";
        }
        s.replace(0,pos,"");

        // remove end space 
        pos = s.find_last_not_of(' ');
        if(pos!=(s.size()-1))
        {
            s.erase(pos+1);
        }

        // reverse string 
        reverse_str(s,0,s.size());
        // reverse word
        pos = 0;
        while(pos<s.size())
        {
            size_t space_pos = s.find_first_of(' ',pos);
            if(space_pos==string::npos)
            {
                reverse_str(s,pos,s.size());
                break;
            }
            reverse_str(s,pos,space_pos);

            size_t second_space = space_pos+1;
            while(s[second_space]==' ')
            {
                ++second_space;
            }
            s.replace(space_pos,second_space-space_pos," ");
            pos = space_pos+1;

        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    cout<<s.reverseWords("the sky is blue")<<endl;
    return 0;
}