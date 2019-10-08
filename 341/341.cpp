/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// 保存每一个嵌套层次的索引号
struct nest_node
{
    vector<NestedInteger*> datas;
    int idx;
};
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nest_node nn;
        for (int i = 0; i < nestedList.size(); ++i)
        {
            nn.datas.push_back(&nestedList[i]);
        }
        nn.idx = 0;
        nest_iterator.push(nn);
        find_next();
    }

    int next() {
        int ret = next_val;
        find_next();
        return ret;
    }

    bool hasNext() {
        return next_flag;
    }
    void find_next()
    {
        next_flag = false;

        while (!nest_iterator.empty())
        {
            nest_node& nn = nest_iterator.top();

            if (nn.idx >= nn.datas.size())
            {
                nest_iterator.pop();
                continue;
            }
            if (nn.datas[nn.idx]->isInteger())
            {
                next_val = nn.datas[nn.idx]->getInteger();
                ++nn.idx;
                next_flag = true;
                return ;
            }

            nest_node new_node;
            for(int i=0;i<nn.datas[nn.idx]->getList().size();++i)
            {
                new_node.datas.push_back(& (nn.datas[nn.idx]->getList()[i]));
            }
            new_node.idx=0;
            ++nn.idx;
            nest_iterator.push(new_node);

        }

    }


private:
    stack<nest_node> nest_iterator;
    bool next_flag;
    int next_val;
};

class NestedIterator123 {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nested_its = &nestedList;

        next_flag = false;
        for (int i = 0; i < nestedList.size(); ++i)
        {
            vector<int> positions;
            if (find_first(nestedList[i], positions))
            {
                nested_idxs.push_back(i);
                std::copy(positions.begin(), positions.end(), std::back_inserter(nested_idxs));
                next_flag = true;
                break;
            }
        }

        for (int i = 0; i < nested_idxs.size(); ++i)
        {
            printf("%d,", nested_idxs[i]);
        }
        printf("next:%d\n", next());

        next_flag = false;
    }

    int next() {
        const NestedInteger& ni = (*nested_its)[nested_idxs[0]];
        int val = get(ni, nested_idxs, 1);
        ++nested_idxs[nested_idxs.size() - 1];
        next_flag = find_next(0);
        return val;
    }

    bool hasNext() {
        return next_flag;
    }

    int get(const NestedInteger&ni, vector<int>& indexs, int depth )
    {
        if (depth >= indexs.size())
        {
            return ni.getInteger();
        }
        return get(ni.getList()[indexs[depth]], indexs, depth + 1);
    }

    bool find_next(NestedInteger& ni, int depth)
    {
        if (depth == (nested_idxs.size() - 1))
        {

        }
    }


    bool find_first(const NestedInteger& ni , vector<int>& indexs)
    {
        if (ni.isInteger())
        {
            return true;
        }
        const vector<NestedInteger> &tmp = ni.getList();
        for (int i = 0; i < tmp.size(); ++i )
        {
            indexs.push_back(i);
            if (find_first(tmp[i], indexs))
            {
                return true;
            }
            indexs.pop_back();
        }

        return false;
    }

private:
    vector<int> nested_idxs;
    vector<NestedInteger>* nested_its;
    bool next_flag;

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

