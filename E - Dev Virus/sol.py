for _ in ' '*int(input()):
    n,k = map(int, input().split()); a = [int(x) for x in input().split()]
    print(0 if all([i==k for i in a]) else 1 if sum(a)==k*n or k in a else 2)
