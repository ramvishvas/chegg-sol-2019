import random
import math
myArray=[]
size= 50

# populate array with size=50  random integers
# in range 0-1 and repeat for 1000 times
for _ in range(1000):
	for k in range(size):
		randNum=random.randint(0,1)
		# add random number to list
		myArray.append(randNum)

#print myArray 50 values per line
for i in range(size):
	print(myArray[i*50 : (i+1)*50])

#display array size
print("\nSize of my array is: ",len(myArray))

# count 0's and 1's
count_of_0 = myArray.count(0)
count_of_1 = myArray.count(1)

print("\nNumber of 0’s is: ", count_of_0)
print("Number of 1’s is: ", count_of_1)

print("\nExpected mean (average) of the 0’s: ", count_of_0*size*.5)
print("Expected mean (average) of the 1’s: ", count_of_1*size*.5)

#calculate mean and SD of binomial distribution
#probability of occurence of 1 is p = 1/2 and occurence of 0 is q =1/2
#mean of Binomial distribution = np
#SD(standard deviation) of Binomial distribution = (npq)^1/2
#here n=50000
sd = math.sqrt(len(myArray)*0.5*0.5)
print("\nStandard Deviation (SD): ", sd)


# n=len(myArray)
# p=0.5
# q=0.5
# mean= n*p #expected mean of no of ones
# sd = math.sqrt(n*p*q)
# print("===============================")
# print("mean of 1s in My Array: ",mean," sd(standard deviation): ",sd)
# Lrange=int(round(mean-sd))
# Rrange=int(round(mean+sd))
# print("range: mean+-sd: ",Rrange," ",Lrange) #round off the range to nearest integer
# #check if no of ones is within range
# if(ones>= Lrange and ones<= Rrange):
# 	output="Yes"
# else:
# 	output="No"

# 	print("Actual number of ones is within the range mean+-sd ??? Ans is: ", output)