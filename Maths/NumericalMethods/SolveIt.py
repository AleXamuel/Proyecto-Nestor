#https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1282
from math import e,sin,cos,tan

def f(x,p,q,r,s,t,u):
    return p*e**(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x**2+u

def biseccion(f,p,q,r,s,t,u,a,b): 
    for _ in range(100):
        if f(a,p,q,r,s,t,u)==0:
            return f"{a:.4f}"
        
        if f(b,p,q,r,s,t,u)==0:
            return f"{b:.4f}"
        
        if f(a,p,q,r,s,t,u) * f(b,p,q,r,s,t,u) < 0:
            mid = (a+b) / 2
            if f(mid,p,q,r,s,t,u) == 0:
                return f"{mid:.4f}"
            else:
                if f(a,p,q,r,s,t,u) * f(mid,p,q,r,s,t,u) < 0:
                    b = mid
                else:
                    a = mid
        else:
            return "No solution"
        
    return f"{mid:.4f}"


while True:
    try:
        p, q, r, s, t ,u = [int(i) for i in input().split()]
        print(biseccion(f,p,q,r,s,t,u,0,1))
    except:
        break
