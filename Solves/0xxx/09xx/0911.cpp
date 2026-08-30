class TopVotedCandidate
{
public:
    unordered_map<int, int> mpp;
    map<int, int> timelyMax;
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        int leader = -1, maxVote = 0;
        for (int i = 0; i < times.size(); i++)
        {
            mpp[persons[i]]++;

            if (mpp[persons[i]] >= maxVote)
            {
                maxVote = mpp[persons[i]];
                leader = persons[i];
            }
            timelyMax[times[i]] = leader;
        }
    }

    int q(int t)
    {
        auto it = timelyMax.upper_bound(t);
        if (it != timelyMax.begin())
        {
            --it;
            return it->second;
        }
        return -1;
    }
};