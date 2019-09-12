#include "../all.cpp"
using namespace std;


class Solution {
public:
    vector<string> split_with_nozero(string&str)
    {
        vector<string> result;
        size_t start = 0 ;
        while (true)
        {
            size_t pos = str.find('.', start);
            if (pos == string::npos)
            {
                pos = str.find_first_not_of('0', start);
                if (pos != string::npos)
                {
                    result.push_back(str.substr(pos));
                }
                break;
            }

            size_t tmp_pos = str.find_first_not_of('0', start);
            if (tmp_pos >= pos)
            {
                result.push_back("");
            }
            else
            {
                result.push_back(str.substr(tmp_pos, pos - tmp_pos));
            }
            start = pos + 1;
        }

        //remove zero 
        while(result.size() > 0 && result[result.size()-1]=="")
        {
            result.pop_back();
        }
        return result;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1_strs = split_with_nozero(version1);
        vector<string> v2_strs = split_with_nozero(version2);

        size_t v1_size = v1_strs.size();
        size_t v2_size = v2_strs.size();
        size_t v1_pos = 0 ;
        size_t v2_pos = 0 ;

        while (true)
        {
            if (v1_pos == v1_size
                    && v2_pos == v2_size)
            {
                return 0;
            }
            else if (v1_pos == v1_size)
            {
                return -1;
            }
            else if (v2_pos == v2_size)
            {
                return 1;
            }
            if (v1_strs[v1_pos] != v2_strs[v2_pos])
            {
                size_t v1_len = v1_strs[v1_pos].size();
                size_t v2_len = v2_strs[v2_pos].size();
                size_t max_len = max(v1_len,v2_len);
                string v1(max_len,'0');
                string v2(max_len,'0');
                v1.replace(max_len-v1_len,v1_len,v1_strs[v1_pos]);
                v2.replace(max_len-v2_len,v2_len,v2_strs[v2_pos]);
                if(v1<v2)
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }


            ++v1_pos;
            ++v2_pos;
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}