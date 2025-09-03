#include <iostream>
#include <string>
#include <stdio.h>

std::string	capitalise_string(std::string lower_case_string);

int main(int argc, char *argv[])
{
	std::string	args;

	//check arguments
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}

	// Build one string with all the arguments with spaces in between simply by adding
	for (int i = 1; i < argc ; i++)
		args += argv[i];

	// Once full string, capitalise it in the dedicated helper function
	std::cout << capitalise_string(args) << std::endl;

	return 0;
}

std::string	capitalise_string(std::string string_to_capitalise)
{
	for (size_t i=0; i<string_to_capitalise.length(); i++)
		string_to_capitalise[i] = std::toupper(string_to_capitalise[i]);
	return (string_to_capitalise);
}
