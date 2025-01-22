# Sorting Algorithms Project

This project implements, tests, and analyzes various sorting algorithms in C. It uses the **CUnit** library for unit testing and provides tools for performance evaluation and visualization.

## **Project Structure**

```
├── data
│   ├── input_arrays.txt   # Input arrays for sorting tests
│   └── result.csv         # CSV file with performance results
├── include
│   └── sorting.h          # Header file with function declarations
├── Makefile               # Build system for the project
├── README.md              # Project documentation
├── scripts
│   ├── generate_arrays.py # Python script to generate test arrays
│   └── visualize_result.py # Python script to visualize results
├── src
│   ├── bubble_sort.c      # Bubble Sort implementation
│   ├── gnome_sort.c       # Gnome Sort implementation
│   ├── heap_sort.c        # Heap Sort implementation
│   ├── quick_sort.c       # Quick Sort implementation
│   └── radix_sort.c       # Radix Sort implementation
└── test
    ├── bubble_sort_test.c # Unit tests for Bubble Sort
    ├── gnome_sort_test.c  # Unit tests for Gnome Sort
    ├── heap_sort_test.c   # Unit tests for Heap Sort
    ├── quick_sort_test.c  # Unit tests for Quick Sort
    └── radix_sort_test.c  # Unit tests for Radix Sort
```

---

## **Getting Started**

### **Prerequisites**

- **C Compiler**: GCC or Clang
- **CUnit Library**: Install using:
  - **Ubuntu/Debian**:
    ```bash
    sudo apt-get install libcunit1 libcunit1-dev
    ```
  - **macOS**:
    ```bash
    brew install cunit
    ```
  - **Windows or else**: Download and set up manually from [CUnit](https://gitlab.com/cunity/cunit).
- **Python** (optional for scripts):
  - Install dependencies for visualization:
    ```bash
    pip install matplotlib pandas
    ```

### **Building the Project**

Compile the main project executable:
```bash
make
```

### **Running Tests**

Run all tests:
```bash
make test
```

Run a specific test:
```bash
make run_test TEST_NAME=<test_name>
```
Replace `<test_name>` with the name of the test file (e.g., `bubble_sort_test`).

### **Cleaning Up**

Remove compiled files and directories:
```bash
make clean
```

---

## **Usage**

### **Input File Format**

The input file (e.g., `data/input_arrays.txt`) should contain arrays with space-separated integers, one array per line:
```
10 5 8 1 3 7 4 2 6 9
20 10 30 40 50
100 90 80 70 60 50
```

### **Generate Input Arrays**

Use the provided Python script to generate test arrays:
```bash
python3 scripts/generate_arrays.py
```

### **Visualize Results**

Use the visualization script to plot performance comparisons:
```bash
python3 scripts/visualize_result.py
```

---

## **Implemented Algorithms**

1. **Bubble Sort**: Simple comparison-based algorithm.
2. **Gnome Sort**: A variation of insertion sort.
3. **Heap Sort**: Utilizes a binary heap.
4. **Quick Sort**: Divide-and-conquer approach for efficient sorting.
5. **Radix Sort**: Non-comparison-based sorting for integers.

---

## **Testing Framework**

The project uses **CUnit** for unit testing. Each sorting algorithm has its own test file in the `test/` directory, and tests are automatically compiled and run using the `Makefile`.

---


