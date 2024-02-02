// pr2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;
//zd1
int* Index() {
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = 1 + rand() % 5;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << "\n";
    }
    int number;
    cout << "Введите число , для поиска индекса этого числа в массиве\n";
    cin >> number;
    cout << "Индексы где встретилось" << number << endl;
    int n = 0;
    for (int i = 0; i < 10; i++) {
        if (array[i] == number) {
            n = i;
            cout << n << "\n";
            n = 0;
        }
    }
    return 0;
}
//zd2
int Sum() {
    cout << "Вот трехмерный массив заполненный на рандоме\n";
    int array[3][3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                array[i][j][k] = 1 + rand() % 5;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << endl;
            for (int k = 0; k < 3; k++) {
                cout << array[i][j][k] << " ";
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                
                res += array[i][j][k];
            }
        }
    }
    cout << "\nсумма =" << res;
    return 0;
}
//zd3
int CheckClassic() {

    struct Movie {
    char titel[20],director[20];
    int year;
    };
    Movie movies[] = {
       {"movie1", "боевик", 2004},
       {"movie2", "классика", 1996},
       {"movie3", "ужасы", 2001},
       {"movie4", "классика", 1995},
       {"movie5", "классика", 2008}
    };
    char userChoice[20];
    cout << "Введите название фильма: \n";
    cin >> userChoice;

    bool found = false;
    for (int i = 0; i < size(movies) ; i++) {
        if (strcmp(movies[i].titel, userChoice) == 0) {
            
            if (strcmp(movies[i].director, "классика") == 0) {
                std::cout << "фильм является классикой.\n";
            }
            else {
                std::cout << "фильм не является классикой.\n";
            }
            found = true;
            break; // Завершаем цикл, так как фильм уже найден
        }
    }

    if (!found) {
        std::cout << "Фильм с названием \"" << userChoice << "\" не найден.\n";
    }
    return 0;
}
//zd4

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber(double realPart, double imaginaryPart) {
        real = realPart;
        imaginary = imaginaryPart;
    }
    void addition(ComplexNumber a, ComplexNumber b) {
        double real = a.real + b.real;
        double imaginary = a.imaginary + b.imaginary;
        ComplexNumber c = ComplexNumber(real, imaginary);
        cout << "a+b = " << c.real << " + (" << c.imaginary << ")i" << endl;
    }
    void subtraction(ComplexNumber a, ComplexNumber b) {
        double real = a.real - b.real;
        double imaginary = a.imaginary - b.imaginary;
        ComplexNumber c = ComplexNumber(real, imaginary);
        cout << "a-b = " << c.real << " + (" << c.imaginary << ")i" << endl;
    }
    void multiplycation(ComplexNumber a, ComplexNumber b) {
        double real = a.real * b.real - a.imaginary * b.imaginary;
        double imaginary = a.imaginary * b.real + a.real * b.imaginary;
        ComplexNumber c = ComplexNumber(real, imaginary);
        cout << "a*b = " << c.real << " + (" << c.imaginary << ")i" << endl;
    }
    void division(ComplexNumber a, ComplexNumber b) {

        double real = (a.real * b.real + a.imaginary * b.imaginary) / (b.real * b.real + b.imaginary * b.imaginary);
        double imaginary = (a.imaginary * b.real - a.real * b.imaginary) / (b.real * b.real + b.imaginary * b.imaginary);
        ComplexNumber c = ComplexNumber(real, imaginary);
        cout << "a/b = " << c.real << " + (" << c.imaginary << ")i" << endl;
    }

};
int main()
{
    setlocale(LC_ALL, "Russian");
    int code = 0;           
        do{
            cout << "\nДля выбора задание введите цифру соответствующую номеру задачи(1/2/3/4)\n";       
            cin >> code;        
            if (code == 1) {
                Index();
        }        
            else if (code == 2) {
                Sum();
                 
            }
        else if (code == 3) {
                CheckClassic();
            
        }
        else if (code == 4) {
                double realA;
                double imaginaryA;
                double realB;
                double imaginaryB;
                cout << "введите первое действительное число, первое мнимое число, второе действительное и второе мнимое  ";
                cin >> realA >> imaginaryA >> realB >> imaginaryB;
                cout << endl;
                ComplexNumber a = ComplexNumber(realA, imaginaryA);
                ComplexNumber b = ComplexNumber(realB, imaginaryB);
                a.addition(a, b);
                a.subtraction(a, b);
                a.multiplycation(a, b);
                a.division(a, b);
        }
    } while (code == 1 || code == 2||code==3||code==4);
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
