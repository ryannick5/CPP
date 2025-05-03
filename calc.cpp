#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// A simple function to evaluate + and * only for this example
int evaluate_expression(const vector<string> &expression)
{
    int result = stoi(expression[0]);
    for (int i = 1; i < expression.size(); i += 2)
    {
        string op = expression[i];
        int next = stoi(expression[i + 1]);
        if (op == "+")
            result += next;
        else if (op == "-")
            result -= next;
        else if (op == "*")
            result *= next;
        else if (op == "/")
            result /= next;
        else
        {
            cout << "Unknown operator: " << op << endl;
        }
    }
    return result;
}

int main()
{
    int num_ops;
    int num_nums;

    cout << "How many operators will you be using today? ";
    cin >> num_ops;

    cout << "How many numbers will you be using today? ";
    cin >> num_nums;

    if (num_ops != num_nums - 1)
    {
        cout << "Error: number of operators must be one less than number of numbers." << endl;
        return 1;
    }

    vector<string> expression;
    string input;

    // Get first number
    cout << "Enter number 1: ";
    cin >> input;
    expression.push_back(input);

    // Get alternating operator and number
    for (int i = 0; i < num_ops; i++)
    {
        cout << "Enter operator " << (i + 1) << ": ";
        cin >> input;
        expression.push_back(input);

        cout << "Enter number " << (i + 2) << ": ";
        cin >> input;
        expression.push_back(input);
    }

    cout << "Expression entered: ";
    for (string s : expression)
    {
        cout << s << " ";
    }
    cout << endl;

    int result = evaluate_expression(expression);
    cout << "Result: " << result << endl;

    return 0;
}
