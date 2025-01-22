# scripts/visualize_results.py
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("data/result.csv")
for algo in df["Algorithm"].unique():
    subset = df[df["Algorithm"] == algo]
    plt.plot(subset["Array Size"], subset["Execution Time"], label=algo)

plt.xlabel("Array Size")
plt.ylabel("Execution Time (s)")
plt.title("Sorting Algorithm Performance")
plt.legend()
plt.savefig('images/plot.png')
print("Plot saved to plot.png")

