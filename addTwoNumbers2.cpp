/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        long long list1;
        long long list2;
        while(l1)
        {
            list1 += l1->val;
            l1 = l1->next;
        }
        while(l2)
        {
            list2 += l2->val;
            l2 = l2->next;
        }
        list1 += list2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        int size = (to_string(list1)).size();
        while(list1 > 0)
        {
            int current = list1 / size;
            curr->next = new ListNode(current);
            list1 %= size;
            size /= 10;
            curr = curr->next;
        }
        return dummy->next;
    }
};