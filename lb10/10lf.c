#include <stdio.h>
#include "structh.h"
#include <locale.h>
#include <wchar.h>


int work(Time fullstart, Time fullend) {
    int startminutes = fullstart.hours * 60 + fullstart.minutes;
    int endminutes = fullend.hours*60+fullend.minutes;

    return endminutes - startminutes;




}