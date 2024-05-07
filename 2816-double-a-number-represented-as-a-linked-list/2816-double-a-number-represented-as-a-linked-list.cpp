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
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr != nullptr) {
            int tmp = curr -> val << 1;
            
            if(tmp < 10) {
                curr -> val = tmp;
            } else if (prev != nullptr) {
                curr -> val = tmp % 10;
                ++prev -> val;
            } else {
                head = new ListNode(1, curr);
                curr -> val = tmp % 10;
            }
            
            prev = curr;
            curr = curr -> next;
        }
        
        return head;
    }
};