class Node:
    def __init__(self,num,den):
        self.num = num
        self.den = den
    
    def __str__(self):
        return f"{self.num}/{self.den}"

def addNodes(node1, node2):
    return Node(node1.num+node2.num,node1.den+node2.den)

t = int(input())
for _ in range(t):
    left = Node(0,1)
    right = Node(1,0)
    root = Node(1,1)
    path = input()
    ans = None
    for i in path:
        if i=="R":
            ans = addNodes(root,right)
            left = root
            root = ans
        else:
            ans = addNodes(left,root)
            right = root
            root = ans
    print(ans)
            
        
