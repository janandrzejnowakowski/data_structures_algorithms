//
// Created by noj on 21.11.20.
//

#include <iostream>
#include <data_structures/Stack.h>

bool isOpeningBracket(char bracket)
{
    std::string opening_brackets = "([{";
    return opening_brackets.find(bracket) != std::string::npos;
}

bool isClosingBracket(char bracket)
{
    std::string opening_brackets = ")]}";
    return opening_brackets.find(bracket) != std::string::npos;
}

bool areSiblingBrackets(char opening, char closing)
{
    std::string opening_brackets = "([{";
    std::string closing_brackets = ")]}";

    return opening_brackets.find(opening) == closing_brackets.find(closing);
}

bool areValidBrackets(const std::string& brackets)
{

    Stack<char> all;
    for (char each : brackets)
    {
        if (isOpeningBracket(each))
            all.push(each);
        else if (isClosingBracket(each))
        {
            if (!areSiblingBrackets(all.pop(), each))
                return false;
        } else
            return false;
    }
    return all.empty();
}