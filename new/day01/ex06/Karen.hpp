#pragma once

#include <string>

class Karen {
	private:
		void info( void );
		void debug( void );
		void error( void );
		void undef ( void );
		void warning( void );
		int  getLevelIndex(std::string level);
	
		std::string levels[4];
		void (Karen::*func[4])(void);

	public:
		Karen();
		~Karen();
		void complain( std::string level );
};
