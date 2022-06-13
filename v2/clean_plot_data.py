import pandas as pd
import matplotlib.pyplot as plt

dfb = pd.read_csv('bubble.csv')
dfb = dfb.sort_values('Num')
dfb = dfb.groupby('Num').mean().reset_index()

dfm = pd.read_csv('merge.csv')
dfm = dfm.sort_values('Num1')
dfm = dfm.groupby('Num1').mean().reset_index()

ax = dfb.plot(x='Num', y='Ordenament bombolla', linewidth=2)
dfm.plot(ax=ax, x='Num1', y='Ordenament per barreja', linewidth=2)
ax.ticklabel_format(useOffset=False, style='plain')

#dfm.plot(x='Num1', y='Ordenament per barreja', linewidth=2)

plt.title("Complexitat Temporal dels Algoritmes")
plt.xlabel("Quantitat de dades")
plt.ylabel("Temps en segons")

plt.grid('on')

plt.show()
plt.savefig("plot.png")
