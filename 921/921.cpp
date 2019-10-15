class Solution {
public:
    int minAddToMakeValid(string S) {
        int lb_cnt = 0; // left bracket
        int supply_cnt = 0;
        for(int i=0;i<S.size();++i)
        {
            if(S[i]=='(')
            {
                ++lb_cnt;
            }
            else // )
            {
                if(lb_cnt==0)
                {
                    ++supply_cnt;
                }
                else
                {
                    --lb_cnt;
                }
            }
        }
        supply_cnt += lb_cnt;
        return supply_cnt;
    }
};

// stack