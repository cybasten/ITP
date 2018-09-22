#include<iostream>
#include<cstring>
#include "Mystack.h"

using namespace std;

int main()
{
    Mystack<char> opr;
    string pf;
    char next;
    cout << "Enter infix : ";
    cin.get(next);
    cout << "Postfix : ";
    do
    {
        switch(next)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                pf = pf + next;
                if (!opr.isEmpty() && opr.top() != '(' && opr.top() != '+' && opr.top() != '-')
                    pf = pf + opr.pop();
                break;
            case '+':
            case '-':
                if (!opr.isEmpty() && (opr.top() == '+' || opr.top() == '-'))
                    pf = pf + opr.pop();
                opr.push(next);
                break;
            case '*':
            case '/':
            case '(':
                opr.push(next);
                break;
            case ')':
                while(opr.top() != '(' && !opr.isEmpty())
                    pf = pf + opr.pop();
                next = opr.pop();
                if (opr.top() == '*' || opr.top() == '/')
                    pf = pf + opr.pop();
            default:
                break;
        }
        cin.get(next);
    }while(next != '\n');
    while(!opr.isEmpty())
        pf = pf + opr.pop();
    Mystack<int> res;
    int i = 0;
    int a, b;
    do
    {
        switch(pf[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                res.push(pf[i] - 48);
                break;
            case '+':
                b = res.pop();
                a = res.pop();
                res.push(a + b);
                break;
            case '-':
                b = res.pop();
                a = res.pop();
                res.push(a - b);
                break;
            case '*':
                b = res.pop();
                a = res.pop();
                res.push(a * b);
                break;
            case '/':
                b = res.pop();
                a = res.pop();
                res.push(a / b);
                break;
            default:
                break;
        }
        cout << pf[i];
        i++;
    }while(pf[i] != NULL);
    cout << endl;
    cout << "Result = " << res.pop() << endl;
    system("pause");
    return 0;
}
