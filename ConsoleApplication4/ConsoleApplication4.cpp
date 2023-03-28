#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    // Устанавливаем сид для генератора случайных чисел
    srand(time(NULL));

    // Создаем массив символов, включающий буквы, цифры, знаки препинания и заглавные буквы
    const char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+-=[]{};':\",.<>/?";

    // Создаем строку длиной 10 символов для хранения случайной строки
    char random_string[11];

    // Генерируем случайную строку
    for (int i = 0; i < 10; i++) {
        int index = rand() % strlen(symbols);
        random_string[i] = symbols[index];
    }
    random_string[10] = '\0'; // Добавляем конец строки

    // Копируем случайную строку в буфер обмена
    if (!OpenClipboard(NULL)) {
        cout << "Ошибка открытия буфера обмена" << endl;
        return 1;
    }

    EmptyClipboard();
    HGLOBAL hClipboardData;
    hClipboardData = GlobalAlloc(GMEM_DDESHARE, 11);
    char* pchData;
    pchData = (char*)GlobalLock(hClipboardData);
    strcpy(pchData, random_string);
    GlobalUnlock(hClipboardData);
    SetClipboardData(CF_TEXT, hClipboardData);
    CloseClipboard();

    cout << "Случайная строка " << random_string << " успешно скопирована в буфер обмена." << endl;

    return 0;
}