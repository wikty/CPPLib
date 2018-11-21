#include <iostream>
#include <vector>
#include <map>

std::string filter_invalid_char(std::string src)
{
    std::string charset("ABCDEFGHIJKLMNOPQISTUVWXYZ"
                        "abcdefghijklmnopqistuvwxyz"
                        "0123456789-_");
    std::string target;
    for (std::string::iterator i(src.begin());
         i != src.end(); 
         i++)
    {
        if (charset.find(*i) != std::string::npos)
        {
            target.push_back(*i);
        }
    }
    return target;
}


int main(int argc, char const *argv[])
{
    std::vector<std::string> text({"ab!", "b*c", "ab", "x", "b", "x"});
    std::map<std::string, int> counter;
    
    // update counter
    for (std::vector<std::string>::iterator i(text.begin());
         i != text.end();
         i++)
    {
        std::string s = filter_invalid_char(*i);
        if (not s.empty())
        {
            counter[s]++;
        }
    }

    // output counter
    for(std::map<std::string, int>::iterator i(counter.begin());
        i != counter.end();
        i++)
    {
        // (*i) is a pair object
        // you can access the key and value via:
        // (*i).first; (*i).second;
        std::cout << i->first << " / " << i->second << std::endl;
    }

    // Note: map is a tree, you can find a key in O(log(n))
    // if you want to a hash table, please use hash_map
    std::cout << "Please input the key you want to find:" << std::endl;
    std::string k;
    std::cin >> k;
    std::map<std::string, int>::iterator i = counter.find(k);
    if (i == counter.end())
    {
        std::cout << "Cannot find the key: " << k << std::endl;
    }
    else
    {
        std::cout << "Find the key: " << k << std::endl;   
    }

    return 0;
}