from math import factorial

if __name__ == '__main__':
    t = int(raw_input())
    while t:
        n = int(raw_input())
        print factorial(n)
        t-=1
