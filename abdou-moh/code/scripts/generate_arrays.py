import random
import sys


def generate_arrays(file_path, sizes, max_value):
    with open(file_path, "w") as f:
        for size in sizes:
            array = [random.randint(0, max_value) for _ in range(size)]
            f.write(" ".join(map(str, array)) + "\n")

if __name__ == "__main__":
    # Get the list sizes from the user
    sizes_input = input("Enter the sizes of arrays (comma-separated): ")
    sizes = list(map(int, sizes_input.split(",")))
    max_value = 1000            # Maximum value in arrays
    generate_arrays("data/input_arrays.txt", sizes, max_value)