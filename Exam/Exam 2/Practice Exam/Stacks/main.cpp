#include <iostream>
#include "Stack.h"
using namespace std;

string reverseString(string input)
{
  // implement the function.
  	Stack<string> s;
	int index = input.find(' ');
	while(index!=-1)
	{
		s.push(input.substr(0, index));
		input = input.substr(index+1, string::npos);
		index = input.find(' ');
	}
	s.push(input.substr(0, string::npos));
	string output;
	while(!s.isEmpty())
	{
		if(output!="")
			output += " ";
		output += s.top();
		s.pop();
	}
	return output;
}

int main()
{
	std::string input;
	
	getline(cin, input);
	std::string output = reverseString(input);
	std::cout << output << std::endl;
	
	return 0;
}