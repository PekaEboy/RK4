#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Вывести первое название файла: ";
    char name1[100];
    char name2[100];
    ofstream lout;
    ifstream lin;
    int t;
    cin.getline(name1, 100);
    lout.open(name1, ios::binary);
    cout << "Вывести второе название файла: ";
    cin.getline(name2, 100);
    cout << "Вывести последовательность чисел: ";
    do {
        cin >> t;
        lout.write((char*)&t, sizeof(t));
    } while (t != 0);
    lout.close();
    lin.open(name1, ios::binary);
    lin.read((char*)&t, sizeof(int));
    int n = 0;
    do {
        cout << t << " ";
        n++;
        lin.read((char*)&t, sizeof(int));
    } while (t);
    lin.close();
    cout << endl;
    int m = n / 2;
    lout.open(name2, ios::binary);
    for (int i = 0; i < m; i++) {
        lin.open(name1, ios::binary);
        for (int j = 0; j <= i; j++) {
            lin.read((char*)&t, sizeof(int));
        }
        lout.write((char*)&t, sizeof(t));
        for (int j = 0; j < n-i-i-1; j++) {
            lin.read((char*)&t, sizeof(int));
        }
        lout.write((char*)&t, sizeof(t));
        lin.close();
    }
    if (n % 2) {
        lin.open(name1, ios::binary);
        for (int j = 0; j <= m; j++) {
            lin.read((char*)&t, sizeof(int));
        }
        lin.close();
        lout.write((char*)&t, sizeof(t));
    }
    lout.close();
    lin.open(name2, ios::binary);
    lin.read((char*)&t, sizeof(int));
    for(int i = 0; i < n; i++) {
        cout << t << " ";
        lin.read((char*)&t, sizeof(int));
    }
    return 0;
}
