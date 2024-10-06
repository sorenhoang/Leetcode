/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */ ccccvv
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // original O(n) TC SC tail recursion soln
        // take each section out of the list, reverse it, reattach
        
        // check if the size of remainder of the unreversed list is at least k 
        int s = 0; // size of list
        ListNode* curr = head; 
        while (curr != NULL) { // run time is O(k) -> O(1)
            s++;
            if (s >= k) break;
            curr = curr->next;
        } // get the size of the list
        if (s < k) { // if the remainder size is smaller than k, return the remainder
            return head;
        }
        
        ListNode* h = head;
        curr = head; // reuse to save space
        for (int i = 0; i < k - 1; ++i) { // run time is O(k) -> O(1)
            curr = curr->next;
        } // curr->next points at the new head of not yet reversed section
        // curr points at last item in k items to be reversed
    
        ListNode* nh = curr->next; // new head for next sections
        curr->next = NULL;
        // before reversal: h = head, curr = end of k items
        // reverse linked list of size k
        ListNode* p = NULL;
        ListNode* c = h;
        ListNode* n = NULL;
        while(c != NULL) { // run time is O(k) -> O(1)
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        // after reversal: curr is reversed head, h = end of k reversed items
        h->next = reverseKGroup(nh, k); // h is now the pointer to the last elt in the rev list
        // recurses n/k times, each time runs O(3k) -> O(n)
        return curr;
    }
};