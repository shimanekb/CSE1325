#include "customer.h"

Customer::Customer(std::string customer_name, std::string customer_phone)
    : kCustomerName(customer_name), kCustomerPhone(customer_phone) {};

Customer::Customer(const Customer& customer) 
    : kCustomerName(customer.get_customer_name()), 
    kCustomerPhone(customer.get_customer_phone()) {};
    
std::string Customer::get_customer_name() const {
    return kCustomerName;
}

std::string Customer::get_customer_phone() const {
    return kCustomerPhone;
}
