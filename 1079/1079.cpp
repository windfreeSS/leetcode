

class Solution {
    int result;
    vector<int> facts;
public:
    vector<int>  calc_fact()
    {   //计算阶乘
        vector<int> ret(8);
        ret[1] = 1;
        for (int i = 2; i < 8; ++i)
        {
            ret[i] = ret[i - 1] * i;
        }
        facts = ret;
        return ret;
    }
    void select_comb(vector<int>& datas, int pos, vector<int>&select_state)
    {
        if (pos == datas.size())
        {
            //calc
            int ch_cnts=0;
            int sub_comb=1;
            for(int i=0;i<select_state.size();++i)
            {
                if(select_state[i]==0)
                {
                    continue;
                }
                ch_cnts += select_state[i];
                sub_comb *= facts[select_state[i]];
            }
            result += facts[ch_cnts] / sub_comb;
            return ;
        }

        for (select_state[pos] = 0; select_state[pos] <= datas[pos]; ++select_state[pos])
        {
            select_comb(datas,pos+1,select_state);
        }
    }
    int numTilePossibilities(string tiles) {
        result = 0;
        calc_fact();
        vector<int> ch_cnt(26, 0);
        int n = tiles.size();
        for (int i = 0; i < n; ++i)
        {
            ++ch_cnt[tiles[i] - 'A'];
        }

        vector<int> ch_dists;
        for (int i = 0; i < 26; ++i)
        {
            if (ch_cnt[i] == 0)
            {
                continue;
            }
            ch_dists.push_back(ch_cnt[i]);
        }

        vector<int> selected(ch_dists.size(), 0);

        select_comb(ch_dists, 0, selected);

        return result;
    }

};