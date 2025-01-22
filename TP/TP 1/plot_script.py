import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv("data.csv")

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(data['n'], data['Execution Time (seconds)'], marker='o', linestyle='-', color='b')
plt.xlabel('n')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time vs n')
plt.grid(True)
plt.xscale('log')  # Use logarithmic scale for x-axis (since n values are large)
plt.yscale('log')  # Use logarithmic scale for y-axis (if execution times vary widely)
plt.show()