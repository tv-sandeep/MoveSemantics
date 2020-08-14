#include "Header.h"

class MyString
{
public:
		MyString() = default;
		MyString(const char* String)
		{
			printf("Created\n");
			m_Size = strlen(String);
			m_data = new char[m_Size + 1];
			strcpy_s(m_data, m_Size + 1, String);
		}
		~MyString()
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

class Entity
{
public:
	Entity(const MyString& Name):m_name(Name)
	{

	}
private:
	MyString m_name;
};

void MoveSemantics1()
{
	{
		Entity oEnt("Sandeep");
		printf("");
	}
	printf("");
	//It is crashing because of no copy constructor
}