#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;
stack<long long int> num;
stack<char> sig;
char word[100];
char Prior[9][9] = //优先级列表
    {
        {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '>', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '>', '<', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '<', '<', '=', ' '},
        {'>', '>', '>', '>', '>', '>', ' ', '>', '>'},
        {'<', '<', '<', '<', '<', '<', '<', ' ', '='}};

int signswitch(char a)
{
    char signs[] = {'+', '-', '*', '/', '%', '^', '(', ')', '#', '\0'};
    int k;
    k = 0;
    while (signs[k] != '\0' && signs[k] != a)
        k++;
    if (signs[k] == a)
        return k;
    else
        return -1;
}

char refusal(char a, char b)
{
    return Prior[signswitch(a)][signswitch(b)];
}

int main()
{

    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        while (!num.empty())
        {
            num.pop();
        }
        while (!sig.empty())
        {
            sig.pop();
        }
        gets(word);
        strcat(word, "#");
        int j = 0;
        sig.push('#');
        while ((sig.top() != '#' || word[j] != '#'))
        {
            ;
    }

    return 0;
}