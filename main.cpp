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

#include "controller.h"
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
#include <iostream>

using namespace std;

//
// Declarations (we'll define later, just need to declare some variables!)
//
void create_robot_partCB(Fl_Widget* w, void* p);
void cancel_robot_partCB(Fl_Widget* w, void* p);
class Robot_Part_Dialog;

//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg; // The dialog of interest!

//
// Robot Part dialog
//

class Robot_Part_Dialog {
public:
    Robot_Part_Dialog() {
        dialog = new Fl_Window(340, 270, "Robot Part");

        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);

        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);

        rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
        rp_type->align(FL_ALIGN_LEFT);

        rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);

        rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);

        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);

        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB, 0);

        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string part_number() {return rp_part_number->value();}
    string type() {return rp_type->value();}
    string weight() {return rp_weight->value();}
    string cost() {return rp_cost->value();}
    string description() {return rp_description->value();}

private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_type;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

//
// Callbacks
//

void CB(Fl_Widget* w, void* p) { } // No action

void menu_create_robot_partCB(Fl_Widget* w, void* p) {
    robot_part_dlg->show();
}

void create_robot_partCB(Fl_Widget* w, void* p) { // Replace with call to model!
    cout << "### Creating robot part" << endl;
    cout << "Name    : " << robot_part_dlg->name() << endl;
    cout << "Part #  : " << robot_part_dlg->part_number() << endl;
    cout << "Type    : " << robot_part_dlg->type() << endl;
    cout << "Weight  : " << robot_part_dlg->weight() << endl;
    cout << "Cost    : " << robot_part_dlg->cost() << endl;
    cout << "Descript: " << robot_part_dlg->description() << endl;
    if ( robot_part_dlg->type().compare("arm") == 0)
    {
        
    }
    robot_part_dlg->hide();

}

void cancel_robot_partCB(Fl_Widget* w, void* p) {
    robot_part_dlg->hide();
}

//
// Menu
//

Fl_Menu_Item menuitems[] = {
        { "&File", 0, 0, 0, FL_SUBMENU },
        { "&New", FL_ALT + 'n', (Fl_Callback *)CB },
        { "&Open", FL_ALT + 'o', (Fl_Callback *)CB },
        { "&Save", FL_ALT + 's', (Fl_Callback *)CB },
        { "Save As", FL_ALT + 'S', (Fl_Callback *)CB },
        { "&Quit", FL_ALT + 'q', (Fl_Callback *)CB },
        { 0 },
        { "&Edit", 0, 0, 0, FL_SUBMENU },
        { "&Undo", 0, (Fl_Callback *)CB },
        { "Cu&t", 0, (Fl_Callback *)CB },
        { "&Copy", 0, (Fl_Callback *)CB },
        { "&Paste", 0, (Fl_Callback *)CB },
        { 0 },
        { "&Create", 0, 0, 0, FL_SUBMENU },
        { "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
        { "Customer", 0, (Fl_Callback *)CB },
        { "Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
        { "Robot Part", 0, (Fl_Callback *)menu_create_robot_partCB },
        { "Robot Model", 0, (Fl_Callback *)CB },
        { 0 },
        { "&Report", 0, 0, 0, FL_SUBMENU },
        { "Invoice", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
        { "All Orders", 0, (Fl_Callback *)CB },
        { "Orders by Customer", 0, (Fl_Callback *)CB },
        { "Orders by Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
        { "All Customers", 0, (Fl_Callback *)CB },
        { "All Sales Associates", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
        { "All Robot Models", 0, (Fl_Callback *)CB },
        { "All Robot Parts", 0, (Fl_Callback *)CB },
        { 0 },
        { "&Help", 0, 0, 0, FL_SUBMENU },
        { "&Manual", 0, (Fl_Callback *)CB},
        { "&About", 0, (Fl_Callback *)CB},
        { 0 },
        { 0 }
};


int main() {
  Shop shop{"Robbie Robot Shop"};
  Controller controller(shop);
  controller.cli();

    const int X = 660;
    const int Y = 320;

    // Create dialogs
    robot_part_dlg = new Robot_Part_Dialog{};

    // Create a window
    win = new Fl_Window{X, Y, "Robbie Robot Shop Manager"};
    win->color(FL_WHITE);

    // Install menu bar
    menubar = new Fl_Menu_Bar(0, 0, X, 30);
    menubar->menu(menuitems);

    // Wrap it up and let FLTK do its thing
    win->end();
    win->show();
    return(Fl::run());



}
