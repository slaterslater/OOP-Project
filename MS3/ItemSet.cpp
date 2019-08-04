#include <iomanip>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	ItemSet::ItemSet(const std::string str) {
		Utilities util;
		name = util.extractToken(str, 0);
		if (name.length() > util.getFieldWidth())
			util.setFieldWidth(name.length()+1);
		size_t next_pos = str.find(util.getDelimiter())+1;
		serial_number = std::stoul(util.extractToken(str, next_pos));
		next_pos = str.find(util.getDelimiter(), next_pos + 1)+1;
		quantity = std::stoul(util.extractToken(str, next_pos));
		next_pos = str.find(util.getDelimiter(), next_pos + 1)+1;
		description = util.extractToken(str, next_pos);
	}

	const std::string& ItemSet::getName() const { return name; }

	const unsigned int ItemSet::getSerialNumber() const { return serial_number; }

	const unsigned int ItemSet::getQuantity() const { return quantity; }

	ItemSet& ItemSet::operator--() {
		// should check quantity != 0
		--quantity;
		++serial_number;
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {		
		Utilities util;
		os << std::setw(util.getFieldWidth()) << std::left << name 
			<< "[" << std::setw(5) << std::setfill('0') << serial_number << std::setfill(' ') << "]";
		if (full) {
			os << " Quantity " << std::setw(3) << quantity << " Description: " << description; 
		os << std::endl;
		}
	}

} // sict