class Solution {
public:
    void unoin_parent(vector<int>& us,int a,int b)
    {
        while(us[a]!=a)
        {
            a = us[a];
        }
        while(us[b]!=b)
        {
            b = us[b];
        }
        us[b] = a;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> us (n);//   union set
        for(int i=0;i<n;++i)
        {
            us[i]=i;
        }
        for(int r = 0;r<n;++r)
        {
            for(int c =r+1;c<n;++c)
            {
                if(M[r][c]==0)
                {
                    continue;
                }
                unoin_parent(us,r,c);
            }
        }

        int result =0;
        for(int i=0;i<n;++i)
        {
            if(us[i]==i)
            {
                ++result;
            }
        }
        return result;

    }
};