#include "../all.cpp"

class Solution {
public:
    void back_traking(vector<int>& state,int depth,int N,int& sum)
    {
        if(depth>N)
        {
            ++sum;
            return ;
        }
        for(int i=0;i<N;++i)
        {
            if(state[i]==1)
            {
                continue;
            }
            if( ((i+1)%depth==0) || (depth%(i+1)==0) )
            {
                state[i]=1;
                back_traking(state,depth+1,N,sum);
                state[i]=0;

            }
        }
    }

    int countArrangement(int N) {
        int count =0;
        vector<int> state(N,0);
        back_traking(state,1,N,count);
        return count;
    }
};

int main()
{
    Solution s;
    cout<<s.countArrangement(15)<<endl;
    return 0;
}