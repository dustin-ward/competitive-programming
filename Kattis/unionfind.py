class UnionFind:
    class UF:
        def __init__(self, p, rank):
            self.p = p
            self.rank = rank

    def __init__(self, n):
        self.size = n
        self.uf = []
        for i in range(self.size):
            self.uf.append(self.UF(i,0))


    def find(self, x):
        if self.uf[x].p != x:
            self.uf[x].p = self.find(self.uf[x].p)
        return self.uf[x].p

    def merge(self, u, v):
        a = self.find(u)
        b = self.find(v)
        if a != b:
            if self.uf[a].rank > self.uf[b].rank:
                self.uf[b].p = a
            else:
                self.uf[a].p = b
                if self.uf[a].rank == self.uf[b].rank:
                    self.uf[b].rank += 1
            return True
        return False

N, Q = [int(x) for x in input().split()]
uf = UnionFind(N)

ans = ""
for _ in range(Q):
    q,a,b = input().split()
    if q == "?":
        ans += "yes\n" if uf.find(int(a)) == uf.find(int(b)) else "no\n"
    else:
        uf.merge(int(a), int(b))

print(ans)
