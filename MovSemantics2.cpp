#include "Header.h"

class MyString1
{
public:
		MyString1() = default;
		MyString1(const char* String)
		{
			printf("Created\n");
			m_Size = strlen(String);
			m_data = new char[m_Size + 1];
			strcpy_s(m_data, m_Size + 1, String);
		}
		MyString1(const MyString1& RHS)
		{
			printf("Copy constructor\n");
			m_Size = RHS.m_Size;
			m_data = new char[m_Size + 1];
			strcpy_s(m_data, m_Size + 1, RHS.m_data);
		}
		~MyString1()
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

class Entity1
{
public:
	Entity1(const MyString1& Name):m_name(Name)//This line calls copy constructor
	{

	}
private:
	MyString1 m_name;
};

void MoveSemantics2()
{
	{
		Entity1 oEnt("Sandeep");
		//To avoid calling copy constructor
		//we have to use move semantics
		printf("");
	}
	printf("");
}