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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        
        ListNode* tmp = new ListNode(0);
        tmp -> next = head;

        ListNode* prev = tmp;
        ListNode* curr = head;
        
        while(curr != nullptr) {
            if(st.count(curr -> val)) {
                // skip curr and connect prev to curr's next
                prev -> next = curr -> next;
            } else {
                // keep curr
                prev = curr;
            }
            // move curr to the next node
            curr = curr -> next;
        }

        // cause tmp[0] = 0
        return tmp -> next;
    }
};