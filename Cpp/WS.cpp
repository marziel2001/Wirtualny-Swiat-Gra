#pragma once

#include "../naglowkowe/Swiat.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    srand(time(NULL));
    
    Swiat* swiat1 = nullptr;

    char command;

    while (true)
    {
        system("cls");
        cout << "N) Nowa gra\nW) wczytaj gre\n";
        command = _getch();

        if (command == 'n' || command == 'N')
        {
            int x, y;  
            cout << "Podaj wymiary planszy - poziomo, pionowo:\n";
            cin >> x >> y;
            swiat1 = new Swiat(x,y);
            break;
        }
        else if (command == 'w'||command == 'W')
        {
            swiat1 = Swiat::WczytajZPliku();
            break;
        } 
        else
        {
            cout << "nieprawidlowa opcja\n";
        }
    }
    
    swiat1->RysujSwiat();

    while (!swiat1->GetKoniec()) 
    {   
        swiat1->Input();
        system("cls");
        swiat1->WykonajTure();  
    }

    delete swiat1;
    return 0;
}