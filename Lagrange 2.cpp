#include <iostream>
#include <fstream>
#include <math.h>
#include<string>

using namespace std;

double lagrangeInterpolation(double* xs, double* ys, double x, int xsLength)
{
    double t;// tworzę zmienną tymczasową
    double  y = 0.0; // deklaracja y dla funkcji

    for (int i = 0; i < xsLength; i++)
    {
        t = 1.0;
        for (int j = 0; j < xsLength; j++)
        {
            if (j != i)
            {
                t = t * ((x - xs[j]) / (xs[i] - xs[j])); //t będziemy liczyć wyłącznie wtedy kiedy j jest różne od i (jest to nasz licznik i mianownik)
            }
        }
        y += t * ys[i];//następnie kiedy mamy tak jak pokazane jest to w przykładzie naszego zadania liczniki i mianowniki dodajemy je pomnożone przez y  i dodajemy do siebie
    }
    return y;
}


int main()
{
    double tab_x[4] = { 27, 64, 125, 216 };
    double tab_y[4];
    for (int i = 0; i < 4; i++)
    {
        tab_y[i] = pow(tab_x[i], 1.0 / 3);
    }
    double x;
    cout << "Podaj x dla ktorego chcesz policzyc zadanie = " << endl;
    cin >> x; //przypisanie x z klawiatury
    //ponizej znajduje się wypisanie danych ->
    cout << "Liczba wezlow = " << 4 << endl;

    for (int k = 0; k < 4; k++)
    {
        cout << k + 1 << ". Wezly interpolacji = " << tab_x[k] << endl;
        cout << k + 1 << ". Wartosci funkcji w wezlach = " << tab_y[k] << endl;
    }


    double y = lagrangeInterpolation(tab_x, tab_y, x, 4); //w tym miejscu wywołujemy funkcję obliczającą y, do funkcji wczytujemy tablicę x-ów i y-ów oraz parametr x i długość tablicy x
    cout << "x = " << x << "-> y = " << y << endl;
    return 0;
}

