#include "header.h"
#include "libxl.h"

using namespace libxl;

int main(){
    auto* book = xlCreateXMLBookA();
    if(book){
        auto* sheet = book->addSheet("Sheet1");
        auto* sheet2 = book->addSheet("Sheet_Hash");
        if(sheet && sheet2){
            sheet->writeStr(1, 0, "Passenger name");
            sheet->writeStr(1, 1, "Departure");
            sheet->writeStr(1, 2, "Arrival");
            sheet->writeStr(1, 3, "Date");
            sheet->writeStr(1, 4, "Class");
            sheet->writeStr(1, 5, "Ticket cost, $");
            sheet2->writeStr(1, 0, "Name Hash");
            for(int i = 2; i <= 100001; i++){
                auto name = get_fistname() + " " + get_lastname();
                sheet->writeStr(i, 0, name.c_str());
                sheet2->writeStr(i, 0, md5(name).c_str());
                auto date = get_date();
                auto get_airports = get_departure_and_arrival(date.second);
                sheet->writeStr(i, 1, get_airports.first.c_str());
                sheet->writeStr(i, 2, get_airports.second.c_str());
                sheet->writeStr(i, 3, date.first.c_str());
                auto class_and_cost = get_class_and_cost();
                sheet->writeStr(i, 4, class_and_cost.first.c_str());
                sheet->writeNum(i, 5, class_and_cost.second);
            }
        }
        book->save("new_base_2.xlsx");
        book->release();
    }
    return 0;
}