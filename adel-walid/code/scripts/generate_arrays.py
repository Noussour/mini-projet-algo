import random


def generate_arrays(file_path, sizes, max_value):
    """Generate arrays of random integers and write them to a file.

    Args:
        file_path (str): The path to the output file.
        sizes (list of int): A list of sizes for the arrays to generate.
        max_value (int): The maximum value for the random integers.
    """
    try:
        with open(file_path, "w") as f:
            for size in sizes:
                array = [random.randint(0, max_value) for _ in range(size)]
                f.write(" ".join(map(str, array)) + "\n")
    except IOError as e:
        print(f"Error writing to file {file_path}: {e}")


if __name__ == "__main__":
    sizes = [100, 300, 500, 800, 1000, 1300, 1500, 2000, 2500]  # Array sizes
    max_value = 1000  # Maximum value in arrays
    generate_arrays("data/input_arrays.txt", sizes, max_value)
