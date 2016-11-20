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

#include "order.h"
#include <iostream>
#include <iomanip>
#include <string>
 
string Order::order_number() const {return _order_number;}
string Order::date_of_sale() const {return _date_of_sale;}
int Order::model() const {return _model;}
int Order::customer() const {return _customer;}
int  Order::sales_associate() const {return _sales_associate;}
//double Order::subtotal() const {return _model.price();}
//double Order::sales_tax() const {return _model.price()*sales_tax_rate;}
//double Order::total_price() const {return _model.price()*(1+sales_tax_rate) + shipping;}


//string Order::to_string() const {return _order_number+ " (" + _model.name() + " for "
//                                      + _customer.name() + " by " + _sales_associate.name() + ")";}

ostream& operator<<(ostream& os, const Order& order) {
  return os << fixed << setprecision(2)
            << order.order_number() << " placed on date " << order.date_of_sale() /*<< " Price: $" << order.total_price()
            << " (subtotal $" << order.subtotal() << " +  sales tax $" << order.sales_tax()*/
            ;

}

