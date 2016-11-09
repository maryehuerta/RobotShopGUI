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

#include "head.h"
#include "../../Dropbox/P5/arm.h"
#include "locomotor.h"
#include "battery.h"
#include "torso.h"
#include "model.h"
#include "customer.h"
#include "sa.h"
#include "order.h"
#include "shop.h"
#include <iostream>
#include <iomanip>

using namespace std;

void label(string uut) {
  cout << "############ " 
       << uut 
       << " ############" 
       << endl;
}

int main() {
  //
  // Test Head construction
  //
  label("Head");
  Head head{"Basic Head", "4323", 3.14, 415.30, "A basic robot head"};

  cout << head << endl;

  //
  // Test Arm construction and power calculation
  //
  label("Arm");
  Arm arm{"Basic Arm", "276", 1.15, 215.11, 500, "A basic robot arm"};

  cout << arm << endl;

  cout << "50% power level is " << arm.power(50) << endl;

  if (arm.power(50) != 250)
      cerr << "Arm power calc failed: expected 250, got " << arm.power(50) << endl;

  //
  // Test Locomotor construction and power calculation
  //
  label("Locomotor");
  Locomotor locomotor{"Basic Locomotor", "562666867", 11.2, 825.25, 2500, 25, "A basic robot locomotor"};

  cout << locomotor << endl;

  cout << "At 10 mph power level is " << locomotor.power(10) << endl;

  if (locomotor.power(10) != 1000)
      cerr << "Locomotor power calc failed: expected 1000, got " << locomotor.power(10) << endl;

  //
  // Test Battery construction
  //
  label("Battery");
  Battery battery{"Basic Battery", "2288379", 21.9, 613.81, 8, "A basic robot battery"};

  cout << battery << endl;

  //
  // Test Torso construction
  //
  label("Torso");
  Torso torso{"Basic Torso", "86776", 17.4, 109.37, 2, "A basic robot torso"};

  cout << torso << endl;

  //
  // Test Robot Model definition
  //
  label("Robot Model");
  Robot_model robbie{"Robbie the Robot", "RB 101", 5000, torso, head, arm, arm,
     locomotor, battery, battery, battery};

  cout << robbie << endl;

  // 
  // Test Customer definition
  //
  label("Customer");
  Customer customer{"Professor Rice", "1"};

  cout << customer << endl;

  // 
  // Test Sales Associate definition
  //
  label("Sales Associate");
  Sales_associate sales_associate{"Floyd", "31415926"};

  cout << sales_associate << endl;

  // 
  // Test Order definition
  //
  label("Order");
  Order order{"GFR1", "2016-10-22", robbie, customer, sales_associate};

  cout << order << endl;

  //
  // Test Shop definition
  //
  label("Shop");
  Shop shop{"Robbie Robot Shop"};

  shop.create_torso("Basic Torso", "86776", 17.4, 109.37, 2, "A basic robot torso");
  shop.create_torso("Large Torso", "586776", 18.7, 189.95, 3, "A basic robot torso");

  shop.create_head("Basic Head", "4323", 3.14, 415.30, "A basic robot head");

  shop.create_arm("Basic Arm", "276", 1.15, 215.11, 500, "A basic robot arm");
  shop.create_arm("Fancy Arm", "3276", 1.35, 435.11, 500, "A fancy robot arm");
  shop.create_arm("Premium Arm", "7276", 1.75, 750.00, 500, "Robot arm de la superb");

  shop.create_locomotor("Basic Locomotor", "562666867", 11.2, 825.25, 2500, 25, "A basic robot locomotor");
  shop.create_locomotor("Strong Locomotor", "7562666867", 13.3, 1093.75, 3500, 20, "A strong robot locomotor");
  shop.create_locomotor("Fast Locomotor", "7562666867", 10.1, 1499.99, 2900, 40, "A fast robot locomotor");

  shop.create_battery("Basic Battery", "2288379", 21.9, 613.81, 8, "A basic robot battery");

  shop.create_model("Speedy Samuel", "726835", 15995.00, shop.torsos()[0], shop.heads()[0],
       shop.arms()[0], shop.arms()[2], shop.locomotors()[2], 
       shop.batteries()[0], shop.batteries()[0], shop.batteries()[0]);

  shop.create_customer("Professor Rice", "1");
  shop.create_sales_associate("Floyd", "31415926");

  shop.create_order("GFR1", "2016-10-22", shop.models()[0], 
                    shop.customers()[0], shop.sales_associates()[0]);

  cout << shop << endl;
}
