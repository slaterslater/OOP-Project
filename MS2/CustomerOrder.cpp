// A class for managing and processing customer orders
// CustomerOrder.h
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/07/19

#include <algorithm>
#include <iomanip>
#include <iostream>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sict {

	CustomerOrder::CustomerOrder() : customer(""), product(""), item_total(0), item(nullptr) {}

	CustomerOrder::CustomerOrder(const std::string str) {
		Utilities util;
		item_total = std::count(str.begin(), str.end(), util.getDelimiter()) - 1;
		item = new ItemInfo[item_total];
		customer = util.extractToken(str, 0);
		if (customer.length() > util.getFieldWidth())
			util.setFieldWidth(customer.length() + 1);
		size_t next_pos = str.find(util.getDelimiter()) + 1;
		product = util.extractToken(str, next_pos);;
		for (int i = 0; i < item_total; i++) {
			next_pos = str.find(util.getDelimiter(), next_pos + 1) + 1;
			item[i].item_name = util.extractToken(str, next_pos);
		}
	}
	
	CustomerOrder::CustomerOrder(CustomerOrder&& order) {
		*this = std::move(order);
	}
	
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) {
		if (this != &order) {
			customer = order.customer;
			product = order.product;
			item = order.item;
			item_total = order.item_total;
			order.item_total = 0;
			order.item = nullptr;
			order.customer = "";
			order.product = "";
		}
		return *this;
	}
	

	CustomerOrder::~CustomerOrder() {
		if (item)
			delete[] item;
	}
	
	void CustomerOrder::fillItem(ItemSet& itemset, std::ostream& os) {
		std::string action, reason="";
		for (int i = 0; i < item_total; i++) {
			if (item[i].item_name == itemset.getName()) {
				if (item[i].filled) {
					action = " Unable to fill ";
					reason = " already filled";
				}
				else if (itemset.getQuantity() == 0) {
					item[i].serial_number = itemset.getSerialNumber();
					action = " Unable to fill ";
					reason = " out of stock";
				}
				else {
					item[i].serial_number = itemset.getSerialNumber();
					item[i].filled = true;
					--itemset;
					action = " Filled ";
				}
				os << action << customer << " [" << product << "][" << item[i].item_name << "][" << item[i].serial_number << "]" << reason << std::endl;
			}
		}
	}
	
	bool CustomerOrder::isFilled() const {
		for (int i = 0; i < item_total; i++) {
			if (!item[i].filled)
				return false;
		}
		return true;
	}
	
	bool CustomerOrder::isItemFilled(const std::string& name_of_item) const {
		for (int i = 0; i < item_total; i++) {
			if (item[i].item_name == name_of_item && !item[i].filled)
				return false;
		}
		return true;
	}
	
	std::string CustomerOrder::getNameProduct() const {
		return std::string(customer + " [" + product + "]");
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		Utilities util;
		if (showDetail) {
			os << std::setw(util.getFieldWidth()) << std::left << customer << "[" << product << "]" << std::endl;
			for (int i = 0; i < item_total; i++) {
				os << "[" << item[i].serial_number << "]" << item[i].item_name << "-" << item[i].filled << std::endl;
			}
		}
		else {
			os << std::setw(util.getFieldWidth()) << std::left << customer << "[" << product << "]" << std::endl;
			for (int i = 0; i < item_total; i++) {
				os << std::setw(util.getFieldWidth()) << " " << item[i].item_name << std::endl;
			}
		}
	}

} // sict