#include <iostream>
#include <vector>
#include <map>

int main(int argc, char const *argv[])
{
    typedef std::map<std::string, int> counter_map;
    typedef std::map<std::string, int>::iterator counter_map_iter;

    counter_map counter;
    std::vector<std::string> text({"ab", "bc", "ab", "x", "b", "x"});
    
    // update counter
    for (std::vector<std::string>::iterator i(text.begin());
         i != text.end();
         i++)
    {
        counter[*i]++;
    }

    // output counter
    for(counter_map_iter i(counter.begin());
        i != counter.end();
        i++)
    {
        // (*i) is a pair object
        // you can access the key and value via:
        // (*i).first; (*i).second;
        std::cout << i->first << " / " << i->second << std::endl;
    }

    return 0;
}