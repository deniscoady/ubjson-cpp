#include <iostream>

#include <ubjson/Object.hpp>
#include <ubjson/Boolean.hpp>
#include <ubjson/String.hpp>
#include <ubjson/Array.hpp>

int main()
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
	return 0;
}