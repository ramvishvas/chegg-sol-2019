N = int(input("Enter N: "))
M = int(input("Enter M: "))
Number = input("Enter Number: ")

Number = Number[Number.index('{') + 1:Number.index('}')].split()
Array = [int(i) for i in Number]
print(N, M, Array);