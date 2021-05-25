#include "Information.h"
Information Information::old(vector<Information> results)
{
    Information temp = results[0];
    for(const auto& elem: results)
    {
        if(temp.m_year > elem.m_year)
        {
            temp = elem;
        }
    }

    return temp;
}

