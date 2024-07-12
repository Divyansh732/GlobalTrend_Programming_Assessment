#include <iostream>
#include <string>
using namespace std ;

bool alphabetic(string str)
{
    int flag=0;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z') ||(str[i] == ' ')) 
        {
            flag=0;
            }
        else{ 
        flag=1;
        break;
        }
    }
    if(flag==1)
     return false;
    else
     return true;
}
int main()
{
    string s;
    cout<<"enter string: "<<endl;
    getline(cin, s);
    if( alphabetic(s))
     cout<<"the string is alphabetical"<<endl;
    else
     cout<<"the string is not alphabetical";
}
