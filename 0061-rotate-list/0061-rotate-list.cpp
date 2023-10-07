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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0 || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while(fast){
            count++;
            fast = fast->next;
        }
        if(k%count == 0) return head;

        fast = head;
        for(int i=0; i<(k%count); i++){
            fast = fast->next;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};