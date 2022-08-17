#include<iostream>  
#include<windows.h>  
using namespace std;  
int main()  
{  
    int T=10000;
    while(T--)  
    {   
        system("data.exe > data.txt");  
        system("1.exe < data.txt > 1.txt");  
        system("2.exe < data.txt > 2.txt");  
        if(system("fc 2.txt 1.txt"))   break;  
    }  
    if(T==0)cout<<"no error"<<endl;
    else cout<<"error"<<endl;  
 
    return 0;  
}
