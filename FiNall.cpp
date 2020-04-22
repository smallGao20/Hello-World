#include<bits/stdc++.h>

using namespace std;

char p[100];
string ss;
string temp3;
char s[100][100];
int n, m, top = 0;

int get(char ch)///寄存器中是否存在变量
{
    for(int i = 0; i < m; i++)
    {
        if(ch == p[i])
            return i;
    }
    return -1;
}

int use(int x, char ch)///查找后面是否使用
{
    for(int i = x; i < n; i++)
    {
        if(ch == s[i][3] || ch == s[i][5])
            return i;
    }
    return n;
}
int find(int x)
{
    if(top < m) return top++;
    int t = -1;
    int ans = -1;
    for(int i = 0; i < m; i++)
    {
        int k = use(x, p[i]);
        if(k > ans)
        {
            ans = k;
            t = i;
        }
    }
    return t;
}

void print1(char ch)
{
    if(ch == '+') printf("ADD ");
    else if(ch == '-') printf("SUB ");
    else if(ch == '*') printf("MUL ");
    else if(ch == '\\') printf("DIV ");
}

void print2(char ch)
{
    int x = get(ch);
    if(x != -1)
        printf("R%d\n", x);
    else{
        printf("%c\n", ch);
    }
}

int Finall(int x,int y)
{
    n = x;
    m = y;
    cout<<"当前使用寄存数量为:"<<y<<endl;
    for(int i = 0; i < n; i++)
    {
        int x = get(s[i][3]);
        if(x == -1)
        {
            x = find(i);
            if(p[x] != '\0' && use(i, p[x]) < n)
            {
                printf("ST R%d, %c\n", x, p[x]);
                p[x] = NULL;
            }
            printf("LD R%d, %c\n", x, s[i][3]);
        }
        print1(s[i][4]);
        printf("R%d, ", x);
        print2(s[i][5]);
        p[x] = s[i][0];
    }
}

string change(string data){
    char p[120];
    data.copy(p,data.length()+1);
    string temp ="";
    int len = data.length();
    for(int i=0;i<len;i++){
        if(p[i]>='a' && p[i]<='z'){
            p[i] = p[i] - 32;
            temp = temp + p[i];
        }
        else if(p[i]>='1' && p[i]<='9' && p[i-1]>='A' && p[i-1]<='Z'){
            ;
        }
        else if (p[i] >='0' && p[i]<= '9'){
                    string temp1;
                    temp1 = temp1 + p[i];
                    int x = i + 1;
                    while (p[x]>='0' && p[x] <='9'){
                        temp1 = temp1 + p[x];
                        x++;
                    }
                    i = x;
                    temp = temp + temp1;
                }
        else if(p[i] == '='){
            temp = temp + ":=";
        }
        else if(p[i] =='+' || p[i] == '*' || p[i] == '(' || p[i] ==')'){
            temp = temp + p[i];
        }
        else
            ;
    }
    return temp;
}

int main()
{
    fstream file("ofinall.txt",ios::out);
    file.close();
    ifstream in("forfina.txt");
    string filename;
    string line;
    int x = 0;
    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        {
            if(line != "success!"){
                ss = change(line);
                int len = ss.length();
                for(int i=0;i<len;i++){
                    s[x][i] = ss[i];
                }
                s[x][len] = '\0';
                //cout<<s[x]<<endl;
                x++;
            }
        }
    }
    else // 没有该文件
    {
        cout <<"no such file" << endl;
    }
    Finall(x,2);
    return 0;
}


