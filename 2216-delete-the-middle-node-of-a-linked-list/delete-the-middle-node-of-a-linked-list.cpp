class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge Case: If the list has only 1 node, returning nullptr is required.
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        // Start fast one step ahead! 
        // This offsets slow to stop exactly BEFORE the middle node.
        ListNode* fast = head->next; 
        
        // Use the standard, reliable condition
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow is now standing exactly one node before the middle node
        ListNode* middle = slow->next;     // This is the actual middle node
        slow->next = middle->next;         // Bypass it
        delete middle;                     // Free the memory
        
        return head;
    }
};