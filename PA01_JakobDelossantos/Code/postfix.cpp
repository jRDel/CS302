//This file is the postfix assignment implementation.

#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "StackLinked.cpp"

using namespace std;
/*string convertToPostFix(string* infix)
{

	StackLinked<char> operatorStack;
	string postfixExpression;
	
	int i=0;
	while(i<infix.length())
	{
	
		if(infix[i]==' ')
		{
			i++;
			char nextCharacter = infix[i];
			process(nextCharacter, postfixExpression);
			i++;
		}
		else
		{
			char nextCharacter = infix[i];
			process(nextCharacter, postfixExpression);
			i++;
		}
	}
	
	while(!operatorStack.isEmpty())
	{
	
		char topOperator = operatorStack.pop();
		postfixExpression+topOperator;
		
	}
	
return postfixExpression;

}
			
string process(char nextC, string & postfixExpression)
{

	switch(nextC)
	{
		case '0':case '1':case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		
			postfixExpression+nextC;
		
		case '^':
			
			operatorStack
	
*/
	
	
	
	
	
	
	
	
	
	
	
	
	
int main()
{

	char postfixExpression[25];
	StackLinked<float> stackOne;
	char character;
	float characterPush;
	char op1;
	char op2;
	float operand1;
	float operand2;
	float result;
	char resultPush;
	
	
	cout<<"Please input a postfix expression with a max size of 10 characters (operands, operators):"<<endl;
	cin>>postfixExpression;
	
	for(int i=0; i<strlen(postfixExpression); i++)
	{
	
		character=postfixExpression[i];
		
		switch(character)
		{
		
			case '0':case '1':case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				characterPush=static_cast<float>(character-'0');
				stackOne.push(characterPush);
				break;
			
			case '^':
				operand1=stackOne.pop(); //pop two numbers off the stack
				operand2=stackOne.pop();
				
				
					result=1.0f;
					for(int i=1; i<=operand1; i++)
					{
					
						result = result*operand2;
						
					}
				
				cout<<result<<endl;
				stackOne.push(result); //push onto the stack
				
				break;
				
			case '*':
				operand1=stackOne.pop(); //pop two numbers off the stack
				operand2=stackOne.pop();
				
				result=operand2*operand1; //perform +
				
				stackOne.push(result); //push onto stack
				
				break;
				
			case '/':
				operand1=stackOne.pop(); //pop two numbers off the stack
				operand2=stackOne.pop();
				
				result=operand2/operand1; //perform +
				
				stackOne.push(result); //push onto stack
				
				break;
				
			case '+':
				operand1=stackOne.pop(); //pop two numbers off the stack
				operand2=stackOne.pop();
				
				result=operand2+operand1; //perform +
				
				stackOne.push(result); //push onto stack
				
				break;
			
			case '-':
				operand1=stackOne.pop(); //pop two numbers off the stack
				operand2=stackOne.pop();
				
				result=operand2-operand1; //perform +
				
				stackOne.push(result); //push onto stack
				
				break;
				
			default:
				break;
		}
	}
	
	result=stackOne.pop();
	
	cout<<"The result of the postfix expression after evaluation is: "<<result<<endl;
	
return 0;

}

