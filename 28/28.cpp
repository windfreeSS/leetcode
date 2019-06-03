#include <vector>
#include <string>
#include <iostream>
using namespace std;

// use kmp string match
class Solution {
public:
	void kmp_next(const string& pattern,vector<int>& next_state)
	{
		int pattern_size = pattern.size();
		int curr_match_pos=-1;
		for( int i=1;i<pattern_size;++i)
		{
			while(curr_match_pos>-1 && pattern[curr_match_pos+1]!=pattern[i])
			{
				curr_match_pos=next_state[curr_match_pos];
			}
			if(pattern[curr_match_pos+1] == pattern[i])
			{
				++curr_match_pos;
			}
			next_state[i]=curr_match_pos;
		}
	}
	int kmp_find(const string& first,const string& second)
	{
		int first_size = first.size();
		int second_size = second.size();
		vector<int> next_state(second_size,-1);
		kmp_next(second,next_state);
		int curr_match_pos = -1;

		for(int i=0;i<first_size;++i)
		{
			while( curr_match_pos>-1 && second[curr_match_pos+1]!=first[i])
			{
				curr_match_pos = next_state[curr_match_pos];
			}
			if(second[curr_match_pos+1] == first[i])
			{
				++curr_match_pos;
			}
			if(curr_match_pos == (second_size-1))
			{
				return (i-second_size+1);
			}
		}
		return -1;
	}
    int strStr(string haystack, string needle) {
        int hay_count =haystack.size();
        int needle_count = needle.size();
        if(needle_count==0)
        {
        	return 0;
        }
        if(hay_count==0)
        {
        	return -1;
        }
        return kmp_find(haystack,needle);
        // 
    }
};
int main()
{
	string str="abcabd";
	Solution s;
	cout<<s.strStr("aaaaa","bb")<<endl;
}