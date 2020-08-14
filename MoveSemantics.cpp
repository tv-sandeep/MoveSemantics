#include <iostream>

using namespace std;

int GetValue()
{
    return 10;
}

int& GetValue1()
{
    int b = 10;
    return b;
}

void SetValue(int a)
{

}

void SetValue1(int& a)
{

}

void SetValue2(const int& a)
{

}

void PrintName(std::string& Name)
{
    cout << Name << endl;
}

void PrintName1(const std::string& Name)
{
    cout << Name << endl;
}

void PrintName2(std::string&& Name)
{
    cout << Name << endl;
}


void PrintName3(const std::string& Name)
{
    cout << "Lvalue: "<< Name << endl;
}

void PrintName3(std::string&& Name)
{
    cout << "Rvalue: " << Name << endl;
}

int main()
{
    //Lvalues are basically variables that have storage
    // Rvalues are temporary values
    // Lvalue references(&) can only take l values unless they have const
    // Rvalue references (&&) only take r values.  (although they have const they wont allow lvalues)
    //--------------------------------------------------------------------------
    int i = 10;//i is lvalue, 10 is rvalue
    int a = i;//both are l values
    int b = GetValue();// GetValue() is r value because GetValue() = 10 wont work
    int c = GetValue1();// GetValue1() is l value because GetValue1() = 10 will work
    GetValue1() = 5;//it works because the return type is reference(&)
    cout << "Hello World!\n";

    SetValue(a);
    SetValue(15);

    SetValue1(a);
    //SetValue1(15);//This will give compile error because it is SetValue1 expecting lvalue reference
    //SetValue1(b + c); //This also throws error.

    //int& d = 10;//Compile error expecting lvalue
    const int& d = 10;//Works fine because of const
    //The compiler actually create a temporary variable and assign it.
    //const int& d = 10; compiler converts this into int temp = 10;
    //                                              const int& d = temp;

    SetValue2(a);
    SetValue2(15);//accepts both lvalue and rvalue because function expects const l value refrence
    //--------------------------------------------------------------------------

    
    //--------------------------------------------------------------------------
    std::string firstName = "Sandeep";
    std::string lastName = " T V";
    std::string fullName = firstName + lastName;
    //In this case all left side values are l values and right side values are rvalues.

    PrintName(fullName);//works fine because lvalue reference
    //PrintName(firstName + lastName); //compile error because it is rvalue
    PrintName1(fullName);
    PrintName1(firstName + lastName);
    //Accepts both because of const

    //By using PrintName() or SetValue1() we can really find which is l value or which is r value
    //Because lvalues reference expects only l values
    //--------------------------------------------------------

    //--------------------------------------------------------
    //We can right a function which accepts only rvalues.
    //PrintName2(fullName); //Will get compile error because expecting rvalues only
    PrintName2(firstName + lastName);
    //--------------------------------------------------------


    //--------------------------------------------------------
    PrintName3(fullName);
    PrintName3(firstName + lastName);
    //void PrintName3(const std::string& Name)
    //Although this function accepts both l value and rvalue
    //PrintName3(firstName + lastName); will go to void PrintName3(std::string&& Name)
    //because the compile will search first rvalue reference.
    //This is very usefull in move semantics
    //--------------------------------------------------------

    return 0;
}