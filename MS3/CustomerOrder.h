// A class for managing and processing customer orders
// CustomerOrder.h
// Anthony Slater 158100172
// aslater1@myseneca.ca 
// 2019/07/19

#ifndef SICT_CUSTOMER_ORDER
#define SICT_CUSTOMER_ORDER

#include "ItemSet.h"

namespace sict {

	class CustomerOrder {
			std::string customer;
			std::string product;
			int item_total;
			struct ItemInfo {
				std::string item_name;
				unsigned int serial_number;
				bool filled;
				ItemInfo() : item_name(""), serial_number(0), filled(false) {}
			} *item;
			//ItemInfo* item;
			//Utilities util;
		public:
			CustomerOrder();
			CustomerOrder(const std::string);
			CustomerOrder(const CustomerOrder&) = delete;
			CustomerOrder(CustomerOrder&&);
			CustomerOrder& operator=(const CustomerOrder&) = delete;	
			CustomerOrder& operator=(CustomerOrder&&);
			~CustomerOrder();
			void fillItem(ItemSet&, std::ostream&);
			bool isFilled() const;
			bool isItemFilled(const std::string&) const;
			std::string getNameProduct() const;
			void display(std::ostream&, bool = false) const;
	};

} // sict 

#endif