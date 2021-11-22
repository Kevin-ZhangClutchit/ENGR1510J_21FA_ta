#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstring>
int main() {
    std::stack<int> number_stack;
    std::stack<char> operator_stack;
    std::string s;
    std::cout << "Input the calculation:" << std::endl;
    std::cin >> s;

    for (auto &item : s) {
        if (strncmp(&item," ",1)==0){
            continue;
        }
        if (std::isdigit((unsigned char) item)!=0){
            number_stack.push(std::stoi(&item));
        }else if (strncmp(&item,"+",1)==0||strncmp(&item,"-",1)==0||strncmp(&item,"*",1)==0||strncmp(&item,"/",1)==0){
            if(operator_stack.empty()){
                operator_stack.push(item);
            }else{
                if (item=='+'||item=='-'){
                    if (operator_stack.top()=='*'||operator_stack.top()=='/'){
                        int a=number_stack.top();
                        number_stack.pop();
                        int b=number_stack.top();
                        number_stack.pop();
                        int result=(operator_stack.top()=='*')?b*a:b/a;
                        operator_stack.pop();
                        number_stack.push(result);
                    }
                    operator_stack.push(item);
                } else{
                    operator_stack.push(item);
                }
            }
        } else{
            throw std::invalid_argument("Invalid input!\n");
        }
    }
    while (!operator_stack.empty()){
        int result;
        int a=number_stack.top();
        number_stack.pop();
        int b=number_stack.top();
        number_stack.pop();
        char oper=operator_stack.top();
        operator_stack.pop();
        switch (oper) {
            case '+':result=b+a;break;
            case '-':result=b-a;break;
            case '*':result=b*a;break;
            case '/':result=b/a;break;
            default:break;
        }
        number_stack.push(result);
    }
    std::cout << "Result: "<<number_stack.top() << std::endl;
    return 0;
}
