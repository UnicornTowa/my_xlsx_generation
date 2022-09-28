#include "header.h"
#include "libxl.h"

using namespace libxl;

int main()
{
    auto* book = xlCreateXMLBook();
    if(book)
    {
        auto* sheet = book->addSheet("Sheet1");
        if(sheet)
        {
            sheet->writeStr(1, 0, "Passenger name");
            sheet->writeStr(1, 1, "Departure");
            sheet->writeStr(1, 2, "Arrival");
            sheet->writeStr(1, 3, "Date");
            for(int i = 2; i <= 100001; i++){
                sheet->writeStr(i, 0, (get_fistname() + " " + get_lastname()).c_str());
                auto air1 = get_airport();
                auto air2 = get_airport();
                while (air1 == air2)
                    air2 = get_airport();
                sheet->writeStr(i, 1, air1.c_str());
                sheet->writeStr(i, 2, air2.c_str());
                sheet->writeStr(i, 3, get_date().c_str());
            }

        }
        book->save("my_base.xlsx");
        book->release();
    }
    return 0;
}