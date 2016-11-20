#ifndef __CONTROLLER_H
#define __CONTROLLER_H 201610
 
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
#include "arm.h"
#include "locomotor.h"
#include "battery.h"
#include "torso.h"
#include "model.h"
#include "customer.h"
#include "sa.h"
#include "order.h"
#include "shop.h"

#include "FL/Fl.h"
#include "FL/Fl_Window.H"
#include "FL/fl_Box.H"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

using namespace std;

class Controller {
  public:
    Controller (Shop& p_shop) : shop{p_shop} { }

    const static int MENU_LIST_ORDERS      =  1;
    const static int MENU_CREATE_ORDER     =  2;
    const static int MENU_LIST_PEOPLE      = 11;
    const static int MENU_CREATE_CUSTOMER  = 12;
    const static int MENU_CREATE_SA        = 13;

    const static int MENU_LIST_MODELS      = 21;
    const static int MENU_CREATE_MODEL     = 22;

    const static int MENU_LIST_PARTS       = 31;
    const static int MENU_CREATE_TORSO     = 32;
    const static int MENU_CREATE_ARM       = 33;
    const static int MENU_CREATE_HEAD      = 34;
    const static int MENU_CREATE_LOCOMOTOR = 35;
    const static int MENU_CREATE_BATTERY   = 36;

    const static int MENU_SHOW_MENU        = 98;
    const static int MENU_EXIT             = 99;

    //
    ///
    /// GUI
    ///

    /*shop.create_arm(robot_part_dlg->name(), robot_part_dlg->part_number(), robot_part_dlg->weight(),
                        robot_part_dlg->cost(), 100,  robot_part_dlg->description()) ;*/
    int get_int(string prompt);
    double get_double(string prompt);
    char* get_charstar(string s);
    double get_total_parts_cost(int torso_num, int head_num, int arm1_num, int arm2_num, int locomotor_num,
                                            int bat1_num, int bat2_num, int bat3_num);

        /*
        void main_menu();



        string get_string(string prompt);
        int get_int(string prompt);
        double get_double(string prompt);

        Customer& get_customer(string prompt);
        Sales_associate& get_sa(string prompt);
        Robot_model& get_model(string prompt);
        Torso& get_torso(string prompt);
        Arm& get_arm(string prompt);
        Head& get_head(string prompt);
        Locomotor& get_locomotor(string prompt);
        Battery& get_battery(string prompt);

        void cli();
        void execute_cmd(int cmd);
        */


  private:
    Shop& shop;
};
#endif
