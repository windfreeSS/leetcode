#include "../all.cpp"

class Solution {
public:
	 bool is_one_diff(const string& first, const string& second)
    {
        int diff_count = 0;
        for (int i = 0; i < first.size(); ++i)
        {
            if (first[i] == second[i])
            {
                continue;
            }
            ++diff_count;
            if (diff_count > 1)
            {
                return false;
            }
        }
        return (diff_count == 1);
    }
	int find_bfs(vector<string>& pre_level,int depth,const string& endWord,list<string>& word_list)
	{
		if(pre_level.empty())
		{
			return 0;
		}

		vector<string> curr_level;
		for(int i=0;i<pre_level.size();++i)
		{
			list<string>::iterator word_it =  word_list.begin();
			while(word_it!=word_list.end())
			{
				if(!is_one_diff(pre_level[i],*word_it))
				{
					word_it++;
					continue;
				}
				if(*word_it == endWord)
				{
					return depth+1;
				}
				curr_level.push_back(*word_it);
				word_list.erase(word_it++);
			}
		}

		return find_bfs(curr_level,depth+1,endWord,word_list);

	}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> curr_level;
        curr_level.push_back(beginWord);
        list<string> word_list;

        std::copy(wordList.begin(),wordList.end(),back_inserter(word_list));

        return find_bfs(curr_level,1,endWord,word_list);
    }
};

int main()
{
	Solution s;
	vector<string> data = {"hot","dot","dog","lot","log"};
	cout<<s.ladderLength("hit","cog",data);
}