class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int sum = 0;

        for(int row = 0;row<m;++row)
        {
            for(int col=0;col<n;++col)
            {
                if(board[row][col]=='.')
                {
                    continue;
                }
                if( (col+1)<n && board[row][col+1]=='X' )
                {
                    continue;
                }
                if( (row+1)<m && board[row+1][col]=='X' )
                {
                    continue;
                }
                ++sum;
            }
        }

        return sum;
    }
};