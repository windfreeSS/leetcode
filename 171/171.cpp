class Solution {
public:
    int titleToNumber(string s) {
        int val = 0 ;
        for(int i=0;i<s.size();++i)
        {
        	val = val*26;
        	if(s[i]>='a')
        	{
        		val += s[i]-'a'+1;
        	}
        	else
        	{
        		val += s[i]-'A'+1;
        	}
        }
        return val;
    }
};