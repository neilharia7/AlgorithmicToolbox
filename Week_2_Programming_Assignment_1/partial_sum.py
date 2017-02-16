def find_fibo(x):
    a, b = 0, 1
    if x <= 1: return x
    else:
        for i in range(x - 1):
            a, b = b, (a + b)% 10
        return b

def fibo_partial_sum(m, n):
    if m == n:	return find_fibo(m % 60)
    else:
        m %= 60
        n %= 60
        m = find_fibo(m + 1) - 1
        n = find_fibo(n + 2) - 1
        return (n - m) % 10

if __name__ == '__main__':
    m, n = map(int, input().split())
    print (fibo_partial_sum(m, n))
