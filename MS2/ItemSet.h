// A class that manages the stock inventory of a particular item
// ItemSet.h
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/07/10

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include <iostream>


namespace sict {

	class ItemSet {
			std::string name;
			unsigned int serial_number;
			unsigned int quantity;
			std::string description;
			//Utilities util;
		public:
			ItemSet(const std::string);
			ItemSet& operator=(const ItemSet&) = delete;
			const std::string& getName() const;
			const unsigned int getSerialNumber() const;
			const unsigned int getQuantity() const;
			ItemSet& operator--();
			void display(std::ostream&, bool) const;
	};

} // sict

#endif