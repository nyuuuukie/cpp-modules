#include "whatever.hpp"

//class Awesome {

//public:
//	Awesome( int n ) : _n( n ) {}

//	bool operator> ( Awesome const & rhs ) const { return (this->_n > rhs._n);  }
//	bool operator< ( Awesome const & rhs ) const { return (this->_n < rhs._n);  }
//	bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
//	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
//	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
//	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }

//	int get_n(void) const { return this->_n; }

//	private:
//		int _n;
//};

//std::ostream &operator<<(std::ostream &o, const Awesome &a) {
//	o << a.get_n();
//	return o;
//}

int main( void ) {

	{
		int a = 2;
		int b = 3;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}

	{
		double a = 2;
		double b = 3;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	
	{
		std::string c = "cha";
		std::string d = "dza";

		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	//{
	//	Awesome a(5);
	//	Awesome b(9);

	//	std::cout << "a = " << a << ", b = " << b << std::endl;
	//	::swap(a, b);
	//	std::cout << "a = " << a << ", b = " << b << std::endl;
	//	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	//	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	//}

	return 0;
}
