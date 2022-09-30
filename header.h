
#ifndef EXCEL_HELLO_HEADER_H
#define EXCEL_HELLO_HEADER_H

#include <fstream>
#include <string>
#include "MD5.h"

using namespace std;
string get_fistname();
string get_lastname();
string get_working_airport();
string get_vacation_airport();
pair<string, int> get_date();
pair<string, string> get_departure_and_arrival(int month);
pair<string, int> get_class_and_cost();
#endif //EXCEL_HELLO_HEADER_H
