#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int evaluate(char op, int op1, int op2)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    default:
        return 0;
    }
}

int evaluateBalanExpression(string expression)
{
    stack<int> s;
    int n = expression.length();

    for (int i = 0; i < n; i++)
    {
        char c = expression[i];

        if (isOperator(c))
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int result = evaluate(c, op1, op2);
            s.push(result);
        }
        else
        {
            int operand = c - '0';
            s.push(operand);
        }
    }

    return s.top();
}

int main()
{
    string expression;
    cout << "Nhap bieu thuc Balan: ";
    cin >> expression;
    int result = evaluateBalanExpression(expression);
    cout << "Ket qua: " << result << endl;
    return 0;
}
