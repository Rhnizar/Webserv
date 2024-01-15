// string::substr
#include <iostream>
#include <string>

int main ()
{
  std::string str="We think in generalities, but we live in details.    ";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos + 1);     // get from "live" to the end

  std::cout << str2 << " / " << str3 << '\n';

	std::cout << "before=  " << str << std::endl;
  std::cout << str.find_last_not_of(" \t") << std::endl;
  str.erase(str.find_last_not_of(" \t") + 1);
  std::cout << "after=  " << str << std::endl;

  return 0;
}