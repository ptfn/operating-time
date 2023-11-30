#include <string>
#include <iostream>

std::string reverse_words(const std::string& str) {
    std::string result (str.size(), ' ');
  
    for (int i = str.size(), e = str.size(); i > 0; i--) {
        if (str[i] == ' ') {
            for (int j = i; j < e; j++) {
                result += str[i];
                e = i;
            }
        }
  }
  return result;
}

int main()
{
    const std::string test = "Hello Wordl!";
    std::string result = reverse_words(test);
    std::cout << result << std::endl;
}
