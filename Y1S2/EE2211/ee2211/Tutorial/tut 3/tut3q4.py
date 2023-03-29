#creating a dictionary {} --> dictionary, () --> tuple
#the two nested for loop iterates through all possible valuse of the dice (i = dice1, j = dice2)
#below generates a dictionary where key is dice-pair and value is sum of dice
#e.g (1,2) : 3 / (2,4) : 6
d = { (i,j) :i+j for i in range(1,7) for j in range(1,7) }
print(d)

#start by creating an empty dictionary.
#difference between defaultdict and typical dict is that when you try to access or modify
#a key that doesnt exits, a default value is given to that key

#code below creates an empty dictionary called dinv
from collections import defaultdict
dinv = defaultdict(list)

#in this code below, make use of d.items() to seperate the dice pair values from the sums.
#for each sum value from 2 to 12 (j), append all dice pair values(i)
for i,j in d.items() : dinv[j].append(i)

#to find the probability for each sum, find the number of pairs(len) and divide by 36
#in the code below, i now stands for sum value and j the dice pair values
X = {i:len(j)/36. for i,j in dinv.items()}
print(X)