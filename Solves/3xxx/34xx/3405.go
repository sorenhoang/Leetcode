package main

const MOD = 1e9 + 7
const MAX = 100005

var fact [MAX]int64
var invFact [MAX]int64

func modPow(a, b, mod int64) int64 {
	res := int64(1)
	a %= mod
	for b > 0 {
		if b&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		b >>= 1
	}
	return res
}

func initComb() {
	fact[0] = 1
	for i := 1; i < MAX; i++ {
		fact[i] = fact[i-1] * int64(i) % MOD
	}
	invFact[MAX-1] = modPow(fact[MAX-1], MOD-2, MOD)
	for i := MAX - 2; i >= 0; i-- {
		invFact[i] = invFact[i+1] * int64(i+1) % MOD
	}
}

func comb(n, k int) int64 {
	if k < 0 || k > n {
		return 0
	}
	return fact[n] * invFact[k] % MOD * invFact[n-k] % MOD
}

func countGoodArrays(n int, m int, k int) int {
	initComb()
	numberOfDiff := n - k - 1
	if numberOfDiff <= 0 {
		return m % MOD
	}

	ans := comb(n-1, numberOfDiff)
	ans = ans * modPow(int64(m-1), int64(numberOfDiff), MOD) % MOD
	ans = ans * int64(m) % MOD
	return int(ans)
}

func main() {

	println("countGoodArrays(3,2,1):", countGoodArrays(3, 2, 1))
	println("countGoodArrays(4,2,2):", countGoodArrays(4, 2, 2))
	println("countGoodArrays(5,2,0):", countGoodArrays(5, 2, 0))
	println("countGoodArrays(1,1,0):", countGoodArrays(1, 1, 0))
}
