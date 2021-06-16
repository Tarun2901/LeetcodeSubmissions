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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* i = l1;
        ListNode* j = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* k = dummy;
        int carry = 0;
        while(i!=nullptr || j!=nullptr || carry!= 0)
        {
            int d1 = i!=nullptr?i->val:0;
            int d2 = j!=nullptr?j->val:0;
            int sum = d1+d2+carry;
            int val = sum%10;
            carry = sum/10;
            k->next = new ListNode(val);
            if(i!=NULL)
             i = i->next;
            if(j!=NULL)
             j = j->next;
            k = k->next;
        }
        
        return dummy->next;
    }
};