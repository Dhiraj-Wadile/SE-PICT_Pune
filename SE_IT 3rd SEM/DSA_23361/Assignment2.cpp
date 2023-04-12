#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

template <class T>
class stack
{
public:
    Node<T> *top;

    stack()
    {
        top = NULL;
    }

    bool Isempty()
    {
        return (top == NULL);
    }

    void push(T ch)
    {
        Node<T> *temp = new Node<T>;
        temp->data = ch;
        temp->next = top;
        top = temp;
    }

    T pop()
    {
        Node<T> *temp = new Node<T>;

        if (!Isempty())
        {
            temp = top;
            top = temp->next;
            return temp->data;
        }
        else
        {
            return -1;
        }
    }

    void display()
    {
        Node<T> *temp = new Node<T>;
        temp = top;
        if (temp == NULL)
        {
            cout << "\nStack is empty." << endl;
        }
        else
        {
            cout << "\nThe Stack is: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << "\n";
    }

    T peek()
    {
        return (top->data);
    }

    int getpriority(char op)
    {
        if (op == '+' || (op == '-'))
        {
            return 1;
        }
        else if (op == '/' || op == '*')
        {
            return 2;
        }
        else if (op == '%')
        {
            return 3;
        }
        else if (op == '^')
        {
            return 4;
        }
        else
        {
            return -1;
        }
    }

    string infixToPostfix(string s)
    {
        stack<int> st;
        string res;

        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                res += s[i];
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while ((!st.Isempty()) && (st.peek() != '('))
                {
                    res += st.peek();
                    st.pop();
                }
                if (!st.Isempty())
                {
                    st.pop();
                }
            }
            else
            {
                while ((!st.Isempty()) && (getpriority(st.peek()) > getpriority(s[i])))
                {
                    res += st.peek();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.Isempty())
        {
            res += st.peek();
            st.pop();
        }
        return res;
    }

    int evaluatePostfix(string s)
    {
        stack<int> obj;
        int i;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                obj.push(s[i] - '0');
            }
            else
            {
                int op2 = obj.peek();
                obj.pop();
                int op1 = obj.peek();
                obj.pop();

                switch (s[i])
                {
                case '+':
                    obj.push(op1 + op2);
                    break;
                case '-':
                    obj.push(op1 - op2);
                    break;
                case '*':
                    obj.push(op1 * op2);
                    break;
                case '/':
                    obj.push(op1 / op2);
                    break;
                case '^':
                    obj.push(pow(op1, op2));
                    break;
                }
            }
        }
        return obj.peek();
    }

    string infixToPrefix(string s)
    {
        /*for (int i = 0; i < str.length(); i++)
        {
            if (str[i] = '(')
            {
                str[i] = ')';
            }
            else
            {
                str[i] = '(';
            }
        }
        string res = infixToPostfix(str);*/
        stack<char> st;
        string res;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                res += s[i];
            }
            else if (s[i] == ')')
            {
                st.push(s[i]);
            }
            else if (s[i] == '(')
            {
                while ((!st.Isempty()) && (st.peek() != ')'))
                {
                    res += st.peek();
                    st.pop();
                }
                if (!st.Isempty())
                {
                    st.pop();
                }
            }
            else
            {
                while ((!st.Isempty()) && (getpriority(st.peek()) > getpriority(s[i])))
                {
                    res += st.peek();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.Isempty())
        {
            res += st.peek();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    int evaluatePrefix(string s)
    {
        stack<int> obj3;
        int i;
        for (i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                obj3.push(s[i] - '0');
            }
            else
            {
                int op2 = obj3.peek();
                obj3.pop();
                int op1 = obj3.peek();
                obj3.pop();

                switch (s[i])
                {
                case '+':
                    obj3.push(op1 + op2);
                    break;
                case '-':
                    obj3.push(op1 - op2);
                    break;
                case '*':
                    obj3.push(op1 * op2);
                    break;
                case '/':
                    obj3.push(op1 / op2);
                    break;
                case '^':
                    obj3.push(pow(op1, op2));
                    break;
                }
            }
        }
        return obj3.peek();
    }
};

int main()
{
    int choice;
    stack<char> S1;
    string infix_exp, postfix_exp, infix_ex, infix_ex1;
    string result;

    do
    {
        cout << "\n---Operations Using Stack---";
        cout << "\n1.Infix to postfix";
        cout << "\n2.Evaluation of postfix";
        cout << "\n3.Infix to prefix";
        cout << "\n4.Evaluation of prefix";
        cout << "\n5.Exit";
        cout << "\n--------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter a Infix Expression: ";
            cin >> infix_exp;
            postfix_exp = S1.infixToPostfix(infix_exp);
            cout << "\nPostfix Expression: " << postfix_exp;
            break;
        case 2:
            cout << "\nEnter postfix expression to evaluate: ";
            cin >> result;
            cout << "\nPostfix Evaluation: " << S1.evaluatePostfix(result);
            break;
        case 3:
            cout << "\nEnter infix Expression: ";
            cin >> infix_ex;
            cout << "\nPrefix expression: " << S1.infixToPrefix(infix_ex);
            break;
        case 4:
            cout << "\nEnter prefix expression to evaluate: ";
            cin >> infix_ex1;
            cout << "\nPrefix Evaluation: " << S1.evaluatePrefix(infix_ex1);
            break;
        case 5:
            cout << "\nExiting the program!";
            break;
        default:
            cout << "\nInvalid choice.";
        }
    } while (choice < 5);
}