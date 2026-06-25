#include "mod.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const char* filename = "C:/Users/dyatl/source/repos/task5/data.txt";

    int result = countShortWords(filename);
    if (result == -1) {
        cout << "Ошибка: не удалось открыть файл." << endl;
        return 1;
    }

    cout << "Количество слов из не более чем 4 букв: " << result << endl;
    return 0;
}
