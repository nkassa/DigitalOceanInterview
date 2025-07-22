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
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int carry = 0;
        while(l1 && l2)
        {
            curr->next = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        while(l1)
        {
            curr->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry)/10;
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2)
        {
            curr->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry)/10;
            l2 = l2->next;
            curr = curr->next;
        }
        if(carry > 0)
        {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return ans->next;
    }
};