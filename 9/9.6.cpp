#include <string>
#include <stack>
#include <iostream>
using namespace std;

int priorityOpt(char);//判断符号优先级
void compute(stack<int>&, char);//计算
int getNum(string&, int&);//取数字
int caculator(string&);//计算器

int main()
{
    string s = "(1+(5+32)*2)";
    cout<<caculator(s)<<endl;
    return 0;
}

int priorityOpt(char opt)
{
    switch (opt)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    default:
        return 0;
    }
}

void compute(stack<int>& val, char opt)
{
    int right = val.top();
    val.pop();
    int left = val.top();
    val.pop();
    int res = 0;
    switch (opt)
    {
    case '+':
        res = left+right;
        break;
    case '-':
        res = left-right;
        break;
    case '*':
        res = left*right;
        break;
    case '/':
        res = left/right;
        break;
    default:
        break;
    }
    val.push(res);
}

int getNum(string& s, int& index)
{
    string numbers="0123456789";
    int left = index;
    ++index;
    while(index!=s.find_first_not_of(numbers,index))
        ++index;
    return stoi(s.substr(left,index));
}

int caculator(string &s)
{
    stack<char> symbol;
    stack<int> val;
    int res = 0;
    int index = 0;
    int tmp;
    while(index<s.size())
    {
        if(s[index]=='(')
            symbol.push(s[index++]);
        else if(s[index]==')')
        {
            while(symbol.top()!='(')
            {
                compute(val,symbol.top());
                symbol.pop();
            }
            symbol.pop();
            ++index;
        }
        else if(s[index] == '+' || s[index] == '-' || s[index]=='*' || s[index]=='/')
        {
            if(symbol.empty())
                symbol.push(s[index]);
            else if (priorityOpt(s[index]) > priorityOpt(symbol.top())) {
				symbol.push(s[index]);
			}else {
				compute(val, symbol.top());
				symbol.pop();
				symbol.push(s[index]);
			}
			index++;
        }
        else
        {
            int num = getNum(s,index);
            val.push(num);
        }
    }
    while(!symbol.empty())
    {
        compute(val,symbol.top());
        symbol.pop();
    }
    return val.top();
}