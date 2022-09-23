package binom

func binom_min(a, b int64) int64 {
	if a <= b {
		return a
	}
	return b
}

func Binom(n, k int64) int64 {
	if k == 0 || k == n {
		return 1
	}
	k = binom_min(k, n-k)
	var ans int64
	var i int64
	ans = 1
	for i = 1; i <= k; i++ {
		ans *= (n - k + i)
		ans /= i
	}
	return ans
}
