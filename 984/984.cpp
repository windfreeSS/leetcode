#include "../all.cpp"

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char chs[300];
        memset(chs,'\0',300);
        int pos=0;
        while(A>0 && B>0)
        {
            if(A>B)
            {
                chs[pos]='a';
                chs[pos+1]='a';
                chs[pos+2]='b';
                pos+=3;
                A-=2;
                --B;
            }
            else if(A<B)
            {
                chs[pos]='b';
                chs[pos+1]='b';
                chs[pos+2]='a';
                pos+=3;
                B-=2;
                --A;
            }
            else
            {
                while(A>0)
                {
                    chs[pos]='a';
                    chs[pos+1]='b';
                    pos+=2;
                    --A;
                    --B;
                }
                break;
            }
        }
        while(A>0)
        {
            chs[pos]='a';
            ++pos;
            --A;
        }
        while(B>0)
        {
            chs[pos]='b';
            ++pos;
            --B;
        }

        return chs;

    }
};

int main()
{
    Solution s;
    cout<<s.strWithout3a3b(1,2)<<endl;
}