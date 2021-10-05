#include <exception>
#include <string>

//class MyException : public std::exception {
//	const char* file;
//    int line;
//    const char* func;
//    const char* info;
    
//    public:
//    	MyException(const char* msg, const char* file_, int line_, const char* func_, const char* info_ = "") : std::exception(msg),
//        	file (file_),
//        	line (line_),
//        	func (func_),
//        	info (info_)
//        {
//        }
//        const char* get_file() const { return file; }
//        int get_line() const { return line; }
//		const char* get_func() const { return func; }
//        const char* get_info() const { return info; }       
//};


class Except: virtual public std::exception {
    
protected:
    int			_num;               
    int 		_offset;               
    std::string _msg;
    
public:
    explicit Except(const std::string& msg, int num, int offset) :
	_msg(msg), _num(num), _offset(offset) {}

    virtual ~Except() throw () {}

    virtual const char* what() const throw () {
       return _msg.c_str();
    }
    
    virtual int getErrorNumber() const throw() {
        return _num;
    }

    virtual int getErrorOffset() const throw() {
        return _offset;
    }
};