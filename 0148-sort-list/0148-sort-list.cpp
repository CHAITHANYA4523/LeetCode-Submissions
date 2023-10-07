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
    ListNode* get_mid(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* &left, ListNode* &right){
        if(left == NULL) return right;
        if(right == NULL) return left;

        //New node is created for sorted list
        ListNode* final_head = new ListNode(-1);
        ListNode* final_tail = final_head;
        while(left && right){
            if(left->val < right->val){
                final_tail->next = left;
                final_tail = left;
                left = left->next;
            }
            else{
                final_tail->next = right;
                final_tail = right;
                right = right->next; 
            }
        }
        while(left){
            final_tail->next = left;
            final_tail = left;
            left = left->next;
        }
        while(right){
            final_tail->next = right;
            final_tail = right;
            right = right->next;
        }

        return final_head->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
        return head; // Base case: already sorted
        }   
        ListNode* mid = get_mid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode* ans = mergeList(left, right);
        return ans;
    }
};