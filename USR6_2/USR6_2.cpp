#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = 1 + rand() % 50;
    }
}

int main() {
    int size;
    bool isCorrect = false;
    while (!isCorrect) {
        cout << "Введите размер массива: ";
        cin >> size;
        if (size % 2 == 0) {
            isCorrect = true;
        }
        else {
            system("cls");
            cout << "Введите чётное число!" << endl;
        }
    }
    
    int* arr = new int[size];
    fillArray(arr, size);

    cout << "Исходный массив:\n";
    printArray(arr, size);

    int middle = size / 2;
    
    int* arr_upper = new int[middle];
    int* arr_lower = new int[middle];

    

    // Запись в массивы
    for (int i = 0; i < middle; i++) {
        arr_upper[i] = arr[i];
    }

    for (int i = 0; i < middle; i++) {
        arr_lower[i] = arr[i + middle];
    }


    // Сортировка по возрастанию
    for (int i = 0; i < middle; i++) {
        for (int j = i + 1; j < middle; j++) {
            if (arr_upper[i] > arr_upper[j]) {
                swap(arr_upper[i], arr_upper[j]);
            }
        }
    }
    cout << "Upper: ";
    printArray(arr_upper, middle);


    // Сортировка по убыванию
    for (int i = 0; i < middle; i++) {
        for (int j = i + 1; j < middle; j++) {
            if (arr_lower[i] < arr_lower[j]) {
                swap(arr_lower[i], arr_lower[j]);
            }
        }
    }
    cout << "Lower: ";
    printArray(arr_lower, middle);

    for (int i = 0; i < size; i++) {
        if (i < middle) {
            arr[i] = arr_upper[i];
        }
        else {
            arr[i] = arr_lower[i - middle];
        }
    }
    cout << "Результат сортировки змейкой: " << endl;
    printArray(arr, size);

    delete[] arr, arr_upper, arr_lower;
}