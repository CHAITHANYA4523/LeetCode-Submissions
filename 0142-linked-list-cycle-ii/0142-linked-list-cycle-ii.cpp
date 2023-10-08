/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
               break;
            }
        }
        if(fast == NULL || fast->next == NULL || fast->next->next == NULL) return NULL;
        ListNode* temp = head;
        while(temp->next != NULL){
            if(temp == slow)  return temp;
            temp = temp->next;
            slow = slow->next;
        }
        return NULL;
    }
};