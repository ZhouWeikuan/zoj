#include <iostream.h>
#include <string.h>

int matching[24][4] = {{0,1,2,3},{0,1,3,2},{0,2,1,3},{0,2,3,1},{0,3,1,2},{0,3,2,1},{1,0,2,3},{1,0,3,2},{1,2,0,3},{1,2,3,0},{1,3,0,2},{1,3,2,0},\
                       {2,0,1,3},{2,0,3,1},{2,1,0,3},{2,1,3,0},{2,3,0,1},{2,3,1,0},{3,0,1,2},{3,0,2,1},{3,1,2,0},{3,1,0,2},{3,2,0,1},{3,2,1,0}};


char s1[60][4];
char s2[60][4];
int num1[60][4];
int num2[60][4];
int vm1[20];
int vm2[20];
int record[20];
int now;
int n;

bool input()
{
    cin >> n;
    if(n == 0)
        return false;
    int i,j;
    for(i = 0;i < n;++i)
    {
        cin >> s1[i];
        for(j = 0;j < 4;++j)
            num1[i][j] = s1[i][j]-'A';
    }
    for(i = 0;i < n;++i)
    {
        cin >> s2[i];
        for(j = 0;j < 4;++j)
            num2[i][j] = s2[i][j]-'a';
    }
    return true;
}

bool can_match(int v)
{
    int i;
    for(i = 0;i < 4;++i)
    {
        if((vm2[num2[v][matching[now][i]]] == -1 || vm2[num2[v][matching[now][i]]] == num1[v][i]) && (vm1[num1[v][i]] == -1 || vm1[num1[v][i]] == num2[v][matching[now][i]]) )
        {
            vm1[num1[v][i]] = num2[v][matching[now][i]];
            vm2[num2[v][matching[now][i]]] = num1[v][i];
        }
        else
            return false;
    }
    return true;
}

void match_24()
{
    bool flag = false;
    int i,k;
    memset(record,-1,sizeof(record));
    for(now = 0;now < 24;++now)
    {
        memset(vm1,-1,sizeof(vm1));
        memset(vm2,-1,sizeof(vm2));
        for(i = 0;i < n;++i)
        {
            if(!can_match(i))
                break;
        }
        if(i == n)
        {
            if(flag == false)
            {
                flag = true;
                for(i = 0;i < n;++i)
                {
                    for(k = 0;k < 4;++k)
                        record[num1[i][k]] = num2[i][matching[now][k]];
                }
            }
            else
            {
                for(i = 0;i < n;++i)
                {
                    for(k = 0;k < 4;++k)
                    {
                        if(record[num1[i][k]] != num2[i][matching[now][k]])
                            record[num1[i][k]] = -1;
                    }
                }
            }
        }
    }
    for(i = 0;i < 4;++i)
    {
        int count = 0;
        bool finish[5];
        int result;
        int temp;
        memset(finish,false,sizeof(finish));
        for(k = 0;k < 5;++k)
        {
            if(record[i*5+k] != -1)
                count++;
        }
        if(count == 4)
        {
            for(k = 0;k < 5;++k)
            {
                if(record[i*5+k] != -1)
                {
                    finish[record[i*5+k]%5] = true;
                    result = record[i*5+k]/5;
                }
                else
                    temp = k;
            }
            for(k = 0;k < 5;++k)
            {
                if(finish[k] == false)
                    break;
            }
            record[i*5+temp] = result*5+k;
        }
    }
}

void output()
{
    int i,k;
    for(k = 0;k < 4;++k)
    {
        for(i = 0;i < 5;++i)
        {
            if(i)
                cout << " ";
            cout << char(k*5+i+'A') << "-";
            if(record[k*5+i] == -1)
                cout << "?";
            else
                cout << char(record[k*5+i]+'a');
        }
        cout << endl;
    }
}

int main()
{
    int count = 1;
    while(input())
    {
        cout << "Test #" << count++ << ":" << endl;
        match_24();
        output();
    }
    return 0;
}

