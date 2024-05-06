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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        
        while (currNode != nullptr) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        return prevNode;
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedHead = reverseLL(head);

        ListNode* current = reversedHead;
        int maxValue = INT_MIN;
        ListNode* prev = nullptr;

        while (current != nullptr) {
            if (current->val < maxValue) {
                prev->next = current->next;
            } else {
                maxValue = current->val;
                prev = current;
            }
            current = current->next;
        }

        return reverseLL(reversedHead);
    }
};