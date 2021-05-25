#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits>
#include "Information.h"
using namespace std;

class TextQuery
{
    public:
        TextQuery();
        void userMenu();
        void print() const;
        void BlastFromThePast() const;
        void RankingRange(double lowBound, double highBound) const;
        void PeopleVsGibbons(double separation) const;
        void Recommendation(int playtime, int playercount, double minRanking) const;

    private:
        Information info;
        vector<Information> results;

};

#endif // TEXTQUERY_H
