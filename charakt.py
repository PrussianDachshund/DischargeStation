import numpy
import pandas as pd
from matplotlib import pyplot as plt

df = pd.DataFrame
colnames = ['start', 'timestamp', 'voltage','Nan']
df = pd.read_csv("Optima_Battery_8004_250v2.txt", delimiter=";",names=colnames)
df = df.drop('Nan',axis=1)
#print(df)
df = df.drop(len(df)-1, axis=0)
#print(df)

for ind in df.index:
    df.loc[ind,'start'] = float(df['start'][ind])/1000
    df.loc[ind,'timestamp'] = float(df['timestamp'][ind]/1000/3600)
    df.loc[ind,'voltage'] = float(df['voltage'][ind]+0.3)

print(df)

fig, ax = plt.subplots()
ax.plot(df['timestamp'], df['voltage'], linewidth = 0.5)


plt.grid(True)
plt.ylabel("Voltage [V]")
plt.xlabel("Time [h]")
plt.title("Discharge Characteristics")
plt.show()