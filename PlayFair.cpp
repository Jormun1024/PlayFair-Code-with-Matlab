#include<iostream>
#include<cstring>
using namespace std;

//�����㷨
void encrypt()
{
    const int N = 100;
    char letters[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    //����������
    int flag[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    //��ĸ�Ƿ����ھ����У���letters�����Ӧ
    char ch[5][5];//5X5����
    char ch1[N];//��Կ
    char ch2[N];//����
    char ch4;//�޹��ַ�
    int len = 'a' - 'A';
    cout << endl << "��������Կ��"<<endl;
    cin >> ch1;
    int flg = 1;
    while (flg == 1)
    {
        for (int i = 0; i < strlen(ch1); i++)
        //�����������Կת��Ϊ��д��ĸ
        {
            if (ch1[i] > 'z' || ch1[i] < 'a')
            {
                cout << endl << "������ѡ�������" << endl;
                flg = 0; break;
            }
            else
                ch1[i] = ch1[i] - len;
        }
        if (flg == 1)
        {
            for (int i = 0; i < strlen(ch1); i++)
            //����Կ�е�J����ΪI
            {
                if (ch1[i] == 'J')ch1[i] = 'I';
            }
            int i = 0; int j = 0;
            for (int k = 0; k < strlen(ch1); k++) 
            //����Կ�е���ĸ���뵽�����У����Ѹ���ĸ���Ϊ����
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
            //����ĸ��˳���δ����ĸ�������뵽������
            {
                if (flag[k] == 0)
                {
                    ch[i][j] = letters[k];
                    flag[k] = 1;
                    if (j < 4)j++;
                    else { i++; j = 0; }
                }
            }
            cout <<endl<< "��Կ����ľ���Ϊ�� " << endl;
            for (i = 0; i < 5; i++)
                for (j = 0; j < 5; j++)
                {
                    cout << ch[i][j];
                    cout << " ";
                    if (j == 4)
                        cout << endl;
                };
            cout << endl << "���������ģ�Ӣ���ַ�����"<<endl;
            cin >> ch2;
            cout << endl << "������һ���޹��ַ���"<<endl;
            cin >> ch4;
            if (ch4 >= 'a')
                ch4 = ch4 - len;
            for (int k = 0; k < strlen(ch2); k++)
            //�������������ת��Ϊ��д��ĸ
            {
                if (ch2[k] >= 'a')
                    ch2[k] = ch2[k] - len;
            }
            for (int k = 0; k < strlen(ch2); k++)
            //�������е�J����ΪI
            {
                if (ch2[k] == 'J')
                    ch2[k] = 'I';
            }
            //Ϊ������ӱ�Ҫ���޹��ַ��Է�ֹͬһ��������ַ���ͬ
            for (int k = 0; k < strlen(ch2); k += 2)
            {
                if (ch2[k] == ch2[k + 1])
                {
                    for (int t = strlen(ch2); t > k; t--)
                        ch2[t + 1] = ch2[t];
                    ch2[k + 1] = ch4;
                }
            }
            //���������������ַ��������һ���޹��ַ��Դչ�ż����
            if (strlen(ch2) % 2 != 0)
            {
                ch2[strlen(ch2) + 1] = ch2[strlen(ch2)];
                //�ַ�����β��'\0'
                ch2[strlen(ch2)] = ch4;
                //���Ĵ�β�����޹��ַ�
            }
            cout << endl << "��ת��������Ϊ��"<<endl;
            for (int k = 0; k < strlen(ch2); k += 2)
                cout << ch2[k] << ch2[k + 1] << " ";
            cout << endl << endl << "���ĳ���Ϊ��" << strlen(ch2) <<endl;
            //�������벢�������
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
            cout << endl << "�����ܺ������ǣ�"<<endl;
            for (int k = 0; k < strlen(ch2); k += 2)
                cout << ch2[k] << ch2[k + 1] << " ";
            cout << endl;
        }
        else break;
    }
}

//�����㷨
void decrypt()
{
    const int N = 100;
    char letters[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";//����������
    int flag[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    //�����ĸ�Ƿ����ھ����У���letters�����Ӧ
    char ch[5][5];//5X5����
    char ch1[N];//��Կ
    char ch2[N];//����
    int len = 'a' - 'A';
    int flg = 1;
    cout << endl << "��������Կ��Ӣ���ַ�����" << endl;
    cin >> ch1;
    while (flg == 1)
    {
        for (int i = 0; i < strlen(ch1); i++)//�����������Կת��Ϊ��д��ĸ
        {
            if (ch1[i] > 'z' || ch1[i] < 'a')
            {
                cout << endl << "������ѡ�������" << endl;
                flg = 0; break;
            }
            else
                ch1[i] = ch1[i] - len;
        }
        if (flg == 1)
        {
            for (int i = 0; i < strlen(ch1); i++)//����Կ�е�J����ΪI        
            {
                if (ch1[i] == 'J')ch1[i] = 'I';
            }
            int i = 0; int j = 0;
            //����Կ�е���ĸ���뵽�����У����Ѹ���ĸ���Ϊ����
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
            for (int k = 0; k < 25; k++)//����ĸ��˳���δ����ĸ�������뵽������
            {
                if (flag[k] == 0)
                {
                    ch[i][j] = letters[k];
                    flag[k] = 1;
                    if (j < 4)j++;
                    else { i++; j = 0; }
                }
            }
            cout << endl << "��Կ����ľ���Ϊ�� " << endl;
            for (i = 0; i < 5; i++)

                for (j = 0; j < 5; j++)
                {
                    cout << ch[i][j];
                    cout << " ";
                    if (j == 4)
                        cout << endl;
                }
            cout << endl;
            // �����������
            int f = 0;
            do {
                cout << endl << "���������ģ�Ӣ���ַ�����" << endl;
                cin >> ch2;
                for (int k = 0; k < strlen(ch2); k++)//�������������ת��Ϊ��д��ĸ
                {
                    if (ch2[k] >= 'a')
                        ch2[k] = ch2[k] - len;
                }
                for (int k = 0; k < strlen(ch2); k++)//�������е�J����ΪI
                {
                    if (ch2[k] == 'J')ch2[k] = 'I';
                }
                for (int k = 0; k < strlen(ch2); k += 2)
                {
                    if (ch2[k] == ch2[k + 1])
                    {
                        cout << endl << "ͬһ�����в��ܳ�����ͬ�ַ������������롣" << endl;
                        f = 1;
                        break;
                    }
                    else f = 2;
                }
                if (f == 1)continue;
                if (strlen(ch2) % 2 != 0)
                {
                    cout << endl << "<Error>�ַ�������Ϊ�����������������롣" << endl;
                    f = 1;
                }
                else f = 2;
            } while (f == 1);
            //���ܿ�ʼ
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
            cout << endl << "�����ܺ�����Ϊ��" << endl;
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
    cout << "��ѡ��ģʽ:��1�����ܣ�2�����ܣ�" <<endl;
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