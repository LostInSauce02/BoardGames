#ifndef INFORMATION_H
#define INFORMATION_H
using namespace std;
#include <iostream>
#include <string>
#include <vector>
class Information
{
    public:
        Information() = default;
        /*inline Information(string name, string year, string GibbRating, string PubRating, string Weight, string MaxPlayers, string MaxTime):
            m_name(name), m_year(year), m_GibbRating(GibbRating), m_PubRating(PubRating), m_Weight(Weight), m_MaxPlayers(MaxPlayers), m_MaxTime(MaxTime){}*/
        inline Information(string name, int year, double GibbRating, double PubRating, double Weight, int MaxPlayers, int MaxTime):
            m_name(name), m_year(year), m_GibbRating(GibbRating), m_PubRating(PubRating), m_Weight(Weight), m_MaxPlayers(MaxPlayers), m_MaxTime(MaxTime){}
        static Information old(vector<Information> results);
//-------------------------------------------------------------------------------------------------------------------------
        string m_name;
        //string m_year;
        int m_year;
        //string m_GibbRating;
        double m_GibbRating;
        //string m_PubRating;
        double m_PubRating;
        //string m_Weight;
        double m_Weight;
        //string m_MaxPlayers;
        int m_MaxPlayers;
        //string m_MaxTime;
        int m_MaxTime;
};

#endif // INFORMATION_H
