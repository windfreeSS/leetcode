#include "../all.cpp"



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
        vector<Node*>  all_nodes;
        vector<Node*> raw_nodes;
        map<Node*,int> random_indexs;
        int idx =0;
        for(Node* it = head;it!=NULL;it=it->next,++idx)
        {
            raw_nodes.push_back(it);
            random_indexs[it] = idx;
            Node* nn = new Node(it->val,NULL,NULL);
            all_nodes.push_back(nn);

        }

        // update random 
        for(int i=0;i<all_nodes.size();++i)
        {
            if(raw_nodes[i]->random==NULL)
            {
                continue;
            }
            all_nodes[i]->random = all_nodes[random_indexs[raw_nodes[i]->random]];
        }
        for(int i=0;i<all_nodes.size()-1;++i)
        {
            all_nodes[i]->next = all_nodes[i+1];
        }
        return all_nodes[0];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

// 首先复制所有链表节点
// 记录原始链表中，随机指针指向的索引序号。
// 根据原始链表中的序号，设置复制链表的随机指针，指向对应位置的节点。