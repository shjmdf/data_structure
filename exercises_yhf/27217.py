def calculate_catalan(n):
    f = [0] * (n + 1)
    f[0] = 1
    f[1] = 1
    for i in range(2, n + 1):
        for j in range(i):
            f[i] += f[j] * f[i - j - 1]
    
    return f[n]

if __name__ == "__main__":
    n = int(input())
    result = calculate_catalan(n)
    print(result)