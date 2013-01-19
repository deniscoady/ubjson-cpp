#include <iostream>

#include <ubjson/Object.hpp>
#include <ubjson/Boolean.hpp>
#include <ubjson/String.hpp>
#include <ubjson/Array.hpp>

void default_demo();
void custom_demo(char* data);

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		custom_demo(argv[1]);
	}
	else
	{
		default_demo();
	}

	return 0;
}

void custom_demo(char* data)
{
	try
	{
		std::string d = data;
		Element* e = Element::unpack(&d);
	}
	catch (ubjson_exception e)
	{
		std::cout << "[Error]: " << e.what();
	}
}

void default_demo()
{
	try {
		Object o;
		Object d;

		Array q;

		Boolean b = true;

		String a = "foo";
		String p = "bar";

		q.push_back(&a);
		q.push_back(&p);

		d["x"] = &b;
		o["a"] = &d;

		String s = "s97dfs9d7f987sf";
		o["something"] = &s;
		o["doub"] = &d;
		o["arr"] = &q;

		std::string x = o.pack();
		std::cout << x << "\n";

		Element* original = Element::unpack(&x);
		std::cout << original->to_string() << "\n\n";
	}
	catch (ubjson_exception e)
	{
		std::cout << "[Error]: " << e.what();
	}
}