class Rectangle:
    def __init__(self, x1,y1,x2,y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
    
    def __str__(self):
        return f"({self.x1}, {self.y1}) ({self.x2}, {self.y2})"
        
class Circle:
    def __init__(self, x,y,r):
        self.x = x
        self.y = y
        self.r = r
    
    def __str__(self):
        return f"({self.x}, {self.y}, {self.r})"

class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    
    def __str__(self):
        return f"({self.x}, {self.y})"


def isInRectangle(p:Point,rec:Rectangle):
    isX = False
    isY = False
    if p.x>=rec.x1 and p.x<=rec.x2:
        isX = True
    if p.y>=rec.y1 and p.y<=rec.y2:
        isY = True
    return isX and isY

dist = lambda p1,p2: ((p1.x-p2.x)**2+(p1.y-p2.y)**2)**0.5

def isInCircle(p:Point,c:Circle):
    return dist(p,Point(c.x,c.y))<=c.r

rectangulos = []
circulos = []

m = int(input())
for _ in range(m):
    s = input().split()
    if s[0] == "rectangle":
        rectangulos.append(Rectangle(int(s[1]),int(s[2]),int(s[3]),int(s[4])))
    else:
        circulos.append(Circle(int(s[1]),int(s[2]),int(s[3])))

n = int(input())
for _ in range(n):
    x,y = [int(i) for i in input().split()]
    p = Point(x,y)
    c  = 0
    for i in rectangulos:
        if isInRectangle(p,i):
            c+=1
    for i in circulos:
        if isInCircle(p,i):
            c+=1
    print(c)
