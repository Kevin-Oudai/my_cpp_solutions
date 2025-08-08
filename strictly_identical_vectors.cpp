#include <iostream>
#include <vector>

template <typename T>
bool areStrictlyIdentical(std::vector<T>& v1, std::vector<T>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (std::size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int vectorSize;
    std::cout << "Enter the size of the vectors: " << std::endl;
    std::cin >> vectorSize;

    std::vector<int> firstVector(vectorSize);
    std::vector<int> secondVector(vectorSize);

    std::cout << "Enter elements of the first vector:" << std::endl;
    for (int& value : firstVector) {
        std::cin >> value;
    }

    std::cout << "Enter elements of the second vector:" << std::endl;
    for (int& value : secondVector) {
        std::cin >> value;
    }

    if (areStrictlyIdentical(firstVector, secondVector)) {
        std::cout << "The vectors are strictly identical." << std::endl;
    } else {
        std::cout << "The vectors are not strictly identical." << std::endl;
    }

    return 0;
}
