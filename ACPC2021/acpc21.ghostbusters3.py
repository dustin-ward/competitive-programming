n, m = [int(x) for x in input().split()]

MOD = 1000000007

def binom(n, k):
	if k == 0 or k == n:
		return 1
	k = min(k, n-k)
	ans = 1
	for i in range(1, k+1):
		ans *= (n-k+i)
		ans //= i
	return ans % MOD

if n == m:
	print(1)
elif n < m:
	print(binom(m,n))
else:
	print(binom(n-1,m-1))
