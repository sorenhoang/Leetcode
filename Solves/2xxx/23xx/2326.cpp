#include <bits/stdc++.h>
using namespace std;

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
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        int idx = 0;

        while (top <= bottom && left <= right && head != nullptr)
        {
            // left → right
            for (int j = left; j <= right && head != nullptr; ++j)
            {

                matrix[top][j] = head->val;
                head = head->next;
            }
            top++;

            // top → bottom
            for (int i = top; i <= bottom && head != nullptr; ++i)
            {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;

            // right → left
            for (int j = right; j >= left && head != nullptr; --j)
            {
                matrix[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;

            // bottom → top
            for (int i = bottom; i >= top && head != nullptr; --i)
            {
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return matrix;
    }
};