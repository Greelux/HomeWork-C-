#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

#define DEBUG

#define INIT_ARRAY(arr, size)                     \
    do {                                          \
        srand(time(0));    \
        for (int i = 0; i < size; ++i) {          \
            arr[i] = rand() % 100;                \
        }                                         \
    } while (0)

#define PRINT_ARRAY(arr, size)                    \
    do {                                          \
        for (int i = 0; i < size; ++i) {          \
            cout << arr[i] << " ";           \
        }                                         \
        cout << endl;                   \
    } while (0)

#define ARRAY_AVERAGE(arr, size, result)          \
    do {                                          \
        int sum = 0;                              \
        for (int i = 0; i < size; ++i) {          \
            sum += arr[i];                        \
        }                                         \
        result = static_cast<double>(sum) / size; \
    } while (0)

#ifdef DEBUG
#define LOG(message)                              \
    do {                                          \
        cout << "[DEBUG]: " << message <<endl; \
    } while (0)
#else
#define LOG(message)
#endif

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");
    const int size = 10;  
    int arr[size];        

    LOG("Ініціалізація масиву...");
    INIT_ARRAY(arr, size);

    LOG("Виведення масиву:");
    PRINT_ARRAY(arr, size);

    LOG("Обчислення середнього значення...");
    double average = 0.0;
    ARRAY_AVERAGE(arr, size, average);
    LOG("Середнє значення обчислено.");

    cout << "Середнє значення: " << average <<endl;

    return 0;


}
