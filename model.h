#ifndef __MODEL_H
#define __MODEL_H 2016

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
#include "head.h"
#include "../../Dropbox/P5/arm.h"
#include "torso.h"
#include "locomotor.h"
#include "battery.h"
 
using namespace std;

class Robot_model {
    public:
        Robot_model(string name, string part_number, double price,
                    Torso& torso, Head& head, Arm& arm1, Arm& arm2, Locomotor& locomotor,
                    Battery& battery1, Battery& battery2, Battery& battery3)
            : _name{name}, _part_number{part_number}, _price{price},
              _torso{torso}, _head{head}, _arm1{arm1}, _arm2{arm2}, _locomotor{locomotor},
              _battery1{battery1}, _battery2{battery2}, _battery3{battery3} { }
        string name() const;
        string part_number() const;
        double price() const;
        Torso& torso() const;
        Head& head() const;
        Arm& arm1() const;
        Arm& arm2() const;
        Locomotor& locomotor() const;
        Battery& battery1() const;
        Battery& battery2() const;
        Battery& battery3() const;
        double parts_cost() const;
        string to_string() const;  // returns short text of a robot model
        friend ostream& operator<<(ostream& os, const Robot_model& model);
    protected:
        string _name;
        string _part_number;
        double _price;
        Torso& _torso; 
        Head& _head;
        Arm& _arm1;
        Arm& _arm2;
        Locomotor& _locomotor;
        Battery& _battery1;
        Battery& _battery2;
        Battery& _battery3;
};
#endif
