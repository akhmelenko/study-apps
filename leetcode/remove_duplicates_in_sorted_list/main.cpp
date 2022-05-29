#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        while (ptr->next && ptr) {
            if (ptr->val == ptr->next->val)
                ptr->next = ptr->next->next;
            ptr = ptr->next;
        }
        return head;
    };

    int main() {
        ListNode third(3, nullptr);
        ListNode second(2, &third);
        ListNode first(1, &second);
        ListNode head(0, &first);

        Solution s;
        s.deleteDuplicates(&head);

        return 0;
    }

    /*
"()"
"()[]{}"
"(]"
"([)]"
"{[]}"


true
true
false
false
true
*/