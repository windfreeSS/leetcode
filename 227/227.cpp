#include "../all.cpp"

struct calc_token
{
    char op_ch;
    long long op_num;
};

class Solution {
public:
    string get_next_token(const string& s, int& pos)
    {
        while (pos < s.size() && s[pos] == ' ')
        {
            ++pos;
        }
        if (pos == s.size())
        {
            return "";
        }

        if (s[pos] >= '0' && s[pos] <= '9')
        {   //digit
            for (int end = pos + 1; end < s.size(); ++end)
            {
                if (s[end] <'0' || s[end] >'9')
                {
                    string result  = s.substr(pos,end-pos);
                    pos = end;
                    return result;
                }
            }
            string result = s.substr(pos);
            pos = s.size();
            return result;

        }
        else
        {
            ++pos;
            return s.substr(pos - 1, 1);
        }
        return "";
    }

    int calculate(string s) {
        int pos = 0;
        vector<calc_token> calc_tokens;
        string data = get_next_token(s,pos);
        calc_token one;
        one.op_num = atoi(data.c_str());
        calc_tokens.push_back(one);

        while(true)
        {
            data = get_next_token(s,pos);
            if(data.empty())
            {
                break;
            }
            calc_token op_token;
            op_token.op_ch = data[0];
            

            data = get_next_token(s,pos);
            calc_token num_token;
            num_token.op_num = atoi(data.c_str());

            if(op_token.op_ch=='*')
            {
                calc_tokens[calc_tokens.size()-1].op_num = calc_tokens[calc_tokens.size()-1].op_num * num_token.op_num;
            }
            else if(op_token.op_ch=='/')
            {
                calc_tokens[calc_tokens.size()-1].op_num = calc_tokens[calc_tokens.size()-1].op_num / num_token.op_num;
            }
            else
            {
                calc_tokens.push_back(op_token);
                calc_tokens.push_back(num_token);
            }

            
        }

        int calc_pos = 0;
        while(true)
        {
            if(calc_pos >= (calc_tokens.size()-1) )
            {
                break;
            }

            if(calc_tokens[calc_pos+1].op_ch=='-')
            {
                calc_tokens[calc_pos+2].op_num = calc_tokens[calc_pos].op_num - calc_tokens[calc_pos+2].op_num;
            }
            else //calc_tokens[calc_pos+1].op_ch=='+'
            {
                calc_tokens[calc_pos+2].op_num = calc_tokens[calc_pos].op_num + calc_tokens[calc_pos+2].op_num;
            }
            calc_pos+=2;
        }

        return calc_tokens[calc_tokens.size()-1].op_num;
    }
};

int main()
{
    Solution s;
    cout<<s.calculate(" 3+5 / 2 ")<<endl;
}