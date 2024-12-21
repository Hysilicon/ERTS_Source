import pandas as pd
import matplotlib.pyplot as plt


data = pd.read_csv("lms_results.csv")

plt.figure(figsize=(10, 5))
plt.plot(data["Iteration"], data["Error"], label="Error Signal")
plt.plot(data["Iteration"], data["Output"], label="Output Signal", linestyle="--")
plt.title("LMS Filter Convergence")
plt.xlabel("Iteration")
plt.ylabel("Value")
plt.legend()
plt.grid()
plt.show()
