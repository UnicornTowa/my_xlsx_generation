#include "header.h"

pair<string, string> get_departure_and_arrival(int month){
    int my_rand = 1 + rand() % 100;
    pair<string, string> res;
    if (5 <= month and month <= 9){
        if (my_rand <= 32){
            res.first = get_working_airport();
            res.second = get_vacation_airport();
            return res;
        }
        else if (my_rand <= 64){
            res.first = get_vacation_airport();
            res.second = get_working_airport();
            return res;
        }
        else if (my_rand <= 78){
            res.first = get_vacation_airport();
            res.second = get_vacation_airport();
            while (res.first == res.second)
                res.second = get_vacation_airport();
            return res;
        }
        else {
            res.first = get_working_airport();
            res.second = get_working_airport();
            while (res.second == res.first)
                res.second = get_working_airport();
            return res;
        }
    }
    else{
        if (my_rand <= 50){
            res.first = get_working_airport();
            res.second = get_working_airport();
            while (res.second == res.first)
                res.second = get_working_airport();
            return res;
        }
        else if (my_rand <= 65){
            res.first = get_working_airport();
            res.second = get_vacation_airport();
            return res;
        }
        else if (my_rand <= 80){
            res.first = get_vacation_airport();
            res.second = get_working_airport();
            return res;
        }
        else{
            res.first = get_vacation_airport();
            res.second = get_vacation_airport();
            while (res.first == res.second)
                res.second = get_vacation_airport();
            return res;
        }
    }
}

pair<string, int> get_class_and_cost(){
    pair<string, int> res;
    if(rand() % 10 == 0)
        return pair("business", 350 + rand() % 2001);
    else return pair("economy", 50 + rand() % 201);
}