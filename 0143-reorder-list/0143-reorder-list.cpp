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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* ptr = head;
        
        while(ptr != nullptr) {
            vec.push_back(ptr);
            ptr = ptr -> next;
        }
        
        int l = 0, r = vec.size() -1;
        
        while(l < r) {
            vec[r] -> next = vec[l] -> next;
            vec[l] -> next = vec[r];
            l++;
            r--;
        }
        
        vec[l] -> next = nullptr;
        head = vec[0];
    }
};