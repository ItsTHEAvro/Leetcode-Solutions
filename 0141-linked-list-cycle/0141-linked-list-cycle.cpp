/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> mp;
        ListNode* tmp = head;
        while(tmp != nullptr) {
            if(mp.count(tmp) > 0) return true;
            mp[tmp] == 1;
            tmp = tmp -> next;
        }
        return false;
    }
};