class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_len = s.size();
        if(s_len==0)
        {
        	return 0;
        }
        while(s_len>0)
        {
        	if(s[s_len-1]==' ')
        	{
        		--s_len;
        	}
        	else
        	{
        		break;
        	}
        }
        for(int i=s_len-1;i>=0;--i)
        {
        	if(s[i]==' ')
        	{
        		return (s_len-i-1);
        	}
        }
        return s_len;
    }
};