#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string S[5]= {"keyword","identifier","integer","boundary","operator"};
string T[6]= {"main","if","else","for","while","int"};
string temp = "";

void writes(string data){
    ofstream outfile("oXiaoC.txt",ios::app);
    outfile<<data<<endl;
    outfile.close();
    temp = "";
}

void panduan(string s)
{
    if(s[0]>='0'&&s[0]<='9')
    {
        temp = "(" + S[2] +"," + s +")";
        writes(temp);
    }
    else
    {
        int f=1;
        for(int i=0; i<6; i++)
        {
            if(s==T[i])
            {
                f=0;
                temp = "(" + S[0] + "," + s + ")";
                writes(temp);
                break;
            }
        }
        if(f==1)
        {
            temp = "(" +  S[1] + "," + s + ")";
            writes(temp);
        }
    }

}
int XiaoC(string line)
{

        string s = line;
        int len=s.length();
        string temp="";
        for(int i=0; i<len; i++)
        {
            if(s[i] == '=' || s[i] == '+' || s[i] == '-'||s[i] == '*'|| s[i] == '/' || s[i] == '<' || s[i] == '>' || s[i] == '!')
            {
                if(temp.length())
                {
                    panduan(temp);
                }
                temp="";
                if(i+1<len&&s[i+1]=='=')
                {
                    temp = "(" + S[4] + "," + s[i] + s[i+1] + ")";
                    writes(temp);
                    i++;
                }
                else
                {
                    temp = "(" + S[4] + "," + s[i] + ")";
                    writes(temp);
                }
            }
            else if(s[i] == '(' || s[i] == ')' || s[i] == '{'||s[i] == '}'|| s[i] == ',' || s[i] ==';')
            {
                if(temp.length())
                {
                    panduan(temp);
                }
                temp="";
                temp = "(" + S[3] + "," + s[i] + ")";
                writes(temp);
            }
            else
            {
                temp=temp+s[i];
            }
        }
        if(temp.length())
        {
            panduan(temp);
        }
    return 0;
}

int main()
{
    fstream file("oXiaoC.txt",ios::out);
    file.close();
    ifstream in("test.txt");
    string filename;
    string line;
    int x = 1;
    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        {
            x++;
            XiaoC(line);
        }
    }
    else // 没有该文件
    {
        cout <<"no such file" << endl;
    }

    return 0;
}
