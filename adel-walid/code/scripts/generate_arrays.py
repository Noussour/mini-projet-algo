import random

def generate_arrays(file_path, sizes, max_value):
    with open(file_path, "w") as f:
        for size in sizes:
            array = [random.randint(0, max_value) for _ in range(size)]
            f.write(" ".join(map(str, array)) + "\n")

if __name__ == "__main__":
    sizes = [10, 100, 500, 1000]  # Arrays sizes
    max_value = 1000             # Maximum value in arrays
    generate_arrays("data/i+nput_arrays.txt", sizes, max_value)

