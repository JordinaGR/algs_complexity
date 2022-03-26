import matplotlib.pyplot as plt

x = [0, 10, 100, 1000, 10000,  40000,  60000, 80000, 100000]
y = [0, 1,  59,  5805, 621536, 9914011,22068634,39835968,60594981]

plt.plot(x, y, 'ro')
plt.title("n i temps en executar un bubble sort f(n)=n²")
plt.xlabel("mida input n")
plt.ylabel("temps en milisegons")

plt.savefig("bubble_sort.png")
plt.show()
