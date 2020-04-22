#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int err = 0;
void writes(string data){
    ofstream outfile("02Yufa.txt",ios::app);
    outfile<<data<<endl;
    outfile.close();
}
int Yufa(string temp)
{
    string a[200][200];
    string b,s;
    b="#E";
    int i=2,l=1;
    a['E']['i']="E->TG";
    a['E']['(']="E->TG";
    a['G']['+']="G->+TG";
    a['G'][')']="G->^";
    a['G']['#']="G->^";
    a['T']['i']="T->FS";
    a['T']['(']="T->FS";
    a['S']['+']="S->^";
    a['S']['*']="S->*FS";
    a['S'][')']="S->^";
    a['S']['#']="S->^";
    a['F']['i']="F->i";
    a['F']['(']="F->(E)";
    s = temp;
    cout<<s<<endl;
    int sl=s.length(),sl1=0;
    while(b[i-1]!='#'||s[sl1]!='#')
    {
        if(b[i-1]>='A'&&b[i-1]<='Z')
        {
        if(a[b[i-1]][s[sl1]]!="")
        {
            cout<<l++<<" "<<a[b[i-1]][s[sl1]]<<endl;
            string temp = "";
            temp =a[b[i-1]][s[sl1]];
            writes(temp);
            if(b[i-1]=='E'&&(s[sl1]=='i'||s[sl1]=='('))
                {
                    b[i-1]='G';
                    b[i++]='T';
                }
                else if(b[i-1]=='G'&&s[sl1]=='+')
                {
                  b[i-1]='G';
                  b[i++]='T';
                  b[i++]='+';

                }
                else if(b[i-1]=='G'&&(s[sl1]==')'||s[sl1]=='#'))
                {
                  i--;
                }
                else if(b[i-1]=='T'&&(s[sl1]=='i'||s[sl1]=='('))
                {
                    b[i-1]='S';
                    b[i++]='F';
                }
                else if(b[i-1]=='S'&&s[sl1]=='*')
                {
                   b[i-1]='S';
                   b[i++]='F';
                   b[i++]='*';
                }
                else if(b[i-1]=='S'&&(s[sl1]=='+'||s[sl1]==')'||s[sl1]=='#'))
                {
                   i--;
                }
                else if(b[i-1]=='F'&&s[sl1]=='i')
                {
                   b[i-1]='i';
                }
                else if(b[i-1]=='F'&&s[sl1]=='(')
                {
                   b[i-1]=')';
                   b[i++]='E';
                   b[i++]='(';
                }
        }
        else
        {
            cout<<"error!"<<endl;
            err ++;
            break;
        }
        }
        else
        {
            if(b[i-1]==s[sl1])
            {
                i--;
                sl1++;
            }
            else
          {
              cout<<"error!"<<endl;
              err ++;
              break;
          }
        }
    }
    if(b[i-1]=='#'&&s[sl1]=='#')
    {
      cout<<"acc!"<<endl;
      string temp = "accepted";
      writes(temp);
    }
    //cout<<a['E']['i']<<endl;
}

#include <fstream>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void changei(){

}

void change(string data){
    char p[120];
    data.copy(p,data.length()+1);
    string temp ="";
    int len = data.length();
    int i =0;
    int flag = 0;
    while( i < len){
        if(p[i] == '='){
            cout<<"find+1"<<endl;
            cout<<p<<endl;
            for(int j = i+1;j<len;j++){
                if(p[j] == ';'){
                    temp = temp + "#";
                    flag = 1;
                    break;
                }
                else if(p[j] == '+')
                    temp = temp + "+";
                else if(p[j] == '*')
                    temp = temp + "*";
                else if(p[j] == '(')
                    temp = temp + "(";
                else if(p[j] == ')')
                    temp = temp + ")";
                else if (p[j] == ' ')
                    ;
                else if (p[j] >='0' && p[j]<= '9'){
                    int x = j + 1;
                    while (p[x]>='0' && p[x] <='9'){
                        x++;
                    }
                    j = x;
                    temp = temp + "i";
                }
                else
                    temp = temp + "i";
            }
            Yufa(temp);
        }
        if (flag == 1){
            break;
        }
        i++;
    }
}

int main()
{
    fstream file("02Yufa.txt",ios::out);
    file.close();
    ifstream in("test.txt");
    string filename;
    string line;
    int x = 1;
    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        {
            //cout << line << endl;
            change(line);
            x++;
        }
    }
    else // 没有该文件
    {
        cout <<"no such file" << endl;
    }

    if(err==0){
        std::cout<<0<<std::endl;
    }
    else{
        std::cout<<err<<std::endl;
    }
    return 0;
}

