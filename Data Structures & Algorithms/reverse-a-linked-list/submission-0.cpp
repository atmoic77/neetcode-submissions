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
    void reverse(ListNode* &preptr,ListNode* &ptr){
        if(ptr == nullptr) return;
        else{
            ListNode* front = ptr -> next;
            ptr -> next = preptr;
            preptr = ptr;
            ptr = front;
            reverse(preptr,ptr);
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* preptr = nullptr;
        ListNode* ptr = head;
        reverse(preptr,ptr);
        return preptr;
    }
};
