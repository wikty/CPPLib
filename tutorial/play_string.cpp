#include <iostream>
#include <string>
#include <locale>
#include <algorithm>

bool non_letter(char c)
{
    return not std::isalnum(c, std::locale(""));
}

char lowercase(char c)
{
    return std::tolower(c, std::locale(""));
}

std::string normalize(std::string s)
{
    std::string::iterator end(std::remove_if(s.begin(), s.end(), non_letter));
    
    s.erase(end, s.end());

    std::transform(s.begin(), s.end(), s.begin(), lowercase);

    return s;
}


int main(int argc, char* argv[])
{
    // output "
    std::cout << "\"" << '\n';

    // complier'll join the adjacent strings to a string
    std::cout << "1\n"
                 "2\n"
                 "3\n";
    std::cout << "1\n""2\n""3\n";

    // empty string is nothing
    std::string empty;
    std::cout << "*" << empty << "*\n";

    // init string
    std::string fruit("apple");
    std::cout << fruit << "\n";

    // string size
    std::string::size_type len = fruit.size();
    std::cout << len << '\n';

    std::cout << "ab8&*3-00^"
              << std::endl
              << normalize("ab8&*3-00^")
              << std::endl;
}