arr = []
size = 7
j = 1

while j <= size:
    num = float(input("Enter "+str(j)+" Number: "))
    arr.append(num)
    j += 1

print('Array : ',arr)

for i in range(1, len(arr)): 
    keyValue = arr[i]
    j = i-1
    while j >=0 and keyValue < arr[j] : 
        arr[j+1] = arr[j] 
        j -= 1
        arr[j+1] = keyValue

print('Sorted Array : ',arr)
