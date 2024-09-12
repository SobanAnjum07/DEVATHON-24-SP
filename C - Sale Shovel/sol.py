def compute(x, n):
    lo = 1
    hi = x // 2
    ans = hi + 1
    
    while lo <= hi:
        mid = (lo + hi) // 2
        if n >= x - mid:
            ans = min(ans, mid)
            hi = mid - 1
        else:
            lo = mid + 1
    
    if ans == x // 2 + 1:
        return 0
    
    return (x // 2) - ans + 1

def solve(n):
    if n < 5:
        print((n * (n - 1)) // 2)
        return

    # Determine the number of trailing nines needed
    if n < 50:
        need = 1
    elif n < 500:
        need = 2
    elif n < 5000:
        need = 3
    elif n < 50000:
        need = 4
    elif n < 500000:
        need = 5
    elif n < 5000000:
        need = 6
    elif n < 50000000:
        need = 7
    elif n < 500000000:
        need = 8
    else:
        need = 9

    s = '9' * need
    ans = 0
    for i in range(10):
        if i == 0:
            ans += compute(int(s), n)
        else:
            t = str(i) + s
            val = compute(int(t), n)
            ans += val

    print(ans)

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    t = int(data[0])
    queries = [int(data[i]) for i in range(1, t + 1)]
    
    for n in queries:
        solve(n)
