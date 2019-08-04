// A class for extracting tokens from a string as well as common system functions 
// Utilities.h
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/07/10

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <string>

namespace sict {

	class Utilities {
			static char delimiter;
			static size_t field_width;
		public:
			Utilities();
			const std::string extractToken(const std::string&, size_t);
			const char getDelimiter() const;
			size_t getFieldWidth() const;
			static void setDelimiter(const char d);
			void setFieldWidth(size_t);
	};

} // sict

#endif