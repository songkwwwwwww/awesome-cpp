#include <iostream>
#include <string>

#define FUNC_START std::cout << __FUNCTION__ << " start." << std::endl;
#define FUNC_END std::cout << __FUNCTION__ << " end." << std::endl;

void test_1() {
  FUNC_START
  std::wstring_view wcstr_v = L"xyzzy";

  char array[3] = {'B', 'a', 'r'};
  std::string_view array_v(array, std::size(array));

  std::string cppstr = "Foo";
  std::string_view cppstr_v(&cppstr[0], cppstr.size());

  std::cout << cppstr_v << '\n' << array_v << '\n' << wcstr_v.size() << '\n';
  FUNC_END
}

void test_lstrip() {
  FUNC_START
  std::string cppstr = "          Foo is Bar.  ";
  std::string_view cppstr_v(cppstr);

  std::cout << "cppstr_v: " << cppstr_v << std::endl;

  cppstr_v.remove_prefix(
      std::min(cppstr_v.find_first_not_of(" "), cppstr_v.size()));

  std::cout << "after lstrip, cppstr_v: " << cppstr_v << std::endl;

  FUNC_END
}

void test_rstrip() {
  FUNC_START

  std::string cppstr = "          Foo is Bar.        ";
  std::string_view cppstr_v(cppstr);

  std::cout << "cppstr_v: " << cppstr_v << std::endl;

  cppstr_v.remove_suffix(std::min(
      cppstr_v.size() - cppstr_v.find_last_not_of(" ") - 1, cppstr_v.size()));

  std::cout << "after lstrip, cppstr_v: " << cppstr_v << std::endl;

  FUNC_END
}

int main() {
  test_1();
  test_lstrip();
  test_rstrip();
}
