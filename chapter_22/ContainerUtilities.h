#ifndef CONTAINERUTILITIES_H
#define CONTAINERUTILITIES_H

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace exercise22
{
    template<typename ElementType, typename ContainerType>
    ElementType maxElement(ContainerType& container)
    {
        typename ContainerType::iterator iterator = container.begin();
        ElementType result = *iterator;

        for (; iterator != container.end(); iterator++)
        {
            if (*iterator > result)
                result = *iterator;
        }

        return result;
    }

    template<typename ElementType, typename ContainerType>
    ElementType minElement(ContainerType& container)
    {
        typename ContainerType::iterator iterator = container.begin();
        ElementType result = *iterator;

        for (; iterator != container.end(); iterator++)
        {
            if (*iterator < result)
                result = *iterator;
        }

        return result;
    }

    template<typename ElementType, typename ContainerType>
    int find(ContainerType& container, const ElementType& value)
    {
        int position = 0;
        for (typename ContainerType::iterator iterator = container.begin(); iterator != container.end(); iterator++)
        {
            if (*iterator == value)
                return position;
            position++;
        }

        return -1;
    }

    template<typename ElementType, typename ContainerType>
    int countElement(ContainerType& container, const ElementType& value)
    {
        int count = 0;
        for (typename ContainerType::iterator iterator = container.begin(); iterator != container.end(); iterator++)
        {
            if (*iterator == value)
                count++;
        }

        return count;
    }

    template<typename ContainerType>
    void reverse(ContainerType& container)
    {
        if (container.begin() == container.end())
            return;

        typename ContainerType::iterator first = container.begin();
        typename ContainerType::iterator last = container.end();
        last--;

        while (true)
        {
            if (first == last)
                break;

            std::swap(*first, *last);
            first++;

            if (first == last)
                break;

            last--;
        }
    }

    template<typename ElementType, typename ContainerType>
    void remove(ContainerType& container, const ElementType& value)
    {
        for (typename ContainerType::iterator iterator = container.begin(); iterator != container.end(); iterator++)
        {
            if (*iterator == value)
            {
                container.erase(iterator);
                return;
            }
        }
    }

    template<typename ElementType, typename ContainerType>
    void replace(ContainerType& container, const ElementType& oldValue, const ElementType& newValue)
    {
        for (typename ContainerType::iterator iterator = container.begin(); iterator != container.end(); iterator++)
        {
            if (*iterator == oldValue)
                *iterator = newValue;
        }
    }

    template<typename ElementType>
    void setUnion(std::set<ElementType>& s1, std::set<ElementType>& s2, std::set<ElementType>& s3)
    {
        s3.clear();

        for (typename std::set<ElementType>::iterator iterator = s1.begin(); iterator != s1.end(); iterator++)
            s3.insert(*iterator);

        for (typename std::set<ElementType>::iterator iterator = s2.begin(); iterator != s2.end(); iterator++)
            s3.insert(*iterator);
    }

    template<typename ElementType>
    void difference(std::set<ElementType>& s1, std::set<ElementType>& s2, std::set<ElementType>& s3)
    {
        s3.clear();

        for (typename std::set<ElementType>::iterator iterator = s1.begin(); iterator != s1.end(); iterator++)
        {
            if (s2.find(*iterator) == s2.end())
                s3.insert(*iterator);
        }
    }

    template<typename ContainerType>
    void printContainer(const ContainerType& container)
    {
        for (typename ContainerType::const_iterator iterator = container.begin(); iterator != container.end(); iterator++)
            std::cout << *iterator << " ";
        std::cout << std::endl;
    }

    inline std::string cleanWord(const std::string& word)
    {
        std::string result;
        for (int i = 0; i < static_cast<int>(word.length()); i++)
        {
            if (std::isalpha(static_cast<unsigned char>(word[i])))
                result += static_cast<char>(std::tolower(static_cast<unsigned char>(word[i])));
        }

        return result;
    }

    inline std::set<std::string> getCppKeywords()
    {
        const char* words[] = {
            "asm", "auto", "bool", "break", "case", "catch", "char", "class", "const",
            "const_cast", "continue", "default", "delete", "do", "double", "dynamic_cast",
            "else", "enum", "explicit", "export", "extern", "false", "float", "for",
            "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
            "new", "operator", "private", "protected", "public", "register",
            "reinterpret_cast", "return", "short", "signed", "sizeof", "static",
            "static_cast", "struct", "switch", "template", "this", "throw", "true",
            "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
            "virtual", "void", "volatile", "wchar_t", "while"
        };

        std::set<std::string> keywords;
        for (int i = 0; i < 63; i++)
            keywords.insert(words[i]);

        return keywords;
    }

    inline std::vector<std::string> extractCppTokens(std::istream& input)
    {
        std::vector<std::string> tokens;
        std::string token;
        bool inLineComment = false;
        bool inBlockComment = false;
        bool inString = false;
        bool inChar = false;
        char previous = '\0';
        char ch;

        while (input.get(ch))
        {
            if (inLineComment)
            {
                if (ch == '\n')
                    inLineComment = false;
                continue;
            }

            if (inBlockComment)
            {
                if (previous == '*' && ch == '/')
                    inBlockComment = false;
                previous = ch;
                continue;
            }

            if (inString)
            {
                if (ch == '"' && previous != '\\')
                    inString = false;
                previous = ch;
                continue;
            }

            if (inChar)
            {
                if (ch == '\'' && previous != '\\')
                    inChar = false;
                previous = ch;
                continue;
            }

            if (previous == '/' && ch == '/')
            {
                if (!token.empty())
                {
                    token.erase(token.length() - 1);
                    if (!token.empty())
                        tokens.push_back(token);
                    token.clear();
                }
                inLineComment = true;
                previous = ch;
                continue;
            }

            if (previous == '/' && ch == '*')
            {
                if (!token.empty())
                {
                    token.erase(token.length() - 1);
                    if (!token.empty())
                        tokens.push_back(token);
                    token.clear();
                }
                inBlockComment = true;
                previous = ch;
                continue;
            }

            if (ch == '"')
            {
                if (!token.empty())
                {
                    tokens.push_back(token);
                    token.clear();
                }
                inString = true;
                previous = ch;
                continue;
            }

            if (ch == '\'')
            {
                if (!token.empty())
                {
                    tokens.push_back(token);
                    token.clear();
                }
                inChar = true;
                previous = ch;
                continue;
            }

            if (std::isalnum(static_cast<unsigned char>(ch)) || ch == '_')
            {
                token += ch;
            }
            else if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }

            previous = ch;
        }

        if (!token.empty())
            tokens.push_back(token);

        return tokens;
    }

    inline int countCppKeywordsInFile(const std::string& fileName)
    {
        std::ifstream input(fileName.c_str());
        if (!input)
            return -1;

        std::set<std::string> keywords = getCppKeywords();
        std::vector<std::string> tokens = extractCppTokens(input);
        int count = 0;

        for (int i = 0; i < static_cast<int>(tokens.size()); i++)
        {
            if (keywords.find(tokens[i]) != keywords.end())
                count++;
        }

        return count;
    }

    inline std::map<std::string, int> countEachCppKeywordInFile(const std::string& fileName)
    {
        std::ifstream input(fileName.c_str());
        std::map<std::string, int> counts;

        if (!input)
            return counts;

        std::set<std::string> keywords = getCppKeywords();
        std::vector<std::string> tokens = extractCppTokens(input);

        for (int i = 0; i < static_cast<int>(tokens.size()); i++)
        {
            if (keywords.find(tokens[i]) != keywords.end())
                counts[tokens[i]]++;
        }

        return counts;
    }
}

#endif
