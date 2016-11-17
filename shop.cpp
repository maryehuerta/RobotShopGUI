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

#include "shop.h"
#include <iostream>
#include <iomanip>
#include <string>
 
//
// Robot parts management
//
void Shop::create_arm(string name, string part_number, double weight,
           double cost, int max_power_consumed, string description) {
    _arms.push_back(Arm{name, part_number, weight, 
           cost, max_power_consumed, description});
}
vector<Arm> Shop::arms() const {return _arms;}

void Shop::create_battery(string name, string part_number, double weight,
           double cost, int max_energy_stored, string description) {
    _batteries.push_back(Battery{name, part_number, weight, 
           cost, max_energy_stored, description});
}
vector<Battery> Shop::batteries() const {return _batteries;}

void Shop::create_head(string name, string part_number, double weight,
           double cost, string description) {
    _heads.push_back(Head{name, part_number, weight, 
           cost, description});
}
vector<Head> Shop::heads() const {return _heads;}

void Shop::create_locomotor(string name, string part_number, double weight,
           double cost, int max_power_consumed, int max_speed_possible, string description) {
    _locomotors.push_back(Locomotor{name, part_number, weight, 
           cost, max_power_consumed, max_speed_possible, description});
}
vector<Locomotor> Shop::locomotors() const {return _locomotors;}

void Shop::create_torso(string name, string part_number, double weight,
           double cost, int max_battery_slots, string description) {
    _torsos.push_back(Torso{name, part_number, weight, 
           cost, max_battery_slots, description});
}
vector<Torso> Shop::torsos() const {return _torsos;}

//
// Robot model management
//
void Shop::create_model(string name, string part_number, double price,
            int torso, int head, int arm1, int arm2, int locomotor,
            int battery1, int battery2, int battery3) {
    _models.push_back(Robot_model{name, part_number, price,
            torso, head, arm1, arm2, locomotor,
            battery1, battery2, battery3});
}
vector<Robot_model> Shop::models() const {return _models;}

//
// People management
//
void Shop::create_customer(string name, string customer_number) {
    _customers.push_back(Customer{name, customer_number});
}
vector<Customer> Shop::customers() const {return _customers;}

void Shop::create_sales_associate(string name, string employee_number) {
    _sales_associates.push_back(Sales_associate{name, employee_number});
}
vector<Sales_associate> Shop::sales_associates() const {return _sales_associates;}

//
// Order management
//
void Shop::create_order(string order_number, string date_of_sale,
            Robot_model& model, Customer& customer, Sales_associate& sales_associate) {
    _orders.push_back(Order{order_number, date_of_sale,
            model, customer, sales_associate});
}
vector<Order> Shop::orders() const {return _orders;}

//
// Shop management
//
string Shop::name() const {return _name;}
string Shop::to_string() const {return _name;}  // returns short text of a robot shop
ostream& operator<<(ostream& os, const Shop& shop) {
  os << fixed << setprecision(2) << endl
     << "================================" << endl
     << shop.name() << endl
     << "================================" << endl;
  os << "Parts" << endl
     << "--------------------------------" << endl;
  for (Arm a: shop.arms()) os << a << endl;
  for (Battery b: shop.batteries()) os << b << endl;
  for (Head h: shop.heads()) os << h << endl;
  for (Locomotor l: shop.locomotors()) os << l << endl;
  for (Torso t: shop.torsos()) os << t << endl;
  os << "--------------------------------" << endl
     << "Robot Models" << endl
     << "--------------------------------" << endl;
  for (Robot_model r: shop.models()) os << r << endl;
  os << "--------------------------------" << endl
     << "Customers" << endl
     << "--------------------------------" << endl;
  for (Customer c: shop.customers()) os << c << endl;
  os << "--------------------------------" << endl
     << "Sales Associates" << endl
     << "--------------------------------" << endl;
  for (Sales_associate s: shop.sales_associates()) os << s << endl;
  os << "--------------------------------" << endl
     << "Orders" << endl
     << "--------------------------------" << endl;
  for (Order o: shop.orders()) os << o << endl;
  return os; 
}

