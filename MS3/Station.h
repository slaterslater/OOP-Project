// class for managing a set of identical items and processing a queue of customer orders
// Station.h
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/08/04

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <queue>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {

	class Station {
			ItemSet item;
			//std::string station_name;
			std::queue<CustomerOrder> request;
		public:
			Station(const std::string);
			Station(const Station&) = delete;
			Station(Station&&) = delete;
			Station& operator=(const Station&) = delete;
			Station& operator=(Station&&) = delete;
			void display(std::ostream&) const;
			void fill(std::ostream&);
			const std::string& getName() const;
			bool hasAnOrderToRelease() const;
			Station& operator--();
			Station& operator+=(CustomerOrder&&);
			bool pop(CustomerOrder&);
			void validate(std::ostream&) const;
	};

} // sict

#endif