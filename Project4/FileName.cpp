#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;

bool isvowel(char c) {
    c = tolower(c); 
    return (c == 'a'  c == 'e'  c == 'i'  c == 'o'  c == 'u'  c == 'а'  c == 'е'  c == 'ё'  c == 'и'  c == 'o'  c == 'у'  c == 'ы'  c == 'э'
        c == 'ю'  c == 'я');
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    int maxlen = 0;
    int curlen = 0;
    for (char c : text) {
        if (iswalpha(c)) {
            curlen++;
            maxlen = max(maxlen, curlen);
        }
        else {
            curlen = 0;
        }
    }
    cout << "Максимальная длина: " << maxlen << " букв(ы)" << "\n";

    int twochars = 0;
    string word;
    for (char c : text) {
        if (iswalpha(c)) {
            word += c;
        }
        else {
            if (word.length() > 1) {
                bool hastwo = false;
                for (size_t i = 0; i < word.length() - 1; ++i) {
                    if (!isvowel(word[i]) && !isvowel(word[i + 1])) {
                        hastwo = true;
                        break;
                    }
                }
                if (hastwo) {
                    twochars++;
                }
            }
            word = "";
        }
    }


    if (word.length() > 1) {
        bool hastwo = false;
        for (size_t i = 0; i < word.length() - 1; ++i) {
            if (!isvowel(word[i]) && !isvowel(word[i + 1])) {
                hastwo = true;
                break;
            }
        }
        if (hastwo) {
            twochars++;
        }
    }

    cout << "Количество слов с удвоенной согласной: " << twochars << endl;

    return 0;
}