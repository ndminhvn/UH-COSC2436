#include <iostream>
#include "Stack.h"

using namespace std;


bool check_for_symmetry ( string s )
{
    Stack new_stack;
    char x;
 
    // Traversing the session
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '['
            || s[i] == '{') {
            // Push the element in the stack
            new_stack.push(s[i]);
            continue;
        }
 
        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (new_stack.isEmpty())
            return false;
 
        switch (s[i]) {
        case ')':
             
            // Store the top element in a
            x = new_stack.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in b
            x = new_stack.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in c
            x = new_stack.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    // Check Empty Stack
    return (s.empty());
}

int main ( int argc, char **argv)
{
    if ( argc < 2 ) {
        return 0;
    }

    string s1 = argv[1];
    bool flag = check_for_symmetry(s1);
    if ( flag == true ) {
        cout << "session " << s1 << " has matching parantheses" << endl;
    }
    else {
        cout << "session " << s1 << " does not have matching parantheses" << endl;
    }

    return 0;
}