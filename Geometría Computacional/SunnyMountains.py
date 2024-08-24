#https://vjudge.net/problem/UVA-920
class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    
    def __str__(self):
        return f"({self.x},{self.y}) "

def pendiente(p1:Point,p2:Point):
    return (p1.y - p2.y)/(p1.x-p2.x)


def eqLine(y, p1,p2):
    m = pendiente(p1,p2)
    return (y-p1.y+m*p1.x)/m
    
dist = lambda p1,p2 : ((p1.x-p2.x)**2 + (p1.y-p2.y)**2)**0.5

t = int(input())
for _ in range(t):
    n = int(input())
    arr = []
    for i in range(n):
        x,y = [int(j) for j in input().split()]
        arr.append(Point(x,y))
    arr.sort(key=lambda p: p.x)
    ans = dist(arr[-1],arr[-2])
    maxi = arr[-2]
    for i in reversed(range(0,n-2)):
        p1 = arr[i]
        if p1.y<=maxi.y:
            continue
        p2 = arr[i+1]
        p3 = Point(eqLine(maxi.y, p1, p2),maxi.y)
        ans+=dist(p1,p3)
        maxi = p1
    print(f"{ans:.2f}")














