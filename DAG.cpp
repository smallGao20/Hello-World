#include<bits/stdc++.h>

using namespace std;

string s[110];
string temp;
void writes(string data);
int n;
struct node
{
    int l = -1;
    int r = -1;
    char id;
    vector<char>val;
} t[101];

int num = 0;

int use(int x, char ch)
{
    int len = t[x].val.size();
    for(int i = 0; i< len; i++)
    {
        if(t[x].val[i] == ch)
            return 1;
    }
    return 0;
}

int add_node(char ch)
{
    for(int i = num - 1; i >= 0; i--)
    {
        if(t[i].id == ch || use(i, ch))
            return i;
    }
    t[num].id = ch;
    return num++;
}
void add_op(char op, char ch, int l, int r)
{
    for(int i = num - 1; i >= 0; i--)
    {
        if(t[i].id == op && t[i].l == l &&  t[i].r == r)
        {
            t[i].val.push_back(ch);
            return ;
        }
    }
    t[num].id = op;
    t[num].l = l;
    t[num].r = r;
    t[num].val.push_back(ch);
    num++;
    return;
}
int flag[101];
char ans[1010][1010];
int dfs(int x)
{
    if(t[x].l != -1 && t[x].r != -1)
    {
        flag[x] = 1;
        dfs(t[x].l);
        dfs(t[x].r);
    }
}
void DAG(int m)
{
    n = m;
    memset(flag, 0, sizeof(flag));
    for(int i = 0; i < n; i++)
    {
        //cout<<s[i]<<endl;
        int l = add_node(s[i][2]);
        int r = add_node(s[i][4]);
        add_op(s[i][3], s[i][0], l, r);
    }
    for(int i = 0; i < num; i++)
    {
        if(t[i].l != -1 && t[i].r != -1)
        {
            ans[i][0] = t[i].val[0];
            ans[i][1] = '=';
            node ll = t[t[i].l];
            node rr = t[t[i].r];
            ans[i][2] = ll.val.size() > 0 ? ll.val[0]:ll.id;
            ans[i][3]=t[i].id;
            ans[i][4] = rr.val.size() > 0? rr.val[0]:rr.id;
            ans[i][5] = '\0';
        }
    }
    for(int i = num - 1; i >= 0; i--)
    {
        if(ans[i][0]  == 'A')
        {
            dfs(i);
            break;
        }
    }
    for(int i = num - 1; i >= 0; i--)
    {
        if(ans[i][0]  == 'B')
        {
            dfs(i);
            break;
        }
    }
    for(int i = 0; i < num; i++)
    {
        if(flag[i]){
            printf("%s\n", ans[i]);
            string temp = "";
            temp = ans[i];
            writes(temp);
        }
    }
}

void writes(string data){
    ofstream outfile("oDAG.txt",ios::app);
    outfile<<data<<endl;
    outfile.close();
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
            temp = temp + "=";
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
    fstream file("oDAG.txt",ios::out);
    file.close();
    ifstream in("oYuyi.txt");
    string filename;
    string line;
    int x = 0;
    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        {
            if(line != "success!"){
                s[x] = change(line);
                //cout<<s[x]<<endl;
                x++;
            }
        }
    }
    else // 没有该文件
    {
        cout <<"no such file" << endl;
    }
    DAG(x);
    return 0;
}

