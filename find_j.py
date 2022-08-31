from math import sqrt

a = int(input("Enter a: "))
b = int(input("Enter b: "))
p = int(input("Enter p: "))
m = int(input("Enter m: "))
k = int(input("Enter k: "))
print()
print("Your equation is y^2 = x^3 +",a,"x +",b)
print()
for j in range(0, 1000):
        y = ((m*k+j)*(m*k+j)*(m*k+j) + a*(m*k+j) + b)
        temp = y
        y = y%p
        sqt = int(sqrt(y))
        if(sqt*sqt == y):
                break
x = (m*k+j)
print("x^3 +",a,"x +",b,"mod p => ",temp," (mod ",p,") => ",y)
print("sqrt(",y,") is",sqt)
print("Value of j is ",j)
print("Value of x is ",x)
print("Verification x/k => ",x,'/',k," => ",x/k)