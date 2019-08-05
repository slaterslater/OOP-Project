// 
// 
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/08/04

#include "LineManager.h"

namespace sict {

	// 5-arg constructor receives station addresses & connections, customer orders, starting station and ostream obj 
	LineManager::LineManager(std::vector<Station*>& station_address, std::vector<size_t>& station_connection, std::vector<CustomerOrder>& cust_order, size_t station_start, std::ostream& os) {
	
	}

	// display completed and incomplete orders
	void LineManager::display(std::ostream& os) const {
		os << "LineManager display" << std::endl;
	}

	// fills the customer order at each station if requested
	// if order to be released 
	// returns true if all orders processed
	bool LineManager::run(std::ostream& os) {
		os << "LineManager Run" << std::endl;
		return true;
	}

} // sict