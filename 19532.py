#x만 구하고 y에는 대입하려고 했는데 런타임 에러 뜸 
a,b,c,d,e,f = map(int,input().split())
x = (c*e-b*f)//(a*e-b*d)
y =(a*f-c*d)//(a*e-b*d)
print(x,y)
