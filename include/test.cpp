#include "DA/exception.hpp"
[[noreturn]] void f()
try
{
  DA_THROW_1("test");
}
DA_CATCH_EXCEPTION
[[noreturn]] void g()
try
{
  f();
}
DA_CATCH_EXCEPTION


int main()
try
{
  g();
}
DA_MAIN_CATCH_EXCEPTION
