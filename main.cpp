#include <iostream>
#include <string>
#include <iterator>
#include "LLParserLibrary/LLParser.h"
#include "LLParserLibrary/LLTableBuilderLibrary/TokenLibrary/TokenInformation/TokenInformation.h"

int const REQUIRED_ARGC = 1;
std::string const NO_ARGUMENT_ERROR = "Error: file with rules is not specified";

void Print(std::vector<TokenInformation> const & tokenInformations, size_t from, size_t to, std::string const & color)
{
	std::cout << "\033[" + color + "m";
	StreamPosition outputStreamPosition;
	if (from > 0)
	{
		StreamString previousStreamString = tokenInformations.at(from - 1).GetTokenStreamString();
		outputStreamPosition = previousStreamString.position;
		outputStreamPosition.IncreaseColumn(previousStreamString.string.length());
	}

	for (size_t i = from; i < to && i < tokenInformations.size(); ++i)
	{
		TokenInformation const & tokenInformation = tokenInformations.at(i);
		StreamString const & streamString = tokenInformation.GetTokenStreamString();
		std::string const & streamStringString = streamString.string;
		StreamPosition const & streamPosition = streamString.position;
		long const & line = streamPosition.GetLine();
		long const & column = streamPosition.GetColumn();
		while (line > outputStreamPosition.GetLine())
		{
			std::cout << "\n";
			outputStreamPosition.IncreaseLine();
			outputStreamPosition.SetColumn(1);
		}
		char const indentCharacter = outputStreamPosition.GetColumn() == 1 ? '\t' : ' ';
		while (column > outputStreamPosition.GetColumn())
		{
			std::cout << indentCharacter;
			outputStreamPosition.IncreaseColumn();
		}
		for (char ch : streamStringString)
		{
			std::cout << ch;
			if (ch == '\n' || ch == '\r')
			{
				outputStreamPosition.IncreaseLine();
				outputStreamPosition.SetColumn(1);
			}
			else
			{
				outputStreamPosition.IncreaseColumn();
			}
		}
	}
	std::cout << "\033[m";
}

int main(int argc, char * argv[])
{
	if (argc - 1 < REQUIRED_ARGC)
	{
		std::cerr << NO_ARGUMENT_ERROR << "\n";
		return EXIT_FAILURE;
	}

	LLParser llParser(argv[1]);
	if (argc - 1 > REQUIRED_ARGC)
	{
		std::vector<TokenInformation> tokenInformations;
		size_t failIndex = 0;
		std::unordered_set<Token> expectedTokens;
		if (!llParser.IsValid(argv[2], tokenInformations, failIndex, expectedTokens))
		{
			long shift = tokenInformations.at(failIndex).GetTokenStreamString().position.GetColumn() - 1;
			Print(tokenInformations, 0, failIndex, "32");
			Print(tokenInformations, failIndex, failIndex + 1, "31");
			Print(tokenInformations, failIndex + 1, tokenInformations.size(), "");
			std::cout << "\n";
			for (Token word : expectedTokens)
			{
				std::cout << "\033[m";
				std::cout << std::string(shift, ' ');
				std::cout << "\033[33m";
				std::cout << TokenExtensions::ToString(word);
				std::cout << "\033[m";
				std::cout << "\n";
			}
		}
	}

	return EXIT_SUCCESS;
}
