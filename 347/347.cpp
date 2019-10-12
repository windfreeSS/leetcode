#include "../all.cpp"


class Solution {
public:
typedef pair<int, int>  Element;
// 创建一个最小堆
    void heap_sort_insert(vector<Element>& result, Element& data)
    {

        if (result.size() == 0)
        {
            result.push_back(data);
            return ;
        }
        result.push_back(data);

        int curr_idx = result.size() - 1;
        int father_node = (curr_idx - 1) >> 1;
        while (father_node >= 0)
        {
            if (result[curr_idx].first >= result[father_node].first)
            {
                break;
            }
            swap(result[curr_idx], result[father_node]);
            curr_idx = father_node;
            father_node = (curr_idx - 1) >> 1;
        }

    }
    const Element& heap_sort_top(vector<Element>&result)
    {
        if (!result.empty())
        {
            return result[0];
        }
        static Element e;
        return e;
    }

    void heap_sort_pop(vector<Element>&result)
    {
        if (result.empty())
        {
            return ;
        }
        swap(result[0], result[result.size() - 1]);
        result.pop_back();

        int r_size = result.size();
        // adjust
        int which_son;
        int father = 0;
        which_son = (father << 1) + 1;
        while (which_son < r_size)
        {
            if (which_son < (r_size - 1) && result[which_son].first > result[which_son + 1].first )
            {
                ++which_son;
            }
            if (result[father].first <= result[which_son].first)
            {
                break;
            }
            swap(result[father], result[which_son]);
            father = which_son;
            which_son = (father << 1) + 1;
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int , int> hash_num;
        for (int i = 0; i < nums.size(); ++i)
        {
            ++hash_num[nums[i]];
        }
        
        vector<Element> v_heap;
        for(map<int,int>::iterator it = hash_num.begin();it!=hash_num.end();++it)
        {
            Element e = {it->second,it->first};
            if(v_heap.size()>=k)
            {
                if(e.first < heap_sort_top(v_heap).first )
                {
                    continue;
                }
                heap_sort_pop(v_heap);
            }
            heap_sort_insert(v_heap,e);
        }
        vector<int> ret(k);
        for(int i=k-1;i>=0;--i)
        {
            ret[i] = heap_sort_top(v_heap).second;
            heap_sort_pop(v_heap);
        }

        return ret;

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}