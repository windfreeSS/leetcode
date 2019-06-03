#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int a_len = a.size();
        int b_len = b.size();
        int min_len = a_len;
        int max_len = b_len;
        if(min_len>b_len)
        {
        	min_len = b_len;
        	max_len = a_len;
        }
     	char* chs = new char[max_len+2];
     	chs[max_len+1]='\0';

     	static char add_table[]={'0','1','0','1','0'};
     	static int carry_table[]={0,0,1,1};
     	for(int i=0;i<min_len;++i)
     	{
     		carry = (a[a_len-i-1]-'0') + (b[b_len-i-1]-'0') + carry;
     		chs[max_len-i]=add_table[carry];
     		carry = carry_table[carry];
     	}

     	for(int i=min_len;i<a_len;++i)
     	{
     		carry = (a[a_len-i-1]-'0') + carry;
     		chs[max_len-i]=add_table[carry];
     		carry = carry_table[carry];
     	}
     	for(int i=min_len;i<b_len;++i)
     	{
     		carry = (b[b_len-i-1]-'0') + carry;
     		chs[max_len-i]=add_table[carry];
     		carry = carry_table[carry];
     	}
     	string result;
     	if(carry==1)
     	{
     		chs[0]='1';
     		result = chs;
     	}
     	else
     	{
     		result =chs+1;
     	}
     	delete [] chs;
     	return result;

    }
};

int main()
{
	Solution s;
	cout<<s.addBinary("0111","1111")<<endl;
}