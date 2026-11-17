
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (true) {
            ListNode* end = prev;

            for (int i = 0; i < k && end; i++) {
                end = end->next;
            }

            if (!end) break;

            ListNode* start = prev->next;
            ListNode* nextGroup = end->next;

            ListNode* p = nextGroup;
            ListNode* curr = start;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = p;
                p = curr;
                curr = temp;
            }

            prev->next = end;
            prev = start;
        }

        return dummy.next;
    }
};
