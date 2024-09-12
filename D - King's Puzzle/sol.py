t = int(input())
for i in range(t):
    n = int(input())
    lo, hi = 1, 1000000000
    ans = False
    while lo <= hi:
        mid = (lo + hi) // 2
        target = mid * (mid + 1) // 2
        if target == n:
            ans = True
            break  
        elif target > n:
            hi = mid - 1
        else:
            lo = mid + 1

    if ans == True:
        print("yes")
    else:
        print("no")
