def gcd(a, b): return a if b == 0 else gcd(b, a % b)

if __name__ == '__main__':
    a, b = map(int, input().split())
    print (gcd(a, b))
