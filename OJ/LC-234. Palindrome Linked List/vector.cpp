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
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        while (head != nullptr) {
            v.push_back(head->val);
            head=head->next;
        }
        vector<int>tmpv=v;
        reverse(tmpv.begin(),tmpv.end());
        if (v == tmpv) {return true;}
        else {return false;}
    }
};
