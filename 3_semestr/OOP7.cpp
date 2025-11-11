#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> st1; 
    stack<char> st2;
    int x;
    cout << "Введите количество данных для стека: " << endl;
    cin >> x;
    cout << "Введите данные для стека: " << endl;
    char data;
    for (int i = 0; i < x; i ++){
        cin >> data;
        st1.push(data);
    }
    stack<char> print_stack = st1;
    cout<<"Данные из стека 1: "<<endl;
    while(!print_stack.empty()){
        cout<<print_stack.top()<<" ";
        print_stack.pop();
    }
    cout << "\n";
    stack<char> third_element = st1;
    int count = 0;
    while(!third_element.empty()){
        char element = third_element.top();
        third_element.pop();
        if (count % 3 == 0){
            st2.push(element);
        }
        count ++;
    }
    cout<<"Данные из стека 2: "<<endl;
    while(!st2.empty()){
        cout<<st2.top() << " ";
        st2.pop();
    }
     cout << "\n";
    return 0;
}
