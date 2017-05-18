// Chapter8Exercise2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h> // for strcpy(), strcat()
#include <stdlib.h> // for exit()

class String
{
	static const int SZ = 80;	//size of string object
	char str[SZ];				// holds string
public:
	String()					//Constructor no arguments
	{
		strcpy_s(str, "");
	}
	String(char s[])			//Constructor one argument
	{
		strcpy_s(str, s);
	}
	void display() const		//display the String
	{
		std::cout << str << std::endl;
	}
	String operator + (String ss) const //Add strings
	{
		String temp;			// make temprorary String
		if (strlen(str) + strlen(ss.str) < SZ)
		{
			strcpy_s(temp.str, str); //copy this string to temp
			strcat_s(temp.str, ss.str); // add the argument string
		}
		else
		{
			std::cout << "\nString overflow"; exit(1);
		}
		return temp;
	}

	String operator += (String ss) const //Add strings
	{
		String temp;			// make temprorary String
		if (strlen(str) + strlen(ss.str) < SZ)
		{
			strcpy_s(temp.str, str); //copy this string to temp
			strcat_s(temp.str, ss.str); // add the argument string
		}
		else
		{
			std::cout << "\nString overflow"; exit(1);
		}
		return temp;
	}
};

int main()
{
	String s1{ "\nMerry Christmas " }; // uses constructor2
	String s2{ "Happy New Year" };	 // uses constructor 2
	String s3;						 // uses constructor 1	

	s1.display();
	s2.display();
	s3.display();

	s3 = s1 + s2;

	std::cout << "together: " << std::endl;
	s3.display();


	s1 += s2;
	std::cout << "together with +=: " << std::endl;
	s3.display();
	system("pause");
    return 0;
}

