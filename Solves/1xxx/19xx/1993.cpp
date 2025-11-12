class LockingTree
{
    vector<tuple<short, short, forward_list<short>>> tree; // parent, lockedBy, list of children

    bool unlockDescendant(const short &num)
    { // O(N)
        queue<short> q;
        q.push(num);
        bool hasLockedDescendant = false;

        do
            for (short i = q.size(); i > 0; --i)
            {
                if (get<1>(tree[q.front()]) >= 0)
                {
                    hasLockedDescendant = true;
                    get<1>(tree[q.front()]) = -1;
                }

                for (const short &j : get<2>(tree[q.front()]))
                    q.push(j);

                q.pop();
            }
        while (!q.empty());

        return hasLockedDescendant;
    }

public:
    LockingTree(const vector<int> &parent)
    { // O(N)
        tree.resize(parent.size());
        tree[0] = {-1, -1, {}};
        for (short i = 1; i < tree.size(); ++i)
        {
            get<0>(tree[i]) = parent[i];
            get<1>(tree[i]) = -1;
            get<2>(tree[parent[i]]).push_front(i);
        }
    }

    bool lock(const int &num, const int &user)
    { // O(1)
        if (get<1>(tree[num]) < 0)
        {
            get<1>(tree[num]) = user;
            return true;
        }

        return false;
    }

    bool unlock(const int &num, const int &user)
    { // O(1)
        if (get<1>(tree[num]) == user)
        {
            get<1>(tree[num]) = -1;
            return true;
        }

        return false;
    }

    bool upgrade(const int &num, const int &user)
    { // O(N)
        if (get<1>(tree[num]) < 0)
        {
            for (short i = get<0>(tree[num]); i >= 0; i = get<0>(tree[i]))
                if (get<1>(tree[i]) >= 0)
                    return false;

            if (!unlockDescendant(num))
                return false;

            get<1>(tree[num]) = user;
            return true;
        }

        return false;
    }
}; // Space complexity: O(N)