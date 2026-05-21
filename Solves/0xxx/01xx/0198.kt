val dp = IntArray(amount + 1) { amount + 2 }
        dp[0] = 0

        for (i in 1..amount) {
            for (coin in coins) {
                if (i < coin) continue

                dp[i] = minOf(dp[i], dp[i - coin] + 1)
            }
        }

        return if (dp[amount] > amount) -1 else dp[amount]