#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int mystrcmp(const char* str1, const char* str2)
{
    int c1 = 0, c2 = 0;
    while (str1[c1])
        c1++;
    while (str2[c2])
        c2++;
    if (c1 < c2)
        return -1;
    if (c1 > c2)
        return 1;
    if (c1 == c2)
        return 0;
}
int StringToNumber(const char* str)
{
    int c = 0;
    while (str[c])
        c++;
    int k = 0;
    for (int i = 0; i < c - 1; i++) {
        k = k * 10 + (str[i] - '0');
    }
    return k;
}
char* NumberToString(int number)
{    
    int c = 0;
    int temp = number;
    while (temp) {
        temp /= 10;
        c++;
    }
    char* nstr = new char(c);

    for (int i = 0; i < c; i++) {
        nstr[c - 1 - i] = (number % 10) + '0';
        number /= 10;
    }

    cout << endl;
    return nstr;
}
char* Uppercase(char* strUp)
{
    int c = 0;
    while (strUp[c])
        c++;
    for (int i = 0; i < c - 1; i++) {
        if((int)strUp[i] >= 97 && (int)strUp[i] <= 122)
            strUp[i] = char((int)strUp[i] - 32);
    }
    return strUp;
}
char* Lowercase(char* strL)
{
    int c = 0;
    while (strL[c])
        c++;
    for (int i = 0; i < c - 1; i++) {
        if ((int)strL[i] >= 65 && (int)strL[i] <= 90)
            strL[i] = char((int)strL[i] + 32);
    }
    return strL;
}
char* mystrrev(char* strR)
{
    int c = 0;
    while (strR[c])
        c++;
    char temp;
    for (int i = 0; i < (c - 1) / 2 ; i++) {
        temp = strR[c - 2 - i];
        strR[c - 2 - i] = strR[i];
        strR[i] = temp;
    }
    return strR;
}
int main()
{
    //1
    const int cmpn = 1000;
    char* cmpstr1 = new char(cmpn);
    printf("Enter the first string: ");
    fgets(cmpstr1, cmpn, stdin);
    char* cmpstr2 = new char(cmpn);
    printf("Enter the second string: ");
    fgets(cmpstr2, cmpn, stdin);
    if (mystrcmp(cmpstr1, cmpstr2) == 1)
        cout << "First string is bigger!" << endl;
    else if (mystrcmp(cmpstr1, cmpstr2) == -1)
        cout << "Second string is bigger!" << endl;
    else
        cout << "Strings are equal!" << endl;

    //2
   const int numn = 1000;
    char* charnum = new char(numn);
    printf("Enter the string: ");
    fgets(charnum, numn, stdin);
    cout << "Number of string: " << StringToNumber(charnum) << endl;

    //3
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "In string: " << NumberToString(num) << endl;

    //4
    const int numU = 1000;
    char* charUp = new char(numU);
    printf("Enter the string: ");
    fgets(charUp, numU, stdin);
    cout << "New string: " << Uppercase(charUp) << endl;

    //5
    const int numL = 1000;
    char* charL = new char(numL);
    printf("Enter the string: ");
    fgets(charL, numL, stdin);
    cout << "New string: " << Lowercase(charL) << endl;

    //6
    const int numR = 1000;
    char* charRev = new char(numR);
    printf("Enter the string: ");
    fgets(charRev, numR, stdin);
    cout << "New string: " << mystrrev(charRev) << endl;
    return 0;
}
