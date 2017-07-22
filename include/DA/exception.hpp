#ifndef DA_EXCEPTION_HPP
#define DA_EXCEPTION_HPP

#include <boost/current_function.hpp>
#include <boost/exception/all.hpp>
#include <boost/throw_exception.hpp>
#include <exception>
#include <iostream>


#define DA_THROW_0() \
  throw (::DA::exception() \
    << ::boost::throw_function(BOOST_CURRENT_FUNCTION) \
    << ::boost::throw_file(__FILE__) << ::boost::throw_line(__LINE__))

#define DA_THROW_1(x) \
  throw (::DA::exception() << ::DA::exception_tag::throw_msg(x) \
    << ::boost::throw_function(BOOST_CURRENT_FUNCTION) \
    << ::boost::throw_file(__FILE__) << ::boost::throw_line(__LINE__))

#define DA_THROW_3(name, type, x) \
  namespace DA\
  {\
    namespace exception_tag \
    {\
      struct name;\
    }\
  }\
  throw ::DA::exception() \
    << ::boost::error_info<DA::exception_tag::##name, type>(x) \
    << ::boost::throw_function(BOOST_CURRENT_FUNCTION) \
    << ::boost::throw_file(__FILE__) << ::boost::throw_line(__LINE__)

#define DA_CATCH \
  catch(const ::DA::exception &e)\
  {\
    ::std::cerr << *::boost::get_error_info< ::boost::throw_file>(e) \
    << "(" << *::boost::get_error_info< ::boost::throw_line>(e) \
    << "): Throw in function " \
    << *::boost::get_error_info< ::boost::throw_function>(e) << ::std::endl;\
    e << ::boost::throw_function(BOOST_CURRENT_FUNCTION) \
    << ::boost::throw_file(__FILE__) << ::boost::throw_line(__LINE__); \
    throw;\
  }\
  catch(const ::std::exception &e)\
  {\
    DA_THROW_1(e.what());\
  }\
  catch(...)\
  {\
    DA_THROW_0();\
  }
#define DA_CATCH_STH(x) \
  catch(const ::DA::exception &e)\
  {\
    ::std::cerr << *::boost::get_error_info< ::boost::throw_file>(e) \
    << "(" << *::boost::get_error_info< ::boost::throw_line>(e) \
    << "): Throw in function " \
    << *::boost::get_error_info< ::boost::throw_function>(e) << ::std::endl; \
    x; \
    e << ::boost::throw_function(BOOST_CURRENT_FUNCTION) \
    << ::boost::throw_file(__FILE__) << ::boost::throw_line(__LINE__); \
    throw;\
  }\
  catch(const ::std::exception &e)\
  {\
    DA_THROW_1(e.what());\
  }\
  catch(...)\
  {\
    DA_THROW_0();\
  }

#define DA_MAIN_CATCH \
	catch(const ::DA::exception &e)\
	{\
		::std::cerr << ::boost::diagnostic_information(e) << ::std::endl;\
	}\
	catch(const ::std::exception &e)\
	{\
		::std::cerr << e.what() << ::std::endl;\
	}\
	catch(...)\
	{\
		::std::cerr << "error" << ::std::endl;\
	}
#define DA_MAIN_CATCH_ENDFUN(endfun) \
	catch(const ::DA::exception &e)\
	{\
		::std::cerr << ::boost::diagnostic_information(e) << ::std::endl;\
		endfun;\
	}\
	catch(const ::std::exception &e)\
	{\
		::std::cerr << e.what() << ::std::endl;\
		endfun;\
	}\
	catch(...)\
	{\
		::std::cerr << "error" << ::std::endl;\
		endfun;\
	}

#define DA_THROW_EXCEPTION_0 DA_THROW_0
#define DA_THROW_EXCEPTION_1 DA_THROW_1
#define DA_THROW_EXCEPTION_3 DA_THROW_3
#define DA_CATCH_EXCEPTION DA_CATCH
#define DA_MAIN_CATCH_EXCEPTION DA_MAIN_CATCH
#define DA_MAIN_CATCH_EXCEPTION_ENDFUN DA_MAIN_CATCH_ENDFUN

#ifdef DA_EXCEPTION
  #define THROW_0 DA_THROW_0
  #define THROW_1 DA_THROW_1
  #define THROW_3 DA_THROW_3
  #define CATCH DA_CATCH
  #define MAIN_CATCH DA_MAIN_CATCH
  #define MAIN_CATCH_ENDFUN DA_MAIN_CATCH_ENDFUN
#endif

namespace DA
{
struct exception :
  virtual ::std::exception,
  virtual ::boost::exception
{};

namespace exception_tag
{
struct msg;
using throw_msg = ::boost::error_info<::DA::exception_tag::msg, ::std::string>;
} // namespace exception_tag

} // namespace DA

#endif // DA_EXCEPTION_HPP
