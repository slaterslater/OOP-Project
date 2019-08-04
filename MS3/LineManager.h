// processes customer orders across the entire assembly line
// LineManager.h
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/08/04

#ifndef SICT_LINE_MANAGER_H
#define SICT_LINE_MANAGER_H

#include <vector>
#include "Station.h"

namespace sict {

	class LineManager {

		public:
			LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
			void display(std::ostream&) const;
			bool run(std::ostream&);
	};

} // sict

#endif