#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;

bool isgood(char c) {
    c = tolower(c); 
    return (c == 'a' ||  c == 'e' ||  c == 'i' ||  c == 'o' ||  c == 'u' ||  c == 'а' ||  c == 'е' ||  c == 'ё' ||  c == 'и' ||  c == 'o' ||  c == 'у' ||  c == 'ы' ||  c == 'э' ||
        c == 'ю' ||  c == 'я');
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    int maxlen = 0;
    int curlen = 0;
    for (char c : text) {
        if (isalpha(c)==0 && c != ' ') {
            curlen++;
            maxlen = max(maxlen, curlen);
        }
        else {
            curlen = 0;
        }
    }
    cout << "Максимальная длина: " << maxlen << " символа(ов)" << "\n";

    int twochars = 0;
    string word;
    for (char c : text) {
        if (isalpha(c)) {
            word += c;
        }
        else {
            if (word.length() > 1) {
                bool hastwo = false;
                for (int i = 0; i < word.length() - 1; ++i) {
                    if ((!isgood(word[i]) && !isgood(word[i + 1] )) && (word[i]==word[i+1])) {
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
        for (int i = 0; i < word.length() - 1; ++i) {
            if (!isgood(word[i]) && !isgood(word[i + 1]) && (word[i] == word[i + 1])) {
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