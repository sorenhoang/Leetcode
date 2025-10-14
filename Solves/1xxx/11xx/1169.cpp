class Solution
{
    struct Transaction
    {
        string name{};
        int time{};
        int val{};
        string city{};
        bool seen{};
    };

public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        vector<Transaction> txs;
        vector<string> res;

        // input processing
        for (const auto &csv : transactions)
        {
            Transaction tx;

            istringstream iss(csv);
            string token;
            for (int i = 0; i < 4 && getline(iss, token, ','); ++i)
            {
                if (i == 0)
                {
                    tx.name = token;
                }
                else if (i == 1)
                {
                    tx.time = stoi(token);
                }
                else if (i == 2)
                {
                    tx.val = stoi(token);
                }
                else
                {
                    tx.city = token;
                }
            }

            txs.emplace_back(tx);
        }

        for (int i = 0; i < txs.size(); ++i)
        {
            if (txs[i].val > 1000)
                txs[i].seen = true;
            for (int j = 0; !txs[i].seen && j < txs.size(); ++j)
            {
                if (i != j && txs[i].name == txs[j].name && txs[i].city != txs[j].city && abs(txs[i].time - txs[j].time) <= 60)
                {
                    txs[i].seen = true;
                    txs[j].seen = true;
                }
            }
        }

        for (int i = 0; i < txs.size(); ++i)
            if (txs[i].seen)
                res.emplace_back(transactions[i]);

        return res;
    }
};