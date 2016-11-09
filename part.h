#ifndef __PART_H
#define __PART_H 2016

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
 
using namespace std;

class Robot_part {
    public:
        Robot_part(string name, string type, string part_number, double weight,
                   double cost, string description)
            : _name{name}, _type{type},  _part_number{part_number}, _weight{weight},
                   _cost{cost}, _description{description} { }
        string name() const;
        string part_number() const;
        string type() const;
        double weight() const;
        double cost() const;
        string description() const;
        string to_string() const;  // returns short text of a robot part
    protected:
        string _name;
        string _part_number;
        string _type;
        double _weight;
        double _cost;
        string _description;
};
#endif
