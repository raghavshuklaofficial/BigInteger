
# 🔢 BigInteger Implementation in C

Welcome to the **BigInteger** 🚀 repository! This project is a **custom implementation of large integer arithmetic** using C, mimicking Java's `BigInteger` class — ideal for handling numbers beyond native `int` or `long long` limits.

---

## 📦 Features

| **Feature**                       | **Details**                                |
|-----------------------------------|--------------------------------------------|
| Arbitrary Precision 🧠            | Handles integers of virtually any size     |
| Operator Overloading ➕➖✖️➗    | Supports `+`, `-`, `*`, `/`, `%`            |
| Modular Code Structure  🧱        | Functions split into '.c' and '.h' for scalability     |

---
---

## 🚀 Getting Started

### 🧪 How to Compile & Run

```bash
gcc main.c BigInteger.c -o biginteger
./biginteger
```

---

## 📂 File Structure

```bash
BigInteger/
├── BigInteger.h        # Header file with class definition
├── BigInteger.c        # Class implementation
├── main.c              # Example/test driver
└── README.md           # Project documentation
```

---

## 🧪 Sample Usage

```c
#include "big_integer.h"

int main() {
    BigInt a = createBigInt("123456789123456789123456789");
    BigInt b = createBigInt("987654321987654321987654321");

    BigInt result = addBigInt(a, b);
    printBigInt(result);

    return 0;
}
```
---

## 👤 Author

**Raghav Shukla**
📌 [GitHub Profile](https://github.com/raghavshuklaofficial)

---

## 🙌 Contributions Welcome

Got improvements or bugs to report?
Feel free to **fork**, **star**, and send a **pull request** 🚀

---

> 💬 *“Code without limits. Numbers beyond imagination.”*

```
