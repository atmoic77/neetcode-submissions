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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* aage = head;
      ListNode* check = head;
      ListNode* piche = nullptr;
      int gino = 0;
      while(aage != nullptr){
        gino++;
        aage = aage -> next;
      }
      if(gino == 1){
        return head = nullptr;
      }
      if(gino == n){
        return head = head -> next;
      }
      int count = 1;
      while(count != (gino - n + 1)){
        count++;
        piche = check;
        check = check -> next;
      }  
      piche -> next = check -> next;
      return head;
    }
};
