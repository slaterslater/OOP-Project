// 
// 
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/08/04

#include "LineManager.h"

namespace sict {

	LineManager::LineManager(std::vector<Station*>& station_address, std::vector<size_t>& station_connection, std::vector<CustomerOrder>& cust_order, size_t station_start, std::ostream& os) {
	
	}

	void LineManager::display(std::ostream& os) const {
		os << "LineManager display" << std::endl;
	}

	bool LineManager::run(std::ostream& os) {
		os << "LineManager Run" << std::endl;
	}

} // sict