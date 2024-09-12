from itertools import permutations


def find(x, parent):
    if x != parent[x]:
        parent[x] = find(parent[x], parent)
    return parent[x]


def merge(x, y, z, parent, size, ans, g):
    rootX = find(x, parent)
    rootY = find(y, parent)

    if rootX == rootY:
        return ans

    if rootX == find(1, parent):
        ans += size[rootY] * z
    if rootY == find(1, parent):
        ans += size[rootX] * z

    parent[rootX] = rootY
    size[rootY] += size[rootX]
    g.append((rootX, rootY, z))

    return ans


def main():
    import sys

    input = sys.stdin.read
    data = input().split()

    idx = 0

    n = int(data[idx])
    k = int(data[idx + 1])
    idx += 2

    m = 0
    ID = {}
    Fa = list(range(200005))
    Siz = [1] * 200005
    p = list(range(k))
    ps = [[0] * k for _ in range(125)]
    To = [[0] * 125 for _ in range(125)]
    ans = 0
    f = []
    g = []

    for perm in permutations(p):
        m += 1
        x = 0
        for i in range(k):
            x = x * k + perm[i]
            ps[m][i] = perm[i]
        ID[x] = m

    for i in range(1, m + 1):
        for j in range(1, m + 1):
            x = 0
            for l in range(k):
                x = x * k + ps[i][ps[j][l]]
            To[i][j] = ID[x]

    for i in range(1, n + 1):
        x = 0
        for j in range(k):
            x = x * k + int(data[idx]) - 1
            idx += 1
        for j in range(1, m + 1):
            Fa[j] = j
            Siz[j] = 1

        x = ID[x]
        ans += i
        f = g.copy()
        g.clear()
        for j in range(1, m + 1):
            ans = merge(j, To[x][j], i, Fa, Siz, ans, g)

        for edge in f:
            x, y, z = edge
            ans = merge(x, y, z, Fa, Siz, ans, g)

    print(ans)


if __name__ == "__main__":
    main()
