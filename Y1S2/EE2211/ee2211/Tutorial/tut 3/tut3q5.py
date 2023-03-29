from scipy import stats

mean = 30 #mean = 30
sigma = 1.8 #standard deviation  = 1.8
x1 = 28 #lower bound = 28
x2 = 33 #upper bound = 33

#scipy.stats.norm
#function creates a normal gaussian continuous random variable
#.cdf returns the cumulative distribution function

#using cdf function saves us the trouble of finding 'area under the curve'

#calculate probability from 0 to lower bound
p_lower = stats.norm.cdf(x1, mean, sigma)

#calculate probability from 0 to upper bound
p_upper = stats.norm.cdf(x2, mean, sigma)

ans = p_upper - p_lower

print('\n')
print (f'Normal distribution: mean = {mean}, std dev = {sigma} \n')
print(f'probability of occuring between {x1} and {x2}:')
print(f'--> inside interval pin = {round(ans*100,1)}%')
print(f'--> outside interval pout = {round((1-ans)*100,1)}% \n')
print('\n')
print(p_lower)
print(p_upper)
print(ans)