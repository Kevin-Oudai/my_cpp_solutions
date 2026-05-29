// Codex Prompt: Exercise 12.20 – Add Two Vectors (Using Templates)
//
// Write a complete C++ program in a single file named `main.cpp` that does the following:
//
// 1. Define a function template with the signature:
//      template <typename T>
//      void addVector(std::vector<T>& baseVector, std::vector<T>& addVector);
//
//    - The function adds each element of `addVector` to the corresponding element in `baseVector`.
//    - Both vectors are assumed to be the same size.
//    - The result is stored in `baseVector`.
//    - Use camelCase naming for function and variables.
//    - Do not return anything.
//
// 2. In the `main()` function:
//    - Declare two `std::vector<int>` variables named `firstVector` and `secondVector`, each with size 6.
//    - Prompt the user: "Enter 6 integers for the first vector:"
//    - Read values into `firstVector`.
//    - Prompt the user: "Enter 6 integers for the second vector:"
//    - Read values into `secondVector`.
//    - Call `addVector(firstVector, secondVector)`.
//    - Print the resulting `firstVector` with the label: "Resulting vector:"
//    - Display the elements separated by spaces.
//
// Use only C++ standard headers and features from C++17.
// Keep the code clean, beginner-friendly, and compile-ready.

#include <iostream>
#include <vector>

template <typename T>
void addVector(std::vector<T>& baseVector, std::vector<T>& addVector) {
    for (std::size_t i = 0; i < baseVector.size(); ++i) {
        baseVector[i] += addVector[i];
    }
}

int main() {
    std::vector<int> firstVector(6);
    std::vector<int> secondVector(6);

    std::cout << "Enter 6 integers for the first vector:" << std::endl;
    for (int& value : firstVector) {
        std::cin >> value;
    }

    std::cout << "Enter 6 integers for the second vector:" << std::endl;
    for (int& value : secondVector) {
        std::cin >> value;
    }

    addVector(firstVector, secondVector);

    std::cout << "Resulting vector:" << std::endl;
    for (const int& value : firstVector) {
        std::cout << value << ' ';
    }
    std::cout << std::endl;

    return 0;
}
