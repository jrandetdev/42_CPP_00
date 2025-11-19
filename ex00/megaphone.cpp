#include <iostream>
#include <string>
#include <stdio.h>

std::string	capitalise_string(std::string lower_case_string);

/**
 * @brief Converts command-line arguments to uppercase and outputs them
 * 
 * If no arguments are provided, outputs a default loud message.
 * Multiple arguments are concatenated together with no spaces.
 * 
 * Example:
 * ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
 * Output: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @return 0 on success
 */
int main(int argc, char *argv[])
{
	std::string	args;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}

	for (int i = 1; i < argc ; i++)
		args += argv[i];

	std::cout << capitalise_string(args) << std::endl;

	return 0;
}

/**
 * @brief Converts all characters in a string to uppercase
 * @param string_to_capitalise The string to convert
 * @return The uppercase version of the input string
 */
std::string	capitalise_string(std::string string_to_capitalise)
{
	for (size_t i=0; i<string_to_capitalise.length(); i++)
		string_to_capitalise[i] = std::toupper(string_to_capitalise[i]);
	return (string_to_capitalise);
}
