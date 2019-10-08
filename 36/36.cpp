#include "../all.cpp"

// 对 1-9 进行 hash 。然后分别判断 1-9 数字是否重复

typedef pair<int,int> point;
class Solution {
public:
    bool is_dup(vector<point>& ps){
        if(ps.size()>9)
        {
            return true;
        }
        for(int i=0;i<ps.size();++i)
        {
            for(int j=i+1;j<ps.size();++j)
            {
                // same row 
                if(ps[i].first==ps[j].first)
                {
                    return true;
                }
                // same col
                if(ps[i].second==ps[j].second)
                {
                    return true;
                }
                // same cell
                if( ps[i].first/3 == ps[j].first/3
                    && ps[i].second/3 == ps[j].second/3
                    )
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<point>> num_hist(9);
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }
                num_hist[board[i][j]-'1'].push_back(make_pair(i,j));
            }
        }

        for(int i=0;i<9;++i)
        {
            if(is_dup(num_hist[i]))
            {
                return false;
            }
        }

        return true;               
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


