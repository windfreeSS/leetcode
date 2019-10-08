#include "../all.cpp"

// 栈处理
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parents;
        size_t p_len = path.size();

        for (size_t pos = 0; pos < p_len;)
        {
            while (pos < p_len && path[pos] == '/')++pos;
            if (pos == p_len)
            {
                break;
            }
            size_t next_slash = pos;
            while (next_slash < p_len && path[next_slash] != '/')++next_slash;
            string str = path.substr(pos, next_slash - pos);
            pos = next_slash;
            if (str == ".")
            {

            }
            else if (str == "..")
            {
                if (!parents.empty())
                {
                    parents.pop_back();
                }
            }
            else
            {
                parents.push_back(str);
            }
        }
        if(parents.empty())
        {
            return "/";
        }

        string result ;
        for (int i = 0; i < parents.size(); ++i)
        {
            result += "/" + parents[i];
        }

        return result;

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

