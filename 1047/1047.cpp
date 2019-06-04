#include <iostream>
#include <string>
#include <memory.h>
using namespace std;


class Solution {
public:
    string removeDuplicates(string S) {
        int s_size = S.size();
        char* tmp_arr = new char[s_size+1];
        int arr_len = 0;
        memset(tmp_arr,0,s_size+1);
        for(int i=0;i<s_size;++i)
        {
            if(arr_len>0)
            {
                if(tmp_arr[arr_len-1] == S[i])
                {
                    --arr_len;
                }
                else
                {
                    tmp_arr[arr_len] = S[i];
                    ++arr_len;
                }
            }
            else
            {
                tmp_arr[arr_len] = S[i];
                ++arr_len;
            }
        }
        tmp_arr[arr_len]='\0';
        string result = string(tmp_arr);

        delete [] tmp_arr;
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.removeDuplicates("abbaca")<<endl;
}