//THIS PROGRAM IS WRITTEN BY AADITYA JOSHI
#include <iostream>
#include <cstring>
using namespace std;
int chance = 9, j = 0;
void displayused(int, char[]);
void displaylogo(int, char[]);
int main()
{
    int i, check;
    char movie[100], original[100], mod[100], ch, gap = 179, used[9];
    char logo[9] = {'D', 'O', 'O', 'W', 'Y', 'L', 'L', 'O', 'B'};
    system("cls");
    cout << "Enter The Movie " << endl;
    gets(movie);
    strcpy(original, movie);
    strcpy(mod, original);
    for (i = 0; original[i] != NULL; i++)
    {
        if (original[i] == ' ')
            mod[i] = gap;
    }
    for (i = 0; movie[i] != NULL; i++)
    {
        if (movie[i] == 'a' || movie[i] == 'A' || movie[i] == 'e' || movie[i] == 'E' || movie[i] == 'i' || movie[i] == 'I' || movie[i] == 'o' || movie[i] == 'O' || movie[i] == 'u' || movie[i] == 'U')
        {
            continue;
        }
        else if (movie[i] == ' ')
        {
            movie[i] = gap;
        }
        else
            movie[i] = '-';
    }
    system("cls");
    puts(movie);
    cout << "Chances Remaining (" << chance << ") :- ";
    displaylogo(chance, logo);
    while (chance <= 9)
    {
        int flag = 0;
        check = strcmp(movie, mod);
        if (check == 0)
        {
            cout << "Congratulations! You Won. " << endl;
            system("pause");
            exit(0);
        }
        cout << "Enter A Letter " << endl;
        cin >> ch;
        for (i = 0; original[i] != NULL; i++)
        {
            if (original[i] == ch)
            {
                movie[i] = ch;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            system("cls");
            cout << "That Was A Right Guess " << endl;
            cout << "Chances Remaining (" << chance << ") :- ";
            displaylogo(chance, logo);
            displayused(j, used);
            puts(movie);
        }
        else if (flag == 0)
        {
            used[j] = ch;
            chance--;
            j++;
            if (chance < 1)
            {
                break;
            }
            puts(movie);
            system("cls");
            cout << "That Letter Does Not Belong To The Movie " << endl;
            cout << "Chances Remaining (" << chance << ") :- ";
            displaylogo(chance, logo);
            displayused(j, used);
            puts(movie);
        }
    }
    cout << "You Lose! The Correct Movie Was " << endl;
    puts(original);
    cout << "Better Luck Next Time " << endl;
    system("pause");
    return 0;
}
void displaylogo(int chance, char logo[])
{
    int j;
    for (j = (chance - 1); j >= 0; j--)
    {
        cout << logo[j] << " ";
    }
    cout << endl;
}
void displayused(int j, char used[])
{
    int i;
    cout << endl;
    cout << "Wrong Letters Used: ";
    for (i = 0; i < j; i++)
    {
        cout << used[i] << ",";
    }
    cout << endl;
}
