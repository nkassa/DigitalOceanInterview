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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> list;
        while(head)
        {
            list.push_back(head->val);
            head = head->next;
        }
        sort(list.begin(), list.end());
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        for(int i = 0; i < list.size(); i++)
        {
            curr->next = new ListNode(list[i]);
            curr = curr->next;
        }
        return ans->next;
    }
};