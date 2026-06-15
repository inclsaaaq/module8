#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

namespace utils {
    template<typename Type>
    void deleteFromArr(Type*& arr,int& size,const Type& value) {
        int newSize = 0;

        for (uint8_t i = 0; i < size;i++)
            if (*(arr + i) != value)
                newSize++;


        Type* newArr = new Type[newSize];

        for (uint8_t i = 0, j = 0; i < size; i++) {
            if (*(arr + i) != value)
                *(newArr + j++) = *(arr + i);
        }


        delete[] arr;

        arr = newArr;
        size = newSize;
    }
}

void e1() {
    std::string* students = new std::string[5];

    for (uint8_t i = 0;i <5;i++) {
        std::string f;
        std::cout << "\nвведи фамилию: ";
        std::cin >> f;

        students[i] = f;
    }

    std::sort(students, students + 5);


    std::cout << "\nотсортированный массив {\n";

    for (uint8_t i = 0; i<5;i++)
        std::cout << students[i] << std::endl;

    std::cout << "\n}\n";
}


void e2() {
    uint8_t rows = 4,cols = 8;

    int** arr = new int*[rows];

    for (uint8_t i = 0 ;i < rows;i++)
        arr[i] = new int[cols];

    std::cout << "начальный массив:\n{\n";
    for (uint8_t i = 0 ; i < rows;i++) {
        for (uint8_t j = 0 ; j < cols;j++) {
            arr[i][j] = rand() % 11;
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "}\n";


    std::cout << "финальный массив:\n{\n";
    int rowSize;
    for (uint8_t i = 0 ; i < rows;i++) {
        rowSize = cols;

        utils::deleteFromArr(arr[i],rowSize,0);

        for (uint8_t j = 0 ; j < rowSize;j++) {
            std::cout << arr[i][j] << ' ';
        }

        std::cout << std::endl;
    }
    std::cout << "}\n";
}

int main() {
    srand(time(0));
    e1();
    e2();
}