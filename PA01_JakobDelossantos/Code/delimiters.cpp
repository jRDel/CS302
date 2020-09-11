//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include "StackLinked.cpp"

#if LAB6_TEST1
#   include "StackLinked.cpp"
#else
#   include "StackArray.cpp"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression )
{
    StackLinked<char> stackOne;

    for(unsigned int i=0; i<expression.length(); i++)
    {
        if(expression[i]=='(' || expression[i]=='[') //if its an opening you can push onto the stack
        {
            stackOne.push(expression[i]);
        }
        else if(expression[i]==')' || expression[i]==']') //if its a closing you can pop off the stack because that means matched
        {
            stackOne.pop();
        }
        else{
            //do nothing
        }
    }

    if(stackOne.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
    

}

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars
    int option;
    cout << "This program checks for properly matched delimiters."
         << endl;
    cout<<"Input 1 to put in your own delimited expression, or 2 to go through 5 pre-made test cases: "<<endl;
    cin>>option;

    if(option==1)
    {
        cin.ignore();
        while( cin )
        {
            
            cout << "Enter delimited expression (<EOF> to quit) : "
                << endl;

            // Read in one line
            inputLine = "";
            cin.get(ch);
            while( cin && ch != '\n' )
            {
                inputLine = inputLine + ch;
                cin.get(ch);
            }

            if( ! cin )              // Reached EOF: stop processing
                break;
        
            if ( delimitersOk (inputLine) )
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        }
    }
    else
    {
        cout<<"Testing delimited expression a=(f(b)-(c+d))/2, which should return valid: ";
        //delimitersOk("a=(f(b)-(c+d))/2");
        if ( delimitersOk ("a=(f(b)-(c+d))/2") )
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        cout<<endl;

        cout<<"Testing delimited expression a=(f(b)-(c+d)/2, which should return invalid: ";
        //delimitersOk("a=(f(b)-(c+d)/2");
        if ( delimitersOk ("a=(f(b)-(c+d)/2") )
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        
        cout<<endl;

        cout<<"Testing delimited expression a=[f(b-(c+d)], which should return invalid: ";
        //delimitersOk("a=[f(b-(c+d)]");
        if ( delimitersOk ("a=[f(b-(c+d)]") )
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        cout<<endl;

        cout<<"Testing delimited expression a=[f(b+d)-(c)], which should return valid: ";
        //delimitersOk("a=[f(b+d)-(c)]");
        if ( delimitersOk ("a=[f(b+d)-(c)]") )
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        cout<<endl;

        cout<<"Testing delimited expression a=(f(c)+[d-b]), which should return valid: ";
        //delimitersOk("a=(f(c)+[d-b])");
        if ( delimitersOk ("a=(f(c)+[d-b])") )
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        cout<<endl;

        cout<<"END TESTING"<<endl;
    }
    
    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below




