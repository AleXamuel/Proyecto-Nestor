res = lambda x: ((x*(x+1))//2)+1
while True:
    n = int(input())
    if n<0:
        break
    print(res(n))
