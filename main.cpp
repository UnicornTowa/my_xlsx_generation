#include "header.h"
#include "libxl.h"

using namespace libxl;

int main(){
    auto* book = xlCreateXMLBook();
    if(book){
        auto* sheet = book->addSheet("Sheet1");
        if(sheet){
            sheet->writeStr(1, 0, "Passenger name");
            sheet->writeStr(1, 1, "Departure");
            sheet->writeStr(1, 2, "Arrival");
            sheet->writeStr(1, 3, "Date");
            sheet->writeStr(1, 4, "Class");
            sheet->writeStr(1, 5, "Ticket cost, $");
            for(int i = 2; i <= 100001; i++){
                sheet->writeStr(i, 0, (get_fistname() + " " + get_lastname()).c_str());
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