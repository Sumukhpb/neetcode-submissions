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
    ListNode* reverse(ListNode* head, ListNode* end){
        ListNode* temp = head, *pre = NULL, *front;

        while(temp != end){
            front = temp->next;
            temp->next = pre;
            pre = temp;
            temp = front;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        while(temp && count < k){
            temp = temp->next;
            count++;
        }

        if(count < k){
            return head;
        }

        ListNode* newHead = reverse(head, temp);
        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};
