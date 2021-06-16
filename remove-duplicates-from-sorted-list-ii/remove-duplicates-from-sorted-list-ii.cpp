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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;
        ListNode* temp = head;
        int repeat = INT_MIN;
        
        while(temp!=NULL)
        {
            while(temp->val == repeat && temp->next!=NULL)
            {
                temp = temp->next;
            }
            if(temp->next!=NULL && temp->next->val == temp->val)
            {
                repeat = temp->val;
            }
            else
            {   if(temp->next == NULL && repeat == temp->val)
                {
                    break;
                 }
                itr->next = new ListNode(temp->val);
                itr = itr->next;
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};