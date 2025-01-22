# Lab 1: Algorithms, Programming, and Complexity

---

## Part I: Sum of the First N Natural Numbers

In this part, we revisit algorithms, programming, and complexity by solving a problem involving the calculation of the sum of the first \( n \) natural numbers. The problem is solved using **iterative programming**.

### Problem Statement
Develop an iterative algorithm and program to calculate the sum \( S \) of the first \( n \) natural numbers:
\[
S = \sum_{i=1}^{n} i = 1 + 2 + 3 + \dots + n
\]
where \( n \) is a natural integer read as input (\( n \geq 1 \)).

---

### 1. Iterative Algorithm (Sum_1)
The iterative algorithm, denoted **Sum_1**, uses a `while` loop to calculate the sum \( S \).

#### Algorithm Steps:
1. Read the input value \( n \) (ensure \( n \geq 1 \)).
2. Initialize a variable \( S \) to 0 to store the sum.
3. Initialize a counter variable \( i \) to 1.
4. Use a `while` loop to iterate from \( i = 1 \) to \( i = n \):
   - Add \( i \) to \( S \).
   - Increment \( i \) by 1.
5. Return the value of \( S \).

#### Pseudocode:
```
Sum_1(n):
    S = 0
    i = 1
    while i <= n:
        S = S + i
        i = i + 1
    return S
```

---

### 2. Time Complexity of the Algorithm
The time complexity of the algorithm **Sum_1** is determined by the number of iterations in the `while` loop.

- The loop runs \( n \) times (from \( i = 1 \) to \( i = n \)).
- Each iteration performs a constant number of operations (addition and increment).

Thus, the **time complexity** is:
\[
O(n)
\]

---

### 3. Space Complexity of the Algorithm
The space complexity is determined by the amount of memory used by the algorithm.

- The algorithm uses a constant amount of memory to store the variables \( S \), \( i \), and \( n \).
- No additional data structures are used.

Thus, the **space complexity** is:
\[
O(1)
\]

---

### 4. Iterative Program in C (PSum_1)
Below is the corresponding iterative program written in C. To handle large values of \( n \), the `double` type is used for the sum \( S \).

#### C Code:
```c
#include <stdio.h>

double PSum_1(int n) {
    double S = 0.0;
    int i = 1;
    while (i <= n) {
        S += i;
        i++;
    }
    return S;
}

int main() {
    int n;
    printf("Enter a natural number n (n >= 1): ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n must be greater than or equal to 1.\n");
        return 1;
    }

    double result = PSum_1(n);
    printf("The sum of the first %d natural numbers is: %.0f\n", n, result);

    return 0;
}
```

#### Explanation:
1. The function `PSum_1` implements the iterative algorithm using a `while` loop.
2. The `main` function reads the input \( n \), validates it, and calls `PSum_1` to compute the sum.
3. The result is printed as a double, but formatted to display as an integer using `%.0f`.

---
