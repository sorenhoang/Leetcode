class Solution
{
public:
    int numSteps(string s)
    {
        deque<char> dq(s.begin(), s.end());
        int steps = 0;

        while (!(dq.size() == 1 && dq.front() == '1'))
        {

            if (dq.back() == '0')
            {
                // Even -> divide by 2
                dq.pop_back();
            }
            else
            {
                // Odd -> add 1
                int i = dq.size() - 1;

                // Turn trailing 1s to 0
                while (i >= 0 && dq[i] == '1')
                {
                    dq[i] = '0';
                    i--;
                }

                if (i >= 0)
                {
                    dq[i] = '1';
                }
                else
                {
                    dq.push_front('1');
                }
            }

            steps++;
        }

        return steps;
    }
};