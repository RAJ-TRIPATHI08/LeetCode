class Solution {
public:
    ListNode* mergeTwo(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;

        if(!l2) return l1;

        if(l1->val <= l2->val)
        {
            l1->next = mergeTwo(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwo(l2->next, l1);
            return l2;
        }
    }

    ListNode* partitionAndMerge(int s, int e, vector<ListNode*>& lists)
    {
        if(s > e) return NULL;

        if(s == e) return lists[s];

        int mid = s + (e-s)/2;
        ListNode* l1 = partitionAndMerge(s, mid, lists);
        ListNode* l2 = partitionAndMerge(mid+1, e, lists);

        return mergeTwo(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = 0;
        int e = lists.size() - 1;
        return partitionAndMerge(s, e, lists);
    }
};