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
        string one = "";
        string two = "";
        while(l1)
        {
            one += to_string(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            two += to_string(l2->val);
            l2 = l2->next;
        }

        ListNode* curr = new ListNode(0);
        int carry = 0;
        int i = one.size()-1;
        int j = two.size()-1;
        while(i >= 0 || j >= 0 || carry > 0)
        {
            int sum = carry;
            if(i >= 0)
            {
                sum += one[i]-'0';
                i--;
            }
            if(j >= 0)
            {
                sum += two[j]-'0';
                j--;
            }
            curr->val = sum % 10;
            ListNode* head = new ListNode(0);
            head->next = curr;
            carry = sum / 10;
            curr = head;
        }
        return curr->next;
    }
};