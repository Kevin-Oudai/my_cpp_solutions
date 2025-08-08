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
