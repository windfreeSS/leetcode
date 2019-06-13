#include "../all.cpp"

class Solution {
public:
    void generate_comb(int n,int k,int pos ,vector<int>&data,vector<vector<int>>& result,int start)
    {
        if(pos==k)
        {
            result.push_back(data);
            return ;
        }
        for(int i=start;i<=(n-k+1+pos);++i)
        {
            data[pos]=i;
            generate_comb(n,k,pos+1,data,result,i+1);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> data(k,0);
        generate_comb(n,k,0,data,result,1);
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> result  =s.combine(10,3);
    for(int i=0;i<result.size();++i)
    {
        print(result[i]);
    }
}