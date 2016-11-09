#ifndef __SHOP_H
#define __SHOP_H 2016

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
#include <vector>
#include <iostream>
#include "../../Dropbox/P5/arm.h"
#include "battery.h"
#include "head.h"
#include "locomotor.h"
#include "torso.h"
#include "model.h"
#include "customer.h"
#include "sa.h"
#include "order.h"
 
using namespace std;

class Shop {
    public:
        Shop(string name) : _name{name} { }
              
        //
        // Robot parts management
        //
        void create_arm(string name, string part_number, double weight,
                   double cost, int max_power_consumed, string description);
        vector<Arm> arms() const; 
        void create_battery(string name, string part_number, double weight,
                   double cost, int max_energy_stored, string description);
        vector<Battery> batteries() const;
        void create_head(string name, string part_number, double weight,
                   double cost, string description);
        vector<Head> heads() const;
        void create_locomotor(string name, string part_number, double weight,
                   double cost, int max_power_consumed, int max_speed_possible, string description);
        vector<Locomotor> locomotors() const;
        void create_torso(string name, string part_number, double weight,
                   double cost, int max_battery_slots, string description);
        vector<Torso> torsos() const;

        //
        // Robot model management
        //
        void create_model(string name, string part_number, double price,
                    Torso& torso, Head& head, Arm& arm1, Arm& arm2, Locomotor& locomotor,
                    Battery& battery1, Battery& battery2, Battery& battery3);
        vector<Robot_model> models() const;

        //
        // People management
        //
        void create_customer(string name, string customer_number);
        vector<Customer> customers() const;
        void create_sales_associate(string name, string employee_number);
        vector<Sales_associate> sales_associates() const;

        //
        // Order management
        //
        void create_order(string order_number, string date_of_sale,
                    Robot_model& model, Customer& customer, Sales_associate& sales_associate);
        vector<Order> orders() const;

        //
        // Shop management
        //
        string name() const;
        string to_string() const;  // returns short text of a robot shop
        friend ostream& operator<<(ostream& os, const Shop& shop);

        //
        // Reports
        //
    protected:
        string _name;
        vector<Arm> _arms;
        vector<Battery> _batteries;
        vector<Head> _heads;
        vector<Locomotor> _locomotors;
        vector<Torso> _torsos;

        vector<Robot_model> _models;
        vector<Customer> _customers;
        vector<Sales_associate> _sales_associates;
        vector<Order> _orders;

};
#endif
