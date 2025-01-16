# scripts/visualize_results.py
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load the data
df = pd.read_csv("data/result.csv")

# Set the seaborn style
sns.set(style="whitegrid")

# Create a color palette
palette = sns.color_palette("husl", len(df["Algorithm"].unique()))

# Plot each algorithm with different styles
plt.figure(figsize=(12, 8))
for i, algo in enumerate(df["Algorithm"].unique()):
    subset = df[df["Algorithm"] == algo]
    sns.lineplot(
        x=subset["Array Size"],
        y=subset["Execution Time"] * 1000,
        label=algo,
        color=palette[i],
        marker="o",
        linestyle="-",
    )

# Add labels and title
plt.xlabel("Array Size", fontsize=14)
plt.ylabel("Execution Time (ms)", fontsize=14)
plt.title("Sorting Algorithm Performance", fontsize=16)

# Customize the legend
plt.legend(title="Algorithm", title_fontsize="13", fontsize="11")

# Add grid lines
plt.grid(True, linestyle="--", alpha=0.7)

# Show the plot
plt.tight_layout()
plt.show()
