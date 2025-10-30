#include<iostream>
using namespace std;

string Convert_Int_To_Binary(int a)
{
    string res;
    int count = 0;
    while(a > 0)
    {
        if(a%2)
        {
            res.push_back('1');
        }
        else
        {
            res.push_back('0');
        }
        a = a/2;
        count++;
    }

    while(count < 32)
    {
        res.push_back('0');
        count++;
    }
    reverse(res.begin(), res.end());
    return res;
}

int Convert_Binary_To_Int(string str)
{
    int num = 0;
    for(int i = 31; i >= 0; i--)
    {
        if(str[i] == '1')
        {
            num = num + pow(2, 31-i);
        }
    }
    return num;
}

int convertnumber(int a)
{
    int n = 0;
    for(int i = 0; i < 32; i++)
    {
        if (a & 1)
        {
            n += pow(2, 31-i);
        }
        a = a >> 1;
    }
    return n;
}

int main()
{
    int a = 43261596;
    cout << convertnumber(a);
    //cout << a << " binary representation: " << Convert_Int_To_Binary(a) << endl;
    //string str = "00000010100101000001111010011100";
    //cout << "numerical representation: " << Convert_Binary_To_Int(str) << endl;
    return 0;
}