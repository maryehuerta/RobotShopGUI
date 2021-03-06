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

#include "model.h"
#include <iostream>
#include <iomanip>
#include <string>
 
string Robot_model::name() const {return _name;}
string Robot_model::part_number() const {return _part_number;}
double Robot_model::price() const {return _price;}
int Robot_model::torso() const {return _torso;}
int Robot_model::head() const {return _head;}
int Robot_model::arm1() const {return _arm1;}
int Robot_model::arm2() const {return _arm2;}
int Robot_model::locomotor() const {return _locomotor;}
int Robot_model::battery1() const {return _battery1;}
int Robot_model::battery2() const {return _battery2;}
int Robot_model::battery3() const {return _battery3;}



string Robot_model::to_string() const {return _name + " (PN " + _part_number + ")";}

ostream& operator<<(ostream& os, const Robot_model& model) {
  return os << fixed << setprecision(2)
            << model.name() << " (" << " PN " << model.part_number() 
             << " price $" << model.price() << ")" ;
}

