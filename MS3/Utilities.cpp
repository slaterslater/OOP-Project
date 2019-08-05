#include "Utilities.h"

namespace sict {
	
	char Utilities::delimiter = '\0';

	size_t Utilities::field_width = 0;

	Utilities::Utilities() {}

	const std::string Utilities::extractToken(const std::string& str, size_t next_pos) {
		size_t stop_pos = str.find(delimiter, next_pos+1);
		if (stop_pos == next_pos)
			throw std::string("one delimiter follows another");
		std::string extraction = str.substr(next_pos, stop_pos-next_pos);
		return extraction;
		/*std::string tempStr;
		size_t positionOfDelim = str.find(getDelimiter(), next_pos);

		tempStr = str.substr(next_pos, (positionOfDelim - next_pos));

		if (tempStr.length() > field_width)
		{
			setFieldWidth(tempStr.length());
		}

		if ((str.at(positionOfDelim + 1) != '\0') && (str.at(positionOfDelim + 1) != getDelimiter()) && (positionOfDelim != std::string::npos))
		{
			next_pos = positionOfDelim + 1;
		}
		else if (str.at(positionOfDelim + 1) == getDelimiter())
		{
			throw("delims are too close to one another!");
		}
		else
		{
			next_pos = std::string::npos;
		}

		return tempStr;
		*/
	}

	const char Utilities::getDelimiter() const { return delimiter; }

	size_t Utilities::getFieldWidth() const {	return field_width; }

	void Utilities::setDelimiter(const char d) { delimiter = d; }

	void Utilities::setFieldWidth(size_t fw) { field_width = fw; }

} // sict