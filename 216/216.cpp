#include "../all.cpp"


// 回溯

class Solution {
    vector<vector<int>> result;
    vector<int> curr;
public:
    // start 用于保证不重复，升序
    void back_track(int k,int n,vector<bool>&flag,int start)
    {
        if(k==0)
        {
            if(n==0)
            {
                result.push_back(curr);
            }
            return ;
        }

        for(int i=start;i<10;++i)
        {
            if(flag[i])
            {
                continue;
            }
            flag[i]=true;
            curr.push_back(i);
            back_track(k-1,n-i,flag,i+1);
            curr.pop_back();
            flag[i]=false;

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        curr.clear();
        if (k > 9 || k<=0)
        {
            return result;
        }

        vector<bool> flag(10,false);

        back_track(k,n,flag,1);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}