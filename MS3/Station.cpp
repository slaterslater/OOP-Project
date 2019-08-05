// 
// 
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/08/04

#include "Station.h"

namespace sict {

	// 1-arg constructor passes const string ref to ItemSet subobj
	Station::Station(const std::string str) : item(str) {
		//std::cout << item.getName() << std::endl;
		//station_name = item.getName();
	}

	// display data for ItemSet 
	void Station::display(std::ostream& os) const {
		item.display(os, true);
	}

	// fills last order in customer order queue. Does nothing if queue empty
	void Station::fill(std::ostream& os) {
		os << "Station fill" << std::endl;
	}

	// returns ref to name of ItemSet subobj
	const std::string& Station::getName() const {
		//return station_name;
		return item.getName();
		//return temp;
	}

	// returns true if front of queue has been filled, or if no items left
	bool Station::hasAnOrderToRelease() const {
		return false;
	}

	// decrease ItemSet, increase serial number of next item and return current obj ref
	Station& Station::operator--() {
		--item;
		return *this;
	}

	// moves ref order to back of queue and return current obj 
	Station& Station::operator+=(CustomerOrder&& order){
		request.push(std::move(order));
		return *this;
	}

	// remove front of queue and moves to calling func via parameter list. 
	// return true if station filled its part of order. Return false if not filled or queue empty
	bool Station::pop(CustomerOrder& ready) {
		return false;
	}

	// reports state of ItemSet
	void Station::validate(std::ostream& os) const {
		os << " getName(): " << getName() << std::endl;
		os << " getSerialNumber(): " << item.getSerialNumber() << std::endl;
		os << " getQuantity(): " << item.getQuantity() << std::endl;
	}

} // sict