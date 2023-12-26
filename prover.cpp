#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    /*int a, b, n;
    int max, max2,max3,max4;
    cout << "Введите 4\n";
    cin >> max >> max2 >> max3 >> max4;
    if (max > max2 && max > max3 && max > max4)
    cout << "наибольш число\n" << max;
    else if (max2 > max3 && max2 > max4)
    cout << "наибольш число\n" << max2;
    else if (max3 > max4)
    cout << "наибольш число\n" << max3;
    else
    cout << "наибольш число\n" << max4;*/


    /*int a, b, n;
    cout << "Введите диапозон\n";
    cin >> a;
    cout << "Введите диапозон\n";
    cin >> b;
    cout << "Введите число\n";
    cin >> n;
    if (a > b) swap(a, b);
    if (b - a < n) n = b - a;
    for (int  i = a; i < a; i++);
        for (int j = 0;j < n; j++);
    cout << n;*/


    /*float max0;
    cout << "Введите число";
    cin >> max0;
    if (max0 < 0) cout << "";
    else {
        for (int i = 0; i < max0; i += 0.25)

            cout << endl << i;
    }*/


    /*int znac, sred, sum = 0, cou = 0;
    do {
        cout << "Введите число: ";
        cin >> znac;
        cou++;
        sum += znac;
    } while (znac = !0);
        cou--;
    cout << "среднее арфм число: " << sum / cou;*/


    /*char bukv;
    cout << "Введите символ: ";
    cin >> bukv;
    if (bukv >= 'a' && bukv <= 'z' || bukv >= 'A' && bukv <= 'Z')
        cout << "Вы ввели маленькую букву из англ";
    else
        cout << "Вы ввели большую букву из англ";*/


    ///*int mas[10], min = 7, max = 18;
    //for (int i = 0; i < 10; i++) {
    //    mas[i] = min + rand() % (max + 1 - min);
    //    cout << mas[i];*/
    //    
    //}

    /*cout << endl;
    int char_mas[10] = {};
    for (int j = 0, i = 0; i < 10; i++) {
        if (mas[i] % 2 == 0) {
            char_mas[j++] == mas[i];
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << char_mas[i] << endl;
    }*/


    int razm;
    cout << "Введите развер квадрата: ";
    cin >> razm;
    if (razm % 2 == 0) razm++;
    for (int i = 0; i < razm; i++) cout << '0';
    cout << endl;
    for (int j = 0; j < razm - 2 / 2; j++) {
        cout << " ";
        cout << " 0";
    }
    
}

