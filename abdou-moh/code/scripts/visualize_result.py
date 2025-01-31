# scripts/visualize_results.py
import pandas as pd

import matplotlib.pyplot as plt
from datetime import datetime
import os
import matplotlib
matplotlib.use('TkAgg')  # Or 'Qt5Agg' for Qt5

from screeninfo import get_monitors

# Get screen resolution
monitor = get_monitors()[0]  # Use the primary monitor
screen_width, screen_height = monitor.width, monitor.height

# Set figure size to full screen
plt.figure(figsize=(screen_width / 100, screen_height / 100))  # Divide by 100 for scaling

# Read the CSV file
df = pd.read_csv("data/result.csv")

# Create the images directory if it doesn't exist
os.makedirs("images", exist_ok=True)

# Generate a unique filename using a timestamp
timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
filename = f"images/plot_{timestamp}.png"

# Plot the results
for algo in df["Algorithm"].unique():
    subset = df[df["Algorithm"] == algo]
    plt.plot(subset["Array Size"], subset["Execution Time"], label=algo)

plt.xlabel("Array Size")
plt.ylabel("Execution Time (s)")
plt.title("Sorting Algorithm Performance")
plt.legend()

# Save the plot with the unique filename
plt.savefig(filename)
print(f"Plot saved to {filename}")




plt.show()