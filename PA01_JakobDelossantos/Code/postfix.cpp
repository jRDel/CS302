//This file is the postfix assignment implementation.

#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "StackLinked.cpp"

using namespace std;

void evaluatePostfix(char postfixExpression[])
{
	
	StackLinked<float> stackOne;
	char character;
	float characterPush;
	float operand1;
	float operand2;
	float result;

	for(unsigned int i=0; i<strlen(postfixExpression); i++)
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
	cout<<"The result of evaluating the postfix form is: "<<result<<endl;
	
}
	
int main()
{
	int option;
	char postfixExpression[25];

	cout<<"Input 1 if you would like to input your own postfix expression, or 2 to test 5 pre-made cases:"<<endl;
	cin>>option;

	if(option==1)
	{
		cout<<"Please input a postfix expression with a max size of 10 characters (operands, operators):"<<endl;
		cin>>postfixExpression;
		evaluatePostfix(postfixExpression);
	}
	else
	{
		char expression[25];
		cout<<"Begin testing with 5 cases..."<<endl;

		cout<<"Testing infix expression (3+4)*(5/2), or postfix 34+52/* (Answer should be 17.5): "<<endl;
		strcpy(expression, "34+52/*");
		evaluatePostfix(expression);

		cout<<"Testing infix expression (5+6)*(4/3), or postfix 56+43/* (Answer should be 14.6667): "<<endl;
		strcpy(expression, "56+43/*");
		evaluatePostfix(expression);

		cout<<"Testing infix expression (2+3)^2, or postfix 23+2^ (Answer should be 25): "<<endl;
		strcpy(expression, "23+2^");
		evaluatePostfix(expression);

		cout<<"Testing infix expression ((5+7)*(8+4))-4, or postfix 57+84+*4- (Answer should be 140): "<<endl;
		strcpy(expression, "57+84+*4-");
		evaluatePostfix(expression);

		cout<<"Testing infix expression ((3+2)-(2+0))^3, or postfix 32+20+-3^ (Answer should be 27): "<<endl;
		strcpy(expression, "32+20+-3^");
		evaluatePostfix(expression);

		cout<<"END TESTING"<<endl;

	}
	
return 0;

}

