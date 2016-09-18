#ifndef _CUSTOMER_H
#define _CUSTOMER_H 2016

#include <string>

class Customer {
    public:
        Customer(std::string customer_name, std::string customer_phone);
        std::string get_customer_name() const;
        std::string get_customer_phone() const;
    private:
        const std::string kCustomerName;
        const std::string kCustomerPhone;
};

#endif
