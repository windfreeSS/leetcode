#include "../all.cpp"


struct op_token
{
    bool is_operand; //操作数
    int val;
    char ch;

};

class Solution {
private:
    vector<int> calc_result;
public:
    vector<op_token> parse(const string& str)
    {
        vector<op_token> result;
        size_t pos = 0;
        while (str[pos] >= '0' && str[pos] <= '9') ++pos;

        op_token ot ;
        ot.is_operand = true;
        ot.val = atoi(str.substr(0, pos).c_str());
        result.push_back(ot);

        while (pos < str.size())
        {
            ot.is_operand = false;
            ot.ch = str[pos];
            result.push_back(ot);

            ++pos;
            size_t end_pos = pos;
            while (end_pos < str.size() && str[end_pos] >= '0' && str[end_pos] <= '9')
            {
                ++end_pos;
            }

            ot.is_operand = true;
            ot.val = atoi(str.substr(pos, end_pos - pos).c_str());
            result.push_back(ot);
            pos = end_pos;
        }

        return result;

    }

    vector<int> calc(vector<op_token>& tokens, int start, int end,int lvl)
    {
        if (start >= tokens.size())
        {
            return vector<int>();
        }
        if (end == (start + 1))
        {
            vector<int> data;
            data.push_back(tokens[start].val);
            return data;
        }

        vector<int> result;

        for (int i = start; i < end-1; i += 2)
        {
            vector<int> left_rets = calc(tokens, start, i + 1,lvl+1);
            vector<int> right_rets = calc(tokens, i + 2, end,lvl+1);
            if (right_rets.empty())
            {
                result.insert(result.end(), left_rets.begin(), left_rets.end());
                continue;
            }
            for(int l_i =0;l_i<left_rets.size();++l_i)
            {
                for(int r_i=0;r_i<right_rets.size();++r_i)
                {
                    if(tokens[i+1].ch=='*')
                    {
                        result.push_back(left_rets[l_i]*right_rets[r_i]);
                    }
                    else if(tokens[i+1].ch=='-')
                    {
                        result.push_back(left_rets[l_i]-right_rets[r_i]);   
                    }
                    else
                    {
                        result.push_back(left_rets[l_i]+right_rets[r_i]);      
                    }
                }
            }
        }
        return result;
    }

    vector<int> diffWaysToCompute(string input) {

        vector<op_token> tokens = parse(input);

        if(tokens.size()==1)
        {
            calc_result.push_back(tokens[0].val);
            return calc_result;
        }

        for (int i = 0; i < tokens.size()-1; i += 2)
        {
            vector<int> left_rets = calc(tokens, 0, i + 1,0);
            vector<int> right_rets = calc(tokens, i + 2, tokens.size(),0);
            if (right_rets.empty())
            {
                calc_result.insert(calc_result.end(), left_rets.begin(), left_rets.end());
                continue;
            }
            for(int l_i =0;l_i<left_rets.size();++l_i)
            {
                for(int r_i=0;r_i<right_rets.size();++r_i)
                {
                    if(tokens[i+1].ch=='*')
                    {
                        calc_result.push_back(left_rets[l_i]*right_rets[r_i]);
                    }
                    else if(tokens[i+1].ch=='-')
                    {
                        calc_result.push_back(left_rets[l_i]-right_rets[r_i]);   
                    }
                    else
                    {
                        calc_result.push_back(left_rets[l_i]+right_rets[r_i]);      
                    }
                }
            }

        }

        return calc_result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<int> result = s.diffWaysToCompute("2-1-1");
    print(result);
    return 0;
}