#include<iostream>
#include<cstring>
using namespace std;

//加密算法
void encrypt()
{
    const int N = 100;
    char letters[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    //用于填充矩阵
    int flag[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    //字母是否已在矩阵中，与letters数组对应
    char ch[5][5];//5X5矩阵
    char ch1[N];//密钥
    char ch2[N];//明文
    char ch4;//无关字符
    int len = 'a' - 'A';
    cout << endl << "请输入密钥："<<endl;
    cin >> ch1;
    int flg = 1;
    while (flg == 1)
    {
        for (int i = 0; i < strlen(ch1); i++)
        //把所输入的密钥转化为大写字母
        {
            if (ch1[i] > 'z' || ch1[i] < 'a')
            {
                cout << endl << "请重新选择操作：" << endl;
                flg = 0; break;
            }
            else
                ch1[i] = ch1[i] - len;
        }
        if (flg == 1)
        {
            for (int i = 0; i < strlen(ch1); i++)
            //把密钥中的J都变为I
            {
                if (ch1[i] == 'J')ch1[i] = 'I';
            }
            int i = 0; int j = 0;
            for (int k = 0; k < strlen(ch1); k++) 
            //把密钥中的字母填入到矩阵中，并把该字母标记为已用
            {
                for (int t = 0; t < 25; t++)
                {
                    if (ch1[k] == letters[t] && flag[t] == 0)
                    {
                        ch[i][j] = letters[t];
                        flag[t] = 1;
                        if (j < 4)j++;
                        else { i++; j = 0; }
                    }
                }
            }
            for (int k = 0; k < 25; k++)
            //按字母表顺序把未用字母依次填入到矩阵中
            {
                if (flag[k] == 0)
                {
                    ch[i][j] = letters[k];
                    flag[k] = 1;
                    if (j < 4)j++;
                    else { i++; j = 0; }
                }
            }
            cout <<endl<< "密钥填充后的矩阵为： " << endl;
            for (i = 0; i < 5; i++)
                for (j = 0; j < 5; j++)
                {
                    cout << ch[i][j];
                    cout << " ";
                    if (j == 4)
                        cout << endl;
                };
            cout << endl << "请输入明文（英文字符）："<<endl;
            cin >> ch2;
            cout << endl << "请输入一个无关字符："<<endl;
            cin >> ch4;
            if (ch4 >= 'a')
                ch4 = ch4 - len;
            for (int k = 0; k < strlen(ch2); k++)
            //把所输入的明文转化为大写字母
            {
                if (ch2[k] >= 'a')
                    ch2[k] = ch2[k] - len;
            }
            for (int k = 0; k < strlen(ch2); k++)
            //把明文中的J都变为I
            {
                if (ch2[k] == 'J')
                    ch2[k] = 'I';
            }
            //为明文添加必要的无关字符以防止同一组的两个字符相同
            for (int k = 0; k < strlen(ch2); k += 2)
            {
                if (ch2[k] == ch2[k + 1])
                {
                    for (int t = strlen(ch2); t > k; t--)
                        ch2[t + 1] = ch2[t];
                    ch2[k + 1] = ch4;
                }
            }
            //若明文有奇数个字符，则添加一个无关字符以凑够偶数个
            if (strlen(ch2) % 2 != 0)
            {
                ch2[strlen(ch2) + 1] = ch2[strlen(ch2)];
                //字符串结尾赋'\0'
                ch2[strlen(ch2)] = ch4;
                //明文串尾插入无关字符
            }
            cout << endl << "经转换后，明文为："<<endl;
            for (int k = 0; k < strlen(ch2); k += 2)
                cout << ch2[k] << ch2[k + 1] << " ";
            cout << endl << endl << "明文长度为：" << strlen(ch2) <<endl;
            //明文输入并整理完毕
            for (int k = 0; k < strlen(ch2); k += 2)
            {
                int m1, m2, n1, n2;
                for (m1 = 0; m1 <= 4; m1++)
                {
                    for (n1 = 0; n1 <= 4; n1++)
                    {
                        if (ch2[k] == ch[m1][n1])break;
                    }
                    if (ch2[k] == ch[m1][n1])break;
                }
                for (m2 = 0; m2 <= 4; m2++)
                {
                    for (n2 = 0; n2 <= 4; n2++)
                    {
                        if (ch2[k + 1] == ch[m2][n2])break;
                    }
                    if (ch2[k + 1] == ch[m2][n2])break;
                }
                m1 = m1 % 5;
                m2 = m2 % 5;
                if (n1 > 4) { n1 = n1 % 5; m1 = m1 + 1; }
                if (n2 > 4) { n2 = n2 % 5; m2 = m2 + 1; }
                if (m1 == m2)
                {
                    ch2[k] = ch[m1][(n1 + 1) % 5];
                    ch2[k + 1] = ch[m2][(n2 + 1) % 5];
                }
                else
                {
                    if (n1 == n2)
                    {
                        ch2[k] = ch[(m1 + 1) % 5][n1];
                        ch2[k + 1] = ch[(m2 + 1) % 5][n2];
                    }
                    else
                    {
                        ch2[k] = ch[m1][n2];
                        ch2[k + 1] = ch[m2][n1];
                    }
                }
            }
            cout << endl << "经加密后，密文是："<<endl;
            for (int k = 0; k < strlen(ch2); k += 2)
                cout << ch2[k] << ch2[k + 1] << " ";
            cout << endl;
        }
        else break;
    }
}

//解密算法
void decrypt()
{
    const int N = 100;
    char letters[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";//用于填充矩阵
    int flag[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    //标记字母是否已在矩阵中，与letters数组对应
    char ch[5][5];//5X5矩阵
    char ch1[N];//密钥
    char ch2[N];//密文
    int len = 'a' - 'A';
    int flg = 1;
    cout << endl << "请输入密钥（英文字符）：" << endl;
    cin >> ch1;
    while (flg == 1)
    {
        for (int i = 0; i < strlen(ch1); i++)//把所输入的密钥转化为大写字母
        {
            if (ch1[i] > 'z' || ch1[i] < 'a')
            {
                cout << endl << "请重新选择操作：" << endl;
                flg = 0; break;
            }
            else
                ch1[i] = ch1[i] - len;
        }
        if (flg == 1)
        {
            for (int i = 0; i < strlen(ch1); i++)//把密钥中的J都变为I        
            {
                if (ch1[i] == 'J')ch1[i] = 'I';
            }
            int i = 0; int j = 0;
            //把密钥中的字母填入到矩阵中，并把该字母标记为已用
            for (int k = 0; k < strlen(ch1); k++)
            {
                for (int t = 0; t < 25; t++)
                {
                    if (ch1[k] == letters[t] && flag[t] == 0)
                    {
                        ch[i][j] = letters[t];
                        flag[t] = 1;
                        if (j < 4)j++;
                        else { i++; j = 0; }
                    }
                }
            }
            for (int k = 0; k < 25; k++)//按字母表顺序把未用字母依次填入到矩阵中
            {
                if (flag[k] == 0)
                {
                    ch[i][j] = letters[k];
                    flag[k] = 1;
                    if (j < 4)j++;
                    else { i++; j = 0; }
                }
            }
            cout << endl << "密钥填充后的矩阵为： " << endl;
            for (i = 0; i < 5; i++)

                for (j = 0; j < 5; j++)
                {
                    cout << ch[i][j];
                    cout << " ";
                    if (j == 4)
                        cout << endl;
                }
            cout << endl;
            // 矩阵生成完毕
            int f = 0;
            do {
                cout << endl << "请输入密文（英文字符）：" << endl;
                cin >> ch2;
                for (int k = 0; k < strlen(ch2); k++)//把所输入的密文转化为大写字母
                {
                    if (ch2[k] >= 'a')
                        ch2[k] = ch2[k] - len;
                }
                for (int k = 0; k < strlen(ch2); k++)//把密文中的J都变为I
                {
                    if (ch2[k] == 'J')ch2[k] = 'I';
                }
                for (int k = 0; k < strlen(ch2); k += 2)
                {
                    if (ch2[k] == ch2[k + 1])
                    {
                        cout << endl << "同一分组中不能出现相同字符！请重新输入。" << endl;
                        f = 1;
                        break;
                    }
                    else f = 2;
                }
                if (f == 1)continue;
                if (strlen(ch2) % 2 != 0)
                {
                    cout << endl << "<Error>字符串不能为奇数个，请重新输入。" << endl;
                    f = 1;
                }
                else f = 2;
            } while (f == 1);
            //解密开始
            for (int k = 0; k < strlen(ch2); k += 2)
            {
                int m1, m2, n1, n2;
                for (m1 = 0; m1 <= 4; m1++)
                {
                    for (n1 = 0; n1 <= 4; n1++)
                    {
                        if (ch2[k] == ch[m1][n1])break;
                    }
                    if (ch2[k] == ch[m1][n1])break;
                }
                for (m2 = 0; m2 <= 4; m2++)
                {
                    for (n2 = 0; n2 <= 4; n2++)
                    {
                        if (ch2[k + 1] == ch[m2][n2])break;
                    }
                    if (ch2[k + 1] == ch[m2][n2])break;
                }
                m1 = m1 % 5;
                m2 = m2 % 5;
                if (n1 > 4) { n1 = n1 % 5; m1 = m1 + 1; }
                if (n2 > 4) { n2 = n2 % 5; m2 = m2 + 1; }
                if (m1 == m2)
                {
                    ch2[k] = ch[m1][(n1 + 4) % 5];
                    ch2[k + 1] = ch[m2][(n2 + 4) % 5];
                }
                else
                {
                    if (n1 == n2)
                    {
                        ch2[k] = ch[(m1 + 4) % 5][n1];
                        ch2[k + 1] = ch[(m2 + 4) % 5][n2];
                    }
                    else
                    {
                        ch2[k] = ch[m1][n2];
                        ch2[k + 1] = ch[m2][n1];
                    }
                }
            }
            cout << endl << "经解密后，明文为：" << endl;
            for (int k = 0; k < strlen(ch2); k += 2)
                cout << ch2[k] << ch2[k + 1] << " ";
            cout << endl;
        }
        else break;
    }
}

int main()
{

    int n;
    cout << "请选择模式:（1、加密；2、解密）" <<endl;
    while (true)
    {
        cin >> n;
        switch (n)
        {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        default:
            break;
        }
    }
    return 0;
}