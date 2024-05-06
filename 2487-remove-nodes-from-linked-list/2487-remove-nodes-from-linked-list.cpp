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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr = head;
        
        while(curr != nullptr) {
            while(!st.empty() && st.top() -> val < curr -> val) {
                st.pop();
            }
            
            st.push(curr);
            curr = curr -> next;
        }
        
        ListNode* temp = new ListNode(0);
        ListNode* prev = temp;
        
        while(!st.empty()) {
            prev -> next = st.top();
            prev = prev -> next;
            st.pop();
        }
        
        prev -> next = nullptr;
        
        ListNode* prevNode = nullptr;
        curr = temp->next;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        return prevNode;
    }
};