def input_data():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    lst = list(map(int, data[1:]))
    
    a = [0]
    for x in lst:
        if len(a) == 0 or x != a[-1]:
            a.append(x)
    
    n = len(a) - 1
    return n, a

def solve(n, a):
    prev_dp = [0] * (n + 1)
    
    for i in range(1, n + 1):
        curr_dp = [0] * (n + 1)
        for j in range(1, n + 1):
            if a[i] == a[n - j + 1]:
                curr_dp[j] = prev_dp[j-1] + 1
            else:
                curr_dp[j] = max(prev_dp[j], curr_dp[j-1])
        prev_dp = curr_dp
    
    return prev_dp

def output(n, dp):
    print(n - (dp[n] + 1) // 2)

if __name__ == "__main__":
    n, a = input_data()
    dp = solve(n, a)
    output(n, dp)
