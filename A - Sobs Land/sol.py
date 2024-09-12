import sys
from collections import defaultdict

sys.setrecursionlimit(400000)

N = int(4e5 + 5)
inf = int(2e9 + 1e8)

n, m, s, t, u, v, ans, tot, s1, s2 = 0, 0, 0, 0, 0, 0, inf, 0, 0, 0
dfn = [0] * N
low = [0] * N
flow = [0] * N
vis = [0] * N
w = [0] * N
a = defaultdict(list)


def read():
    return list(map(int, sys.stdin.read().split()))


def tarjan(u: int, fa: int, k: int) -> None:
    global tot, ans, s1, s2
    dfn[u] = low[u] = tot = tot + 1
    for v, idx in a[u]:
        if idx == fa or vis[idx]:
            continue
        if dfn[v]:
            low[u] = min(low[u], dfn[v])
        else:
            tarjan(v, idx, k)
            low[u] = min(low[u], low[v])
            if low[v] > dfn[u] and dfn[t] and dfn[t] >= dfn[v] and w[k] + w[idx] < ans:
                ans = w[k] + w[idx]
                s1 = k
                s2 = idx


def dfs(u: int) -> bool:
    global ans, s1, s2, tot
    flow[u] = 1
    found = u == t
    for v, idx in a[u]:
        if flow[v] or not dfs(v):
            continue
        found = True
        vis[idx] = 1
        dfn[:] = [0] * (n + 1)
        tot = 0
        tarjan(s, 0, idx)
        if not dfn[t] and w[idx] < ans:
            ans = w[idx]
            s1 = idx
            s2 = 0
        vis[idx] = 0
    return found


def main():
    global n, m, s, t
    input_data = read()
    n, m, s, t = input_data[0], input_data[1], input_data[2], input_data[3]
    edge_idx = 4
    for i in range(1, m + 1):
        u, v, weight = (
            input_data[edge_idx],
            input_data[edge_idx + 1],
            input_data[edge_idx + 2],
        )
        w[i] = weight
        a[u].append((v, i))
        a[v].append((u, i))
        edge_idx += 3

    if not dfs(s):
        print("0\n0")
        return

    if ans == inf:
        print("-1")
        return

    print(ans)
    print(1 + (s2 > 0))
    print(s1, end="")
    if s2:
        print(f" {s2}")
    else:
        print()


if __name__ == "__main__":
    main()
