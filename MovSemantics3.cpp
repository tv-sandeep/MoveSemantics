#include "Header.h"

class MyString2
{
public:
		MyString2() = default;
		MyString2(const char* String)
		{
			printf("Created\n");
			m_Size = strlen(String);
			m_data = new char[m_Size + 1];
			strcpy_s(m_data, m_Size + 1, String);
		}
		MyString2(const MyString2& RHS)
		{
			printf("Copied\n");
			m_Size = RHS.m_Size;
			m_data = new char[m_Size + 1];
			strcpy_s(m_data, m_Size + 1, RHS.m_data);
		}
		MyString2(MyString2&& RHS) noexcept
		{
			printf("Moved\n");
			m_Size = RHS.m_Size;
			m_data = RHS.m_data;
			//To avoid crash in destructor
			RHS.m_Size = 0;
			RHS.m_data = NULL;
		}
		~MyString2()
		{
			printf("Destroyed\n");
			if (m_data)
				delete m_data;
			m_data = nullptr;
			m_Size = 0;
		}
private:
	int m_Size;
	char* m_data;
};

class Entity2
{
public:
	Entity2(const MyString2& Name):m_name(Name)
	{
		printf("Entity2 Default constructor\n");
	}
	//Entity2(MyString2&& Name) :m_name(Name)//Still it calls copy constructor
	Entity2(MyString2&& Name) :m_name(std::move(Name))
	{//or Entity2(MyString2&& Name) :m_name((MyString2&&)Name)
		printf("Entity2 rvalue constructor\n");
	}
private:
	MyString2 m_name;
};

void MoveSemantics3()
{
	{
		Entity2 oEnt("Sandeep");
		printf("");
	}
	printf("");
}