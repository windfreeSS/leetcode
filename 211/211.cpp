#include "../all.cpp"

struct WordLink
{
    vector<WordLink*> nexts;
    bool is_leaf;
    WordLink():nexts(26),is_leaf(false)
    {

    }
};
class WordDictionary {
private:
    WordLink wl;
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
    
    void add_next(const string& word,size_t pos,WordLink*where)
    {
        if(pos>=word.size())
        {
            where->is_leaf = true;
            return ;
        }
        if(where->nexts[word[pos]-'a']==NULL)
        {
            where->nexts[word[pos]-'a'] = new WordLink();
        }
        add_next(word,pos+1,where->nexts[word[pos]-'a']);
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        add_next(word,0,&wl);
    }
    bool search_next(const string& word,size_t pos,WordLink* where)
    {
        if(pos >= word.size())
        {
            return where->is_leaf;
        }
    
        for(int i=0;i<where->nexts.size();++i)
        {
            if(where->nexts[i]==NULL)
            {
                continue;
            }
            if( i!= (word[pos]-'a')
                && word[pos]!='.')
            {
                continue;
            }
            if(search_next(word,pos+1,where->nexts[i]))
            {
                return true;
            }
        }

        return false;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_next(word,0,&wl);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */



int main(int argc, char const *argv[])
{
    /* code */
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    obj->addWord("xyzt");
    obj->addWord("xyz");


    cout<<obj->search("pad")<<endl;
    cout<<obj->search("bad")<<endl;
    cout<<obj->search(".ad")<<endl;
    cout<<obj->search("b..")<<endl;
    cout<<obj->search("xyz")<<endl;
    return 0;
}


// 使用多重链表