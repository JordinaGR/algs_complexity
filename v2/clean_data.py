import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('bubble.csv')

df = df.sort_values('Num')
df = df.groupby('Num').mean().reset_index()

df.plot(x='Num', y='Time')
plt.title("n i temps en executar un bubble sort f(n)=n²")
plt.xlabel("mida input n")
plt.ylabel("temps en segons")

plt.show()
plt.savefig("bubble_sort.png")
