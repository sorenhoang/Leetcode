class Solution
{
public:
    void reorderList(ListNode *head)
    {
        helper(head);
    }

    ListNode *helper(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *last = head;
        ListNode *prev = head;
        while (last->next != nullptr)
        {
            prev = last;
            last = last->next;
        }
        prev->next = nullptr;
        ListNode *next = head->next;
        head->next = last;
        last->next = helper(next);
        return head;
    }
};