#include "span.hpp"

int main() {
	try {
		Span	span(7);

		span.addNumber(2);
		span.addNumber(3);
		span.addNumber(21);
		span.addNumber(8);
		span.addNumber(13);
		span.addNumber(5);
		std::cout << "shortest : " << span.shortestSpan() << std::endl;
		std::cout << "longest : " << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}