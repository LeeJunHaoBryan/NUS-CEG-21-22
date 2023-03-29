import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv('/Users/bryanlee/Desktop/NUS/NUS Y2S1/ee2211/tut2/government-expenditure-on-education.csv')
print(df['total_expenditure_on_education'])

expenditure = df['total_expenditure_on_education']
year = df['year']
plt.plot(year,expenditure)
plt.xlabel('year')
plt.ylabel('expenditure')
plt.show()