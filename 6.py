n=int(input())
otvet=[]
for i in range (n):
    a,b,x,y=map(int, input().split())
    otvet.append(min(b,x)+abs(max(b,x)-(min(b,x)))+min((a - abs(max(b,x)-(min(b,x)))), y))
otvet=[str(x) for x in otvet]
print(' '.join(otvet))
