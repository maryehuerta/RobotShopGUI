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
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_Browser.H>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
//#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>



using namespace std;


//
// Declarations
//
void create_robot_partCB(Fl_Widget* w, void* p);
void cancel_robot_partCB(Fl_Widget* w, void* p);
void create_robot_modelCB(Fl_Widget* w, void *p);
void cancel_robot_modelCB(Fl_Widget* w, void* p);
void create_customerCB(Fl_Widget* w, void *p);
void cancel_customerCB(Fl_Widget* w, void *p);
void create_salesCB(Fl_Widget* w, void* p);
void cancel_salesCB(Fl_Widget* w, void *p);
void create_ordersCB(Fl_Widget* w, void* p);
void cancel_ordersCB(Fl_Widget* w, void *p);

void refresh_ordersCB(Fl_Widget* w, void* p);
void refresh_robot_modelCB(Fl_Widget* w, void* p);
void okay_report_partsCB(Fl_Widget* w, void* p);
void refresh_report_partsCB(Fl_Widget* w, void* p);
void okay_report_modelsCB(Fl_Widget* w, void* p);
void okay_report_customersCB(Fl_Widget* w, void* p);
void refresh_report_modelsCB(Fl_Widget* w, void* p);
void refresh_report_customersCB(Fl_Widget* w, void* p);
void refresh_report_salesCB(Fl_Widget* w, void* p);
void okay_report_salesCB(Fl_Widget* w, void* p);
void refresh_report_ordersCB(Fl_Widget* w, void* p);
void okay_report_ordersCB(Fl_Widget* w, void* p);

class Robot_Part_Dialog;
class Robot_Model_Dialog;
class Report_All_Parts_Dialog;
class Report_All_Models_Dialog;
class Report_All_Customers_Dialog;
class Report_All_Sales_Dialog;
class Report_All_Orders_Dialog;
class Customer_Dialog;
class Sales_Dialog;
class Orders_Dialog;
//güd
//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg;
Robot_Model_Dialog *robot_model_dlg;
Report_All_Parts_Dialog *report_all_parts_dlg;
Report_All_Models_Dialog *report_all_models_dlg;
Customer_Dialog *customer_dlg;
Report_All_Customers_Dialog *report_all_customers_dlg;
Sales_Dialog *sales_dlg;
Report_All_Sales_Dialog *report_all_sales_dlg;
Orders_Dialog *orders_dlg;
Report_All_Orders_Dialog *report_all_orders_dlg;

Shop shop{"Robbie Robot Shop"};
Controller controller(shop);

Fl_Check_Browser* md_torso_broswer;
Fl_Check_Browser* md_head_broswer;
Fl_Check_Browser* md_arm1_broswer;
Fl_Check_Browser* md_arm2_broswer;
Fl_Check_Browser* md_locomotor_broswer;
Fl_Check_Browser* md_battery1_broswer;
Fl_Check_Browser* md_battery2_broswer;
Fl_Check_Browser* md_battery3_broswer;

Fl_Check_Browser* rt_torso_broswer;
Fl_Check_Browser* rt_head_broswer;
Fl_Check_Browser* rt_arm1_broswer;
Fl_Check_Browser* rt_locomotor_broswer;
Fl_Check_Browser* rt_battery1_broswer;

Fl_Browser* rt_models;
Fl_Browser* customers_broswer;
Fl_Browser* sales_broswer;
Fl_Browser* orders_broswer;
Fl_Check_Browser* od_models;
Fl_Check_Browser* od_customers;
Fl_Check_Browser* od_sales;
//
// Robot Part dialog
//

class Robot_Part_Dialog {
public:
    Robot_Part_Dialog() {


        shop.create_battery("B1", "3", 5.3, 10.99, 2, "The battery like no other" );
        shop.create_battery("Blue8000", "3", 5.3, 10.99, 80, "This battery has tons of power" );
        shop.create_head("TheHead", "51", 12.1, 10.99, "Robot head with lights");
        shop.create_head("V2", "11", 11.1, 15.99, "Robot head that is sturdy");
        shop.create_arm("Army", "4", 1.1, 2.99, 1, "It's an arm with flare");
        shop.create_arm("Lefty", "2", 2.1, 3.99, 2, "A left arm that can rotate");
        shop.create_arm("Righty", "1", 2.1, 2.99, 1, "A right arm that can't rotate");
        shop.create_locomotor("Loco's Motors", "22", 8.4, 11.95, 5, 2, "This will get your robot far");
        shop.create_locomotor("Motor541", "22", 1.1, 10.00, 2, 1, "caution prone to fires");
        shop.create_torso("Timmy's Torso", "1", 3.1, 3.99, 3, "This is a hard out shell of a torso");
        shop.create_torso("BaseCamp", "300", 30.1, 30.39, 1, "Toughest most reliable torso on the robot black market");

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

    double weight() {return atof(rp_weight->value());}

    double cost() {return atof(rp_cost->value());}
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
        shop.create_arm(robot_part_dlg->name(), robot_part_dlg->part_number(), robot_part_dlg->weight(),
                        robot_part_dlg->cost(), 100,  robot_part_dlg->description()) ;
    }
    if ( robot_part_dlg->type().compare("head") == 0)
    {
        shop.create_head(robot_part_dlg->name(), robot_part_dlg->part_number(), robot_part_dlg->weight(),
                         robot_part_dlg->cost(),   robot_part_dlg->description());
    }
    if ( robot_part_dlg->type().compare("torso") == 0)
    {
        shop.create_torso(robot_part_dlg->name(), robot_part_dlg->part_number(), robot_part_dlg->weight(),
                          robot_part_dlg->cost(), 2,  robot_part_dlg->description());

    }
    if ( robot_part_dlg->type().compare("battery") == 0)
    {
        shop.create_battery(robot_part_dlg->name(), robot_part_dlg->part_number(), robot_part_dlg->weight(),
                            robot_part_dlg->cost(), 100,  robot_part_dlg->description());
    }
    if ( robot_part_dlg->type().compare("locomotor") == 0)
    {
        shop.create_locomotor(robot_part_dlg->name(), robot_part_dlg->part_number(), robot_part_dlg->weight(),
                              robot_part_dlg->cost(), 100, 100,  robot_part_dlg->description());
    }


    Fl::check();

    robot_part_dlg->hide();

}

class Robot_Model_Dialog {
public:
    Robot_Model_Dialog() {


        Fl::check();

        shop.create_model("model", "12", 123.0, 0, 0,0,0,0,0,0,0);


        //Created for testing
        dialog = new Fl_Window(610, 600, "Create a Robot Model");


        md_torso_broswer = new Fl_Check_Browser(400, 10, 200, 50, "Torso");
        md_torso_broswer->align(FL_ALIGN_LEFT);

        md_head_broswer = new Fl_Check_Browser(400, 70, 200, 50, "Head");
        md_head_broswer->align(FL_ALIGN_LEFT);


        md_arm1_broswer = new Fl_Check_Browser(400, 140, 200, 50, "Arm 1");
        md_arm1_broswer->align(FL_ALIGN_LEFT);


        md_arm2_broswer = new Fl_Check_Browser(400, 210, 200, 50, "Arm 2");
        md_arm2_broswer->align(FL_ALIGN_LEFT);


        md_locomotor_broswer = new Fl_Check_Browser(400, 280, 200, 50, "Locomotor");
        md_locomotor_broswer->align(FL_ALIGN_LEFT);


        md_battery1_broswer = new Fl_Check_Browser(400, 350, 200, 50, "Battery 1");
        md_battery1_broswer->align(FL_ALIGN_LEFT);


        md_battery2_broswer = new Fl_Check_Browser(400, 420, 200, 50, "Battery 2");
        md_battery2_broswer->align(FL_ALIGN_LEFT);


        md_battery3_broswer = new Fl_Check_Browser(400, 490, 200, 50, "Battery 3");
        md_battery3_broswer->align(FL_ALIGN_LEFT);

        md_name = new Fl_Input(100, 10, 200, 25, "Name:");
        md_name->align(FL_ALIGN_LEFT);

        md_part_number = new Fl_Input(100, 40, 200, 25, "Part Number:");
        md_part_number->align(FL_ALIGN_LEFT);

        md_cost = new Fl_Input(100, 70, 200, 25, "Cost:");
        md_cost->align(FL_ALIGN_LEFT);

        md_create = new Fl_Return_Button(340, 570, 120, 25, "Create");
        md_create->callback((Fl_Callback *) create_robot_modelCB, 0);

        md_cancel = new Fl_Button(530, 570, 60, 25, "Cancel");
        md_cancel->callback((Fl_Callback *) cancel_robot_modelCB, 0);


        md_refresh = new Fl_Button(465, 570, 60, 25, "Refresh");
        md_refresh->callback((Fl_Callback *) refresh_robot_modelCB , 0);


        dialog->end();
        dialog->set_non_modal();
    }

    void show() { dialog->show(); }

    void hide() { dialog->hide(); }

    string name() { return md_name->value(); }

    string part_number() { return md_part_number->value(); }

    double cost() { return atof(md_cost->value()); }

    int torso_num() { return md_torso_broswer->value();}

    int head_num() { return md_head_broswer->value();}

    int arm1_num() { return md_arm1_broswer->value();}

    int arm2_num() { return md_arm2_broswer->value();}

    int locomotor_num() { return md_locomotor_broswer->value();}

    int battery1_num() { return md_battery1_broswer->value();}

    int battery2_num() { return md_battery2_broswer->value();}

    int battery3_num() { return md_battery3_broswer->value();}



private:
    Fl_Window *dialog;
    //Fl_Check_Browser *md_parts;
    Fl_Input *md_name;
    Fl_Input *md_part_number;
    Fl_Input *md_cost;

    Fl_Return_Button *md_create;
    Fl_Button *md_cancel;
    Fl_Button *md_refresh;
public:
    //Fl_Check_Browser *md_parts;
};


class Report_All_Parts_Dialog {
public:
    Report_All_Parts_Dialog() {


        Fl::check();


        dialog = new Fl_Window(700, 700, "Report All Parts");

        rt_torso_broswer = new Fl_Check_Browser(80, 30, 600, 100, "Torsos");
        rt_torso_broswer->align(FL_ALIGN_LEFT);

        rt_head_broswer = new Fl_Check_Browser(80, 160, 600, 100, "Heads");
        rt_head_broswer->align(FL_ALIGN_LEFT);


        rt_arm1_broswer = new Fl_Check_Browser(80, 290, 600, 100, "Arms");
        rt_arm1_broswer->align(FL_ALIGN_LEFT);

        rt_locomotor_broswer = new Fl_Check_Browser(80, 420, 600, 100, "Locomotors");
        rt_locomotor_broswer->align(FL_ALIGN_LEFT);


        rt_battery1_broswer = new Fl_Check_Browser(80, 550, 600, 100, "Batteries");
        rt_battery1_broswer->align(FL_ALIGN_LEFT);


        md_create = new Fl_Return_Button(370, 670, 120, 25, "Okay");
        md_create->callback((Fl_Callback *) okay_report_partsCB, 0);

        md_refresh = new Fl_Button(495, 670, 60, 25, "Refresh");
        md_refresh->callback((Fl_Callback *) refresh_report_partsCB , 0);


        dialog->end();
        dialog->set_non_modal();
    }

    void show() { dialog->show(); }

    void hide() { dialog->hide(); }





private:
    Fl_Window *dialog;
    //Fl_Check_Browser *md_parts;

    Fl_Return_Button *md_create;

    Fl_Button *md_refresh;
public:
    //Fl_Check_Browser *md_parts;
};

class Report_All_Models_Dialog {
public:
    Report_All_Models_Dialog() {
        Fl::check();
        dialog = new Fl_Window(700, 200, "Report All Models");

        rt_models = new Fl_Browser(80, 30, 600, 100, "Models");
        rt_models->align(FL_ALIGN_LEFT);

        md_create = new Fl_Return_Button(450, 150, 120, 25, "Okay");
        md_create->callback((Fl_Callback *) okay_report_modelsCB, 0);

        md_refresh = new Fl_Button(575, 150, 60, 25, "Refresh");
        md_refresh->callback((Fl_Callback *) refresh_report_modelsCB , 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() { dialog->show(); }
    void hide() { dialog->hide(); }

private:
    Fl_Window *dialog;
    Fl_Return_Button *md_create;
    Fl_Button *md_refresh;

};

class Customer_Dialog { //Name address phone number email address
public:
    Customer_Dialog() {

        dialog = new Fl_Window(340, 270, "Customer");

        bc_name = new Fl_Input(120, 10, 210, 25, "Name:");
        bc_name->align(FL_ALIGN_LEFT);

        bc_address = new Fl_Input(120, 40, 210, 25, "Address:");
        bc_address->align(FL_ALIGN_LEFT);

        bc_phonenumber = new Fl_Input(120, 70, 210, 25, "Phone:");
        bc_phonenumber->align(FL_ALIGN_LEFT);

        bc_emailaddress = new Fl_Input(120, 100, 210, 25, "Email:");
        bc_emailaddress->align(FL_ALIGN_LEFT);

        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_customerCB, 0);

        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_customerCB, 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return bc_name->value();}
    string adress() {return bc_address->value();}

    string phonenumber() {return bc_phonenumber->value();}
    string emailadress() {return bc_emailaddress->value();}

private:
    Fl_Window *dialog;
    Fl_Input *bc_name;
    Fl_Input *bc_address;
    Fl_Input *bc_phonenumber;
    Fl_Input *bc_emailaddress;

    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

class Report_All_Customers_Dialog {
public:
    Report_All_Customers_Dialog() {
        Fl::check();
        dialog = new Fl_Window(700, 200, "Report All Customers");

        customers_broswer = new Fl_Browser(80, 30, 600, 100, "Customers");
        customers_broswer->align(FL_ALIGN_LEFT);

        md_create = new Fl_Return_Button(450, 150, 120, 25, "Okay");
        md_create->callback((Fl_Callback *) okay_report_customersCB, 0);

        md_refresh = new Fl_Button(575, 150, 60, 25, "Refresh");
        md_refresh->callback((Fl_Callback *) refresh_report_customersCB , 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() { dialog->show(); }
    void hide() { dialog->hide(); }

private:
    Fl_Window *dialog;
    Fl_Return_Button *md_create;
    Fl_Button *md_refresh;

};

class Sales_Dialog { //Name address phone number email address
public:
    Sales_Dialog() {

        dialog = new Fl_Window(340, 270, "Sales Associate");

        sa_name = new Fl_Input(120, 10, 210, 25, "Name:");
        sa_name->align(FL_ALIGN_LEFT);

        sa_number = new Fl_Input(120, 40, 210, 25, "Number:");
        sa_number->align(FL_ALIGN_LEFT);

        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_salesCB, 0);

        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_salesCB, 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return sa_name->value();}
    string number() {return sa_number->value();}


private:
    Fl_Window *dialog;
    Fl_Input *sa_name;
    Fl_Input *sa_number;


    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

class Report_All_Sales_Dialog {
public:
    Report_All_Sales_Dialog() {
        Fl::check();
        dialog = new Fl_Window(700, 200, "Report All Sales Associates");

        sales_broswer = new Fl_Browser(80, 30, 600, 100, "Sales\nAssociates");
        sales_broswer->align(FL_ALIGN_LEFT);

        md_create = new Fl_Return_Button(450, 150, 120, 25, "Okay");
        md_create->callback((Fl_Callback *) okay_report_salesCB, 0);

        md_refresh = new Fl_Button(575, 150, 60, 25, "Refresh");
        md_refresh->callback((Fl_Callback *) refresh_report_salesCB , 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() { dialog->show(); }
    void hide() { dialog->hide(); }

private:
    Fl_Window *dialog;
    Fl_Return_Button *md_create;
    Fl_Button *md_refresh;

};

class Report_All_Orders_Dialog {
public:
    Report_All_Orders_Dialog() {
        Fl::check();
        dialog = new Fl_Window(700, 200, "Report All Orders");

        orders_broswer = new Fl_Browser(80, 30, 600, 100, "Orders");
        orders_broswer->align(FL_ALIGN_LEFT);

        md_create = new Fl_Return_Button(450, 150, 120, 25, "Okay");
        md_create->callback((Fl_Callback *) okay_report_ordersCB, 0);

        md_refresh = new Fl_Button(575, 150, 60, 25, "Refresh");
        md_refresh->callback((Fl_Callback *) refresh_report_ordersCB , 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() { dialog->show(); }
    void hide() { dialog->hide(); }

private:
    Fl_Window *dialog;
    Fl_Return_Button *md_create;
    Fl_Button *md_refresh;

};


class Orders_Dialog {
public:
    Orders_Dialog() {


        Fl::check();

        //Created for testing
        dialog = new Fl_Window(610, 600, "Create an Order");

        od_customers = new Fl_Check_Browser(400, 10, 200, 50, "Customers");
        od_customers->align(FL_ALIGN_LEFT);

        od_models = new Fl_Check_Browser(400, 70, 200, 50, "Models");
        od_models->align(FL_ALIGN_LEFT);


        od_sales= new Fl_Check_Browser(400, 140, 200, 50, "Sales\nAssociates");
        od_sales->align(FL_ALIGN_LEFT);

        od_number = new Fl_Input(100, 10, 200, 25, "Order Number:");
        od_number->align(FL_ALIGN_LEFT);

        od_date = new Fl_Input(100, 40, 200, 25, "Date:");
        od_date->align(FL_ALIGN_LEFT);

        md_create = new Fl_Return_Button(340, 570, 120, 25, "Create");
        md_create->callback((Fl_Callback *) create_ordersCB, 0);

        md_cancel = new Fl_Button(530, 570, 60, 25, "Cancel");
        md_cancel->callback((Fl_Callback *) cancel_ordersCB, 0);


        md_refresh = new Fl_Button(465, 570, 60, 25, "Refresh");
        md_refresh->callback((Fl_Callback *) refresh_ordersCB , 0);


        dialog->end();
        dialog->set_non_modal();
    }

    void show() { dialog->show(); }

    void hide() { dialog->hide(); }

    string number() { return od_number->value(); }

    string date() { return od_date->value(); }

    int model_num() { return od_models->value();}

    int sales_num() { return od_sales->value();}

    int customer_num() { return od_customers->value();}


private:
    Fl_Window *dialog;
    Fl_Input *od_number;
    Fl_Input *od_date;

    Fl_Return_Button *md_create;
    Fl_Button *md_cancel;
    Fl_Button *md_refresh;

};

//
/// Callbacks
//

void CB(Fl_Widget* w, void* p) { } // No action

void menu_create_robot_partCB(Fl_Widget* w, void* p) { robot_part_dlg->show(); }
void menu_create_customerCB(Fl_Widget* w, void* p) { customer_dlg->show(); }
void menu_create_robot_modelCB(Fl_Widget* w, void* p) { robot_model_dlg->show(); }
void menu_create_salesCB(Fl_Widget* w, void* p) { sales_dlg->show(); }
void menu_create_orderCB(Fl_Widget* w, void* p) { orders_dlg->show(); }

void menu_report_robot_partsCB(Fl_Widget* w, void* p) { report_all_parts_dlg->show(); }
void menu_report_robot_modelsCB(Fl_Widget* w, void* p) { report_all_models_dlg->show(); }
void menu_report_customersCB(Fl_Widget* w, void *p) { report_all_customers_dlg->show(); }
void menu_report_salesCB(Fl_Widget* w, void* p) { report_all_sales_dlg->show(); }
void menu_report_ordersCB(Fl_Widget* w, void* p) { report_all_orders_dlg->show(); }

void okay_report_modelsCB(Fl_Widget* w, void* p) { report_all_models_dlg->hide(); }
void okay_report_partsCB(Fl_Widget* w, void* p) { report_all_parts_dlg->hide(); }
void okay_report_customersCB(Fl_Widget* w, void* p) { report_all_customers_dlg->hide(); }
void okay_report_salesCB(Fl_Widget* w, void* p) { report_all_sales_dlg->hide(); }
void okay_report_ordersCB(Fl_Widget* w, void* p) { report_all_orders_dlg->hide(); }

void cancel_robot_modelCB(Fl_Widget* w, void* p) { robot_model_dlg->hide(); }
void cancel_robot_partCB(Fl_Widget* w, void* p){ robot_part_dlg->hide();  }
void cancel_customerCB(Fl_Widget* w, void* p) { customer_dlg->hide(); }
void cancel_salesCB(Fl_Widget* w, void* p) { sales_dlg->hide(); }
void cancel_ordersCB(Fl_Widget* w, void* p) { orders_dlg->hide(); }


void refresh_robot_modelCB(Fl_Widget* w, void* p) {


    robot_model_dlg->hide();
    md_torso_broswer->clear();
    md_head_broswer->clear();
    md_arm1_broswer->clear();
    md_arm2_broswer->clear();
    md_locomotor_broswer->clear();
    md_battery1_broswer->clear();
    md_battery2_broswer->clear();
    md_battery3_broswer->clear();

    char* c;
    string s;

    for (Torso t: shop.torsos())
    {
        cout << t << endl;
        s = t.to_string();
        c = controller.get_charstar(s);
        md_torso_broswer->add(c);
    }

    for (Arm a: shop.arms()){
        cout << a << endl;
        s = a.to_string();
        c = controller.get_charstar(s);
        md_arm1_broswer->add(c);
        md_arm2_broswer->add(c);
    }

    for (Head h: shop.heads()){

        cout << h << endl;
        s = h.to_string();
        c = controller.get_charstar(s);
        md_head_broswer->add(c);
    }

    for (Locomotor l: shop.locomotors()){
        cout << l << endl;
        s = l.to_string();
        c = controller.get_charstar(s);
        md_locomotor_broswer->add(c);
    }
    int bnum = 0;
    for (Battery b: shop.batteries()){
        cout << b << endl;
        s = b.to_string();
        //s = to_string(b);
        c = controller.get_charstar(s);
        md_battery1_broswer->add(c);
        md_battery2_broswer->add(c);
        md_battery3_broswer->add(c);
        bnum++;

    }
    //robot_model_dlg->hide();
    //report_all_parts_dlg->hide();
    robot_model_dlg->show();
    //report_all_parts_dlg->show();

};

void refresh_report_partsCB(Fl_Widget* w, void* p) {
    report_all_parts_dlg->hide();
    rt_torso_broswer->clear();
    rt_head_broswer->clear();
    rt_arm1_broswer->clear();
    rt_locomotor_broswer->clear();
    rt_battery1_broswer->clear();

    char* c;
    string s;
    ostringstream os;

    for (Torso t: shop.torsos())
    {

        cout << t << endl;
        os<<t;
        s=os.str();

        c = controller.get_charstar(s);
        rt_torso_broswer->add(c);
        os.str("");
        //os.clear();
    }

    for (Arm a: shop.arms()){
        cout << a << endl;
        os << a;
        s=os.str();

        c = controller.get_charstar(s);
        rt_arm1_broswer->add(c);
        os.str("");
        //os.clear();
    }

    for (Head h: shop.heads()){

        cout << h << endl;
        os << h;
        s=os.str();
        c = controller.get_charstar(s);
        rt_head_broswer->add(c);
        os.str("");
        //os.clear();
    }

    for (Locomotor l: shop.locomotors()){
        cout << l << endl;
        os << l;
        s = os.str();

        c = controller.get_charstar(s);
        rt_locomotor_broswer->add(c);
        os.str("");
        //os.clear();
    }

    for (Battery b: shop.batteries()){
        cout << b << endl;
        os << b;
        s = os.str();
        c = controller.get_charstar(s);

        rt_battery1_broswer->add(c);

        os.str("");


    }

    os.clear();

    report_all_parts_dlg->show();

}

void refresh_report_modelsCB(Fl_Widget* w, void* p) {
    report_all_models_dlg->hide();
    rt_models->clear();

    char* c;
    string s;
    ostringstream os;
    for (Robot_model r: shop.models())
    {
        cout << r << endl;
        //s = r.to_string();
        cout << r.arm1() << endl;
        //cout << r << endl;
        os << r << setprecision(2) <<" parts cost $" <<
                          controller.get_total_parts_cost
                (r.torso(), r.head(), r.arm1(), r.arm2(), r.locomotor(),
                 r.battery1(), r.battery2(), r.battery3())<< " | "

                << (shop.torsos()[r.torso()]).to_string() << " | "
                << (shop.heads()[r.head()]).to_string() << " | "
                << (shop.arms()[r.arm1()]).to_string() << " | "
                << (shop.arms()[r.arm2()]).to_string() << " | "
                << (shop.locomotors()[r.locomotor()]).to_string() << " | "
                << (shop.batteries()[r.battery1()]).to_string() << " | "
                << (shop.batteries()[r.battery2()]).to_string() << " | "
                << (shop.batteries()[r.battery3()]).to_string();

        s=os.str();
        c = controller.get_charstar(s);
        rt_models->add(c);
        os.str("");
    }

    report_all_models_dlg->show();

}

void refresh_report_customersCB(Fl_Widget* w, void* p) {
    report_all_customers_dlg->hide();
    customers_broswer->clear();

    char* c;
    string s;
    ostringstream os;
    for (Customer cu: shop.customers())
    {
        cout << cu << endl;
        os << cu;
        s = os.str();
        c = controller.get_charstar(s);
        customers_broswer->add(c);
        os.str("");
    }
    report_all_customers_dlg->show();

}

void create_robot_modelCB(Fl_Widget* w, void* p) { // Replace with call to model!

    shop.create_model(robot_model_dlg->name(),
                      robot_model_dlg->part_number(),
                      robot_model_dlg->cost(),
                      (robot_model_dlg->torso_num() - 1),
                      (robot_model_dlg->head_num() - 1),
                      (robot_model_dlg->arm1_num() - 1),
                      (robot_model_dlg->arm2_num() - 1),
                      (robot_model_dlg->locomotor_num() - 1),
                      (robot_model_dlg->battery1_num() - 1),
                      (robot_model_dlg->battery2_num() - 1),
                      (robot_model_dlg->battery3_num() - 1 ));
    Fl::check();
    robot_model_dlg->hide();
}

void create_customerCB(Fl_Widget* w, void* p) {

    shop.create_customer(customer_dlg->name(), customer_dlg->phonenumber());

    customer_dlg->hide();
}

void create_ordersCB(Fl_Widget* w, void* p) { // Replace with call to model!

    shop.create_order(orders_dlg->number(), orders_dlg->date(), orders_dlg->model_num() -1,
                         orders_dlg->customer_num() -1, orders_dlg->sales_num() -1 );
    Fl::check();
    orders_dlg->hide();
}

void create_salesCB(Fl_Widget* w, void* p) {

    shop.create_sales_associate(sales_dlg->name(), sales_dlg->number());
    sales_dlg->hide();
}

void refresh_report_salesCB(Fl_Widget* w, void* p) {

    report_all_sales_dlg->hide();
    sales_broswer->clear();

    char* c;
    string s;
    ostringstream os;
    for (Sales_associate sa: shop.sales_associates())
    {
        cout << sa << endl;
        os << sa;
        s = os.str();
        c = controller.get_charstar(s);
        sales_broswer->add(c);
        os.str("");
    }
    report_all_sales_dlg->show();

}

void refresh_ordersCB(Fl_Widget* w, void* p) {


    orders_dlg->hide();
    od_customers->clear();
    od_models->clear();
    od_sales->clear();

    char* c;
    string s;
    ostringstream os;

    for (Sales_associate sa: shop.sales_associates())
    {
        cout << sa << endl;
        os << sa;
        s = os.str();
        c = controller.get_charstar(s);
        od_sales->add(c);
        os.str("");
    }

    for (Customer cu: shop.customers())
    {
        cout << cu << endl;
        os << cu;
        s = os.str();
        c = controller.get_charstar(s);
        od_customers->add(c);
        os.str("");
    }

    for (Robot_model r: shop.models())
    {
        cout << r << endl;
        os << r ;
        s=os.str();
        c = controller.get_charstar(s);
        od_models->add(c);
        os.str("");
    }

    orders_dlg->show();


};


void refresh_report_ordersCB(Fl_Widget* w, void* p) {
    report_all_orders_dlg->hide();
    orders_broswer->clear();

    char* c;
    string s;
    ostringstream os;
    for (Order r: shop.orders())
    {
        cout << r << endl;
        //s = r.to_string();

        //cout << r << endl;
        os << r << "Model: " << (shop.models()[r.model()]).name() << " | "
           << "Customer: " << (shop.customers()[r.customer()].name()) << " | "
           << "Sales Associate: " << (shop.sales_associates()[r.sales_associate()].name());

        s=os.str();
        c = controller.get_charstar(s);
        orders_broswer->add(c);
        os.str("");
    }

    report_all_orders_dlg->show();

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
        { "Order", 0, (Fl_Callback *)menu_create_orderCB, 0, FL_MENU_DIVIDER  },
        { "Customer", 0, (Fl_Callback *)menu_create_customerCB },
        { "Sales Associate", 0, (Fl_Callback *)menu_create_salesCB, 0, FL_MENU_DIVIDER  },
        { "Robot Part", 0, (Fl_Callback *)menu_create_robot_partCB },
        { "Robot Model", 0, (Fl_Callback *)menu_create_robot_modelCB },
        { 0 },
        { "&Report", 0, 0, 0, FL_SUBMENU },
        { "Invoice", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
        { "All Orders", 0, (Fl_Callback *)menu_report_ordersCB },
        { "Orders by Customer", 0, (Fl_Callback *)CB },
        { "Orders by Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
        { "All Customers", 0, (Fl_Callback *)menu_report_customersCB },
        { "All Sales Associates", 0, (Fl_Callback *)menu_report_salesCB, 0, FL_MENU_DIVIDER  },
        { "All Robot Models", 0, (Fl_Callback *)menu_report_robot_modelsCB },
        { "All Robot Parts", 0, (Fl_Callback *)menu_report_robot_partsCB },
        { 0 },
        { "&Help", 0, 0, 0, FL_SUBMENU },
        { "&Manual", 0, (Fl_Callback *)CB},
        { "&About", 0, (Fl_Callback *)CB},
        { 0 },
        { 0 }
};



int main() {

    const int X = 660;
    const int Y = 320;

    // Create dialogs
    robot_part_dlg = new Robot_Part_Dialog{};
    robot_model_dlg = new Robot_Model_Dialog {};
    customer_dlg =  new Customer_Dialog {};
    sales_dlg = new Sales_Dialog{};
    orders_dlg = new Orders_Dialog{};
    report_all_models_dlg = new Report_All_Models_Dialog{};
    report_all_parts_dlg = new Report_All_Parts_Dialog {};
    report_all_customers_dlg = new Report_All_Customers_Dialog {};
    report_all_sales_dlg = new Report_All_Sales_Dialog {};
    report_all_orders_dlg = new Report_All_Orders_Dialog{};

    // Create a window
    //fl_register_images();
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
