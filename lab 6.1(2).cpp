#include <iostream>
#include <iomanip>

using namespace std;

void Print(int* list, const int size, int i);
void Processing(int* list, const int size, int& sum, int& count, int i);
void Create(int* list, const int size, const int Min, const int Max, int i);

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    srand((unsigned)time(NULL));

    //srand(1); // для перевірки правильності способів

    const int n = 25;
    int c[n] = { 1 };

    int Min = 5;
    int Max = 90;

    int sum = 0;
    int count = 0;

    cout << "Рекурсивний спосiб" << endl;
    cout << endl;

    Create(c, n, Min, Max, 0);
    cout << "Before: "; Print(c, n, 0);

    Processing(c, n, sum, count, 0);
    cout << "After:  "; Print(c, n, 0);

    cout << endl;

    cout << "Sum: " << setw(4) << sum << endl
        << "Count: " << setw(2) << count << endl;
}

void Create(int* list, const int size, const int Min, const int Max, int i) {
    if (i < size)
    {
        list[i] = rand() % (Max - Min + 1) + Min;
        return Create(list, size, Min, Max, ++i);
    }
}

void Processing(int* list, const int size, int& sum, int& count, int i) {
    if (i < size) {
        if (!(list[i] % 2) || i % 8 != 0) { // парний або індекс не кратрий 8
            sum += list[i];
            list[i] = 0;
            count++;
        }

        Processing(list, size, sum, count, ++i);
    }
}

void Print(int* list, const int size, int i)
{
    if (i < size) {
        cout << setw(3) << list[i];
        return Print(list, size, ++i);
    }
    cout << endl;
}