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

N,M = [int(x) for x in input().split()]
uf = UnionFind(N)

for _ in range(M):
    u,v = [int(x)-1 for x in input().split()]
    uf.merge(u,v)

ans = []
for i in range(N):
    if uf.find(i) != uf.find(0):
        ans.append(i)

if len(ans):
    for i in ans:
        print(i+1)
else:
    print("Connected")
