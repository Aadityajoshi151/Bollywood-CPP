# Bollywood Game in C++
## Important:
I wrote this program when I was in my first year and I posted it on a simple blog that I created at that time (PEC-World.weebly.com). Recently I decided to move all my projects to github and I have taken down this blog. Since I wrote this is in 2017 it has some mistakes here and there but it works fine. I improved this project and made a proper desktop application which you can find [here](https://github.com/Aadityajoshi151/Bollywood). I also know this project would have been more easy if I had written it in python but I didn't know python at that time. Here is the exact copy of the post that I wrote on my blog on 11 Nov 2017 👇

## Description
Bollywood, we all have played this game once in our lives. This is a classic way to kill time especially in a boring class.  
The concept of this pen & paper game is 1 player gives a movie to another player where only vowels are visible. The consonants are replaced with a ‘_’ sign. For example the movie ‘Now You See Me’ will be written as ‘_ O _ /_ O U /_ E E/_ E’. Spaces are indicated by ‘/’ sign.  
The other player tries to guess the letters one by one. If the guess is correct, the letter is put on its respective position(s) in the movie. If the guess is wrong, the word ‘BOLLYWOOD’ loses one of its letters to indicate the number of chances left. There are total 9 chances as there are 9 letters in the word ‘BOLLYWOOD’. The wrongly guessed letters are also noted down to avoid repeating those letters.  
Creating this game in C++ was not a difficult job. Any programmer with a basic knowledge of loops, strings and user defined functions can write the code for this game.  
  
There are some variants available on the internet. This is my version of Bollywood.

    
   
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
In my code,  
I have used the minus (-) sign to indicate a consonant instead of the underscore (_) sign because when 2 blanks are consecutive, instead of seeing 2 blanks (_ _), we see 2 blanks as one (__) which is very confusing. Using an underscore with a space seemed to be solution for the problem but while replacing, we can only use 1 character and not 2. Underscore and a space counted as 2 characters.

-   To indicate spaces, I have used the pipe symbol (|) which has an ASCII vale of 179. The name of the variable is ‘gap’.
-   I have used 2 functions: - displayused() and displaylogo()

Displayused() displays the wrong letters used after each wrong guess.  
Displaylogo() displays the word ‘BOLLYWOOD’ and is responsible for eliminating a letter after every wrong guess.

-   The variable ‘j’ is responsible for storing the wrong guessed letters in an array of 9 elements called ‘used[]’.
-   The variable ‘check’ stores the value 0 only when the player guesses all the letters correctly. The 0 value is assigned to ‘check’ by the string comparing function (strcmp).
-   The array ‘original[]’ stores the name entered of the movie without any modifications.
-   The array ‘mod[]’ stores the name with the spaces replaced by ‘|’ symbol.
-   The array ‘movie[]’ stores the name with modified consonants, spaces.
-   The array ‘logo[]’ stores the word ‘BOLLYWOOD’ as individual letters. In this way it is easy to eliminate the letters.
-   The variable ‘i’ handles all the FOR loops.
-   The variable ‘ch’ accepts the letter from the player.
-   The ‘flag’ variable is initialized in every pass of WHILE loop with a value 0. This ‘flag’ decides the guess was right or wrong.
-   Entering and checking of a letter, it all happens inside a WHILE loop which keeps running as long as chances are less than or equal to 9. When chances < 1, the loop is broken.
