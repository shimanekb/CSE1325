#include "customer.h"

Customer::Customer(std::string customer_name, std::string customer_phone)
    : kCustomerName(customer_name), kCustomerPhone(customer_phone) {};

std::string Customer::get_customer_name() {
    return kCustomerName;
}

std::string Customer::get_customer_phone() {
    return kCustomerPhone;
}
