/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <regex>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    
    std::string s = "1) Элемент 1.1) Элемент 1.2) Элемент 2) Элемент 2.1) Элемент 2.1.1) Элемент 2.1.1.5) Элемент";
    
    const regex word_regex(R"((\d)((\.\d)*)\)\s*\S*)");
    
    auto words_begin = 
        std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
    
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (!(match.size() >= 2)) continue;
        
        auto sub_string = match[2].str();
        
        auto tab_count = std::count(sub_string.begin(), sub_string.end(), '.');

        std::cout << std::string(tab_count, '\t') << match_str /*<< " | " << match[1].str() << "\t" << match[2].str() << "\t" << tab_count*/ <<  '\n';
    }
    
    

    return 0;
}
