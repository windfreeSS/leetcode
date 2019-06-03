#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct reg_token
{
    char ch;
    bool is_any;
    bool is_zeroormore;
    reg_token():is_any(false),is_zeroormore(false)
    {
    }
};
// backtracking

class Solution {
public:
    bool parseTokens(const string& p, vector<reg_token>& tokens)
    {
        for (int i = 0; i < p.size(); ++i)
        {
            if (p[i] == '*')
            {
                continue;
            }
            reg_token rt;
            if (p[i] == '.')
            {
                rt.is_any = true;
            }
            else // a-z
            {
                rt.ch = p[i];
            }
            if ( (i + 1) < p.size() && p[i + 1] == '*' )
            {
                rt.is_zeroormore = true;
            }
            tokens.push_back(rt);
        }
        return true;
    }

    bool matchNextToken(const string&str, const reg_token& token, int& curr_match_len, int str_len, int& token_state)
    {
        if (token.is_zeroormore)
        {
			if(token_state==0)
			{

				++token_state;
				return true;
			}
            else if( (str_len-curr_match_len)< 1 )
            {
                curr_match_len-=token_state-1;
                token_state=0;
                return false;
            }
            else
            {
                if(token_state>0)
                { 
                    if(token.is_any || token.ch == str[curr_match_len])
                    {
                        ++curr_match_len;    
                    }
                    else
                    {
						curr_match_len -= token_state-1;
                        token_state = 0;
                        return false;
                    }
                    
                }
                ++token_state;
                return true;

            }
        }
        else //only one
        {
            if (token_state >= 1)
            {
                --curr_match_len;
                token_state = 0;
                return false;
            }
            if (curr_match_len >= str_len)
            {
                return false;
            }
            if (token.is_any || (token.ch == str[curr_match_len]) )
            {
                token_state = 2;
                ++curr_match_len;
                return true;
            }
            else
            {
                return false;
            }

        }
        return false;
    }

    bool isMatch(string s, string p) {
        // parse token
        vector<reg_token> tokens;
        parseTokens(p, tokens);


        int token_count = tokens.size();
        if (token_count == 0)
        {
            return s.empty();
        }

        vector<int> tokens_state(token_count, 0); //count of token
        int curr_token_pos = 0;
        int match_s_len = 0;
        int s_len = s.size();
        while (true)
        {
            if (curr_token_pos >= token_count)
            {
                if (match_s_len == s_len)
                {
                    return true;
                }
                --curr_token_pos;
                continue;
            }
            if (curr_token_pos == 0)
            {
                if ( tokens[curr_token_pos].is_zeroormore)
                {
                    if (tokens_state[curr_token_pos] > s_len)
                    {
                        return false;
                    }
                }
                else if (tokens_state[curr_token_pos] >= 1)
                {
                    return false;
                }
            }
			else if(curr_token_pos<0)
			{
				return false;
			}

            
            if (matchNextToken(s, tokens[curr_token_pos], match_s_len, s_len, tokens_state[curr_token_pos]))
            {
                ++curr_token_pos;
            }
            else
            {
                --curr_token_pos;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.isMatch("aa","a")<<endl;
}