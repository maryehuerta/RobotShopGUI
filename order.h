#ifndef __ORDER_H
#define __ORDER_H 2016

/*
    Robbie Robot Shop v1.0 beta, (c) 2016 by Professor George F. Rice.

    This file is part of Robbie Robot Shop (RRS), an example solution
    to Project #5 for UTA CSE 1325. 

    Permission is expressly DENIED to students in this class to include
    ANY of this code in a submitted Homework #5 solution during any semester 
    of this class. This restriction supercedes the license granted below,
    and use of this code for Homework #5 will be deemed an Honor Code Violation 
    regardless of disclosure.
    
    Permission is expressly GRANTED to students in this class to include
    this code, or any derivatives thereof, in Project #6 of the same class,
    providing that this header is not removed.
    
    RRS is otherwise free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    RRS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with RRS.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string>
#include "model.h"
#include "customer.h"
#include "sa.h"
 
using namespace std;

class Order {
    public:
        Order(string order_number, string date_of_sale, 
                    Robot_model& model, Customer& customer, Sales_associate& sales_associate)
            : _order_number{order_number}, _date_of_sale{date_of_sale},
              _model{model}, _customer{customer}, _sales_associate{sales_associate} { }
              
        constexpr static double sales_tax_rate = 0.0825;
        constexpr static double shipping = 100.0;

        string order_number() const;
        string date_of_sale() const;
        Robot_model& model() const;
        Customer& customer() const;
        Sales_associate& sales_associate() const;
        double subtotal() const;
        double sales_tax() const;
        double total_price() const;

        string to_string() const;  // returns short text of a robot model
        friend ostream& operator<<(ostream& os, const Order& model);
    protected:
        string _order_number;
        string _date_of_sale;
        Robot_model& _model; 
        Customer& _customer;
        Sales_associate& _sales_associate;
};
#endif
