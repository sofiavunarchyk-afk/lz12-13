#include <iostream>  
#include <fstream>   
#include <clocale>   

using namespace std;

int main() {
    setlocale(LC_ALL, ".1251"); 

    ifstream inputFile("number.txt");

    // Перевірка, чи файл успішно відкрився (як у вашому прикладі)
    if (!inputFile) {
        // cerr - це потік для виводу помилок
        cerr << "Не вдалося відкрити файл 'number.txt' для читання." << endl;
        return 1; // Повертаємо 1, що означає помилку
    }

    int number; // Змінна для зчитування кожного числа з файлу
 
    long long dob = 1; // Початкове значення добутку = 1

    while (inputFile >> number) {
        
        if (number % 3 == 0) {
            dob = dob * number; // або dob *= number;
        }
    }

    inputFile.close();

 
    if (dob == 1) {
        cout << "У файлі не було чисел, кратних 3." << endl;
    } else {
        // Виводимо результат
        cout << "Добуток чисел, кратних 3, у файлі: " << dob << endl;
    }

    return 0; // Все пройшло успішно
}