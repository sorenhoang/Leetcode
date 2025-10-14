#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];
    bool isSet(int bit)
    {
        return (links[bit] != NULL);
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Tries
{
private:
    Node *root;

public:
    Tries()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->isSet(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->isSet(1 - bit))
            {
                maxi |= (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << sol.findMaximumXOR(nums) << endl;
    return 0;
}