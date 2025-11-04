#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream> 

using namespace std;

struct Student {
    string PIB;
    string group;
    double avgMark;
};

int main() {
    const int N = 3;
    Student students[N];

    cout << "Введіть дані про 3 студентів:\n";
    for (int i = 0; i < N; i++) {
        cout << "\nСтудент " << i + 1 << ":\n";
        cout << "ПІБ: ";
        getline(cin >> ws, students[i].PIB);
        cout << "Номер групи: ";
        getline(cin, students[i].group);
        cout << "Середній бал: ";
        cin >> students[i].avgMark;
    }

    sort(students, students + N, [](Student a, Student b) {
        return a.avgMark > b.avgMark;
        });

    ofstream fout("results.txt");

    if (!fout) {
        cout << "Помилка! Не вдалося створити файл results.txt" << endl;
        return 1;
    }

    cout << "\n=====================================================\n";
    cout << "| П.І.П.                       | Група    | Середній бал |\n";
    cout << "=====================================================\n";

    fout << "=====================================================\n";
    fout << "| П.І.П.                       | Група    | Середній бал |\n";
    fout << "=====================================================\n";

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (students[i].avgMark > 4.0) {
            cout.setf(ios::left);
            cout.width(28); cout << ("| " + students[i].PIB);
            cout.width(10); cout << ("| " + students[i].group);
            cout.width(15); cout << ("| " + to_string(students[i].avgMark).substr(0, 4));
            cout << " |\n";
            
            fout.setf(ios::left);
            fout.width(28); fout << ("| " + students[i].PIB);
            fout.width(10); fout << ("| " + students[i].group);
            fout.width(15); fout << ("| " + to_string(students[i].avgMark).substr(0, 4));
            fout << " |\n";
            
            found = true;
        }
    }

    cout << "=====================================================\n";
    fout << "=====================================================\n";

    if (!found) {
        cout << "Немає студентів із середнім балом більше 4.0.\n";
        fout << "Немає студентів із середнім балом більше 4.0.\n";
    }

    fout.close();

    cout << "\nРезультати також було записано у файл results.txt" << endl;

    return 0;
}