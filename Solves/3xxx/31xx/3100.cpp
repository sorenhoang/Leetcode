class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int sum = numBottles;
        while (numBottles >= numExchange)
        {
            numBottles = numBottles - numExchange + 1;
            sum++;
            numExchange++;
        }
        return sum;
    }
};