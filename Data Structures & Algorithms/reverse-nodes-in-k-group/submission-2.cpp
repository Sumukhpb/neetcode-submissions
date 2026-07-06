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
    ListNode* temp = head, *prev = NULL, *front;

    while(temp != end){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp && count < k){
            temp = temp->next;
            count++;
        }
        if(count < k){
            return head;
        }
        ListNode* NewHead = reverse(head, temp);

        head->next = reverseKGroup(temp, k);

        return NewHead;
    }
};
