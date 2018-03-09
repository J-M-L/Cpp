#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <ctype.h>

using namespace std;

vector<string> words;

//Creates word container vector
void createWordContainer(vector<string>& words);

//Clears thhe console view
void clearView();

//Prints the new word from word vector, using random
string printNewWord(vector<string> words);

//Reads user answer
string getPlayerAnswer();

//Check user answer
void checkUserAnswer(string answer, string correct);

//Lowers the case of string
string changeToLower(string input);

int main()
{
    createWordContainer(words);

    string userAnswer, printedWord;
    clearView();

    bool theGameIsOn = true;
    while(theGameIsOn)
    {
        printedWord = printNewWord(words);

        userAnswer = getPlayerAnswer();

        clearView();

        checkUserAnswer(userAnswer, printedWord);

    }
}

void clearView()
{
    for(int i = 0; i < 100; i++)
        cout << endl << endl;
}

void checkUserAnswer(string answer, string correct)
{
    if(answer == correct)
    {
        cout << "Oikein!" << endl;
    }
    else
    {
        cout << "Väärin dorka!" << endl;
    }

}

string getPlayerAnswer()
{
    string answer = "";
    cin >> answer;

    return answer;
}

string printNewWord(vector<string> words)
{
    srand((int)time(0));
    int wordIndex = rand() % words.size();

    string selectedWord = words[wordIndex];

    cout << "Kirjoitettava sana: " << selectedWord << endl;

    return selectedWord;
}

void createWordContainer(vector<string>& words)
{
    ifstream wordsFile;
    wordsFile.open("words.txt");
    string line = "";


    if(wordsFile.is_open())
    {
        while(getline(wordsFile, line))
        {
            string lineLower = changeToLower(line);
            if(find(words.begin(), words.end(), lineLower) == words.end())
            {
                words.push_back(lineLower);
            }
        }
        wordsFile.close();
        sort(words.begin(), words.end());
    }
}


string changeToLower(string input)
{
    string newString = "";

    for(char c : input)
    {
        newString += tolower(c);
    }
    return newString;
}
