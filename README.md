# 🔢 BigInteger Implementation in C++

Welcome to the **BigInteger** 🚀 repository! This project is a **custom implementation of large integer arithmetic** using C++, mimicking Java's `BigInteger` class — ideal for handling numbers beyond native `int` or `long long` limits.

---

## 📦 Features

| **Feature**         | **Icon** | **Details**                                |
|---------------------|----------|--------------------------------------------|
| Arbitrary Precision | 🧠       | Handles integers of virtually any size     |
| Operator Overloading | ➕➖✖️➗  | Supports `+`, `-`, `*`, `/`, `%`            |
| Clean OOP Design     | 🧱       | Class-based structure for scalability      |

---

## 🏗️ Class Overview

```cpp
class BigInteger {
public:
    BigInteger(); // Default Constructor
    BigInteger(std::string val); // Initialize from string

    // Core Arithmetic Operators
    BigInteger operator+(const BigInteger&) const;
    BigInteger operator-(const BigInteger&) const;
    BigInteger operator*(const BigInteger&) const;
    BigInteger operator/(const BigInteger&) const;
    BigInteger operator%(const BigInteger&) const;

    // Utility
    std::string toString() const;
};
