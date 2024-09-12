import random

def generate_test_cases(n, k):
    print(n, k)
    for _ in range(n):
        trick = random.sample(range(1, k + 1), k)
        print(" ".join(map(str, trick)))

# Example usage:
n = 199999  # Number of tricks
k = 2   # Number of cards in Wojtek's deck

generate_test_cases(n, k)

