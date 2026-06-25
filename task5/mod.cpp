#include "mod.h"

int countLetters(const string& word) {
    int count = 0;
    for (char c : word)
        if (isalpha((unsigned char)c))
            count++;
    return count;
}

int countShortWords(const char* filename) {
    ifstream in(filename);
    if (!in.is_open()) return -1;

    string token;
    int count = 0;
    while (in >> token) {
        int letters = countLetters(token);
        if (letters >= 1 && letters <= 4)
            count++;
    }
    return count;
}
