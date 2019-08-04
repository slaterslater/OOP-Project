#include "Utilities.h"

namespace sict {
	
	char Utilities::delimiter = '\0';

	size_t Utilities::field_width = 0;

	Utilities::Utilities() {}

	const std::string Utilities::extractToken(const std::string& str, size_t next_pos) {
		size_t stop_pos = str.find(delimiter, next_pos+1);
		std::string extraction = str.substr(next_pos, stop_pos-next_pos);
		// throw exception if one delimiter follows another
		return extraction;
	}

	const char Utilities::getDelimiter() const { return delimiter; }

	size_t Utilities::getFieldWidth() const {	return field_width; }

	void Utilities::setDelimiter(const char d) { delimiter = d; }

	void Utilities::setFieldWidth(size_t fw) { field_width = fw; }

} // sict