#include "TextQuery.h"

TextQuery::TextQuery()
{
    string contents;
    string tempName;
    //string tempYear;
    int tempYear;
    //string tempGibbRating;
    double tempGibbRating;
    //string tempPubRating;
    double tempPubRating;
    //string tempWeight;
    double tempWeight;
    //string tempMaxPlayers;
    int tempMaxPlayers;
    //string tempMaxTime;
    int tempMaxTime;
    ifstream infile;
    infile.open("sample.tsv");
    getline(infile, contents);
    while(infile.is_open() && infile.good())
    {
        getline(infile, contents);
        istringstream ss(contents);
        ss >> tempName >> tempYear >> tempGibbRating >> tempPubRating >> tempWeight >> tempMaxPlayers >> tempMaxTime;
        if(!infile.eof())
        {
            Information info(tempName, tempYear, tempGibbRating, tempPubRating, tempWeight, tempMaxPlayers, tempMaxTime);
            results.push_back(info);
        }
    }
    infile.close();
}

void TextQuery::userMenu()
{
    while(true)
    {
        cout << "User Menu" << '\n';
        cout << "---------" << '\n';
        cout << "1) Print All Games" << '\n';
        cout << "2) Blast From the Past" << '\n';
        cout << "3) Ranking Range" << '\n';
        cout << "4) The People VS Dr. Gibbons" << '\n';
        cout << "5) Find Game Recommendations" << '\n';
        cout << "6) Exit" << '\n';
        cout << endl;

        int selection = 0;
        cout << "Please Enter a Selection: ";
        cin >> selection;
        cout << endl;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cerr << "Sorry, the entered input is not an int. Try again: ";
            cin >> selection;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "The number entered: " << selection << '\n';
        cout << endl;

        if(selection > 6 || selection < 1)
        {
            cerr << "Error! Invalid Selection, Try Again" << '\n';
        }
        else
        {
            if(selection == 1)
            {
                print();
                cout << endl;
            }
            else if(selection == 2)
            {
                BlastFromThePast();
                cout << endl;
            }
            else if(selection == 3)
            {
                while(true)
                {
                    double lowerBound = 0;
                    double higherBound = 0;
                    cout << "Enter Lower Ranking Bound (1-10): ";
                    cin >> lowerBound;
                    cout << "Enter Higher Ranking Bound (1-10): ";
                    cin >> higherBound;
                    if(lowerBound < 1 || lowerBound > 10)
                    {
                        cerr << "Error! Invalid Lower Bound" << '\n';
                    }
                    else if((higherBound < lowerBound) || (lowerBound > higherBound))
                    {
                        cerr << "Error! Entered Values do not correspond. Try Again!" << '\n';
                    }
                    else
                    {
                        RankingRange(lowerBound, higherBound);
                        cout << endl;
                        break;
                    }
                }
            }
            else if(selection == 4)
            {
                while(true)
                {
                    double separation = 0;
                    cout << "Enter A Separation Number (0-10): ";
                    cin >> separation;
                    if(separation < 0 || separation > 10)
                    {
                        cerr << "Error! Number Entered our of Range" << '\n';
                    }
                    else
                    {
                        PeopleVsGibbons(separation);
                        cout << endl;
                        break;
                    }
                }

            }
            else if(selection == 5)
            {
                int playtime = 0;
                int playercount = 0;
                double minRanking = 0;
                cout << "Enter Desired Play Time: ";
                cin >> playtime;
                cout << "Enter Desired Player Count: ";
                cin >> playercount;
                cout << "Enter Desired Minimum Ranking(1-10): ";
                cin >> minRanking;
                Recommendation(playtime, playercount, minRanking);
                cout << endl;
            }
            else if(selection == 6)
            {
                cout << "Thank You!!!";
                break;
            }
        }
    }
}

void TextQuery::print() const
{
    for(const auto& elem : results)
    {
        cout << elem.m_name << " (" << elem.m_year << ") " << "[GR= " << elem.m_GibbRating << ", PR= " << elem.m_PubRating << ", WT= " << elem.m_Weight <<
        ", MP= " << elem.m_MaxPlayers << ", MT= " << elem.m_MaxTime << "]" << '\n';
    }
}

void TextQuery::BlastFromThePast() const
{
    Information oldest = Information::old(results);
    cout << oldest.m_name << " (" << oldest.m_year << ") " << "[GR= " << oldest.m_GibbRating << ", PR= " << oldest.m_PubRating << ", WT= " << oldest.m_Weight <<
        ", MP= " << oldest.m_MaxPlayers << ", MT= " << oldest.m_MaxTime << "]" << '\n';
}

void TextQuery::RankingRange(double lowBound, double highBound) const
{
    for(const auto& elem : results)
    {
        if((elem.m_GibbRating <= highBound) && (elem.m_GibbRating >= lowBound))
        {
            cout << elem.m_name << " (" << elem.m_year << ") " << "[GR= " << elem.m_GibbRating << ", PR= " << elem.m_PubRating << ", WT= " << elem.m_Weight <<
            ", MP= " << elem.m_MaxPlayers << ", MT= " << elem.m_MaxTime << "]" << '\n';
        }
    }
}

void TextQuery::PeopleVsGibbons(double separation) const
{
    for(const auto& elem : results)
    {
        if((abs(elem.m_GibbRating - elem.m_PubRating)) >= separation)
        {
            cout << elem.m_name << " (" << elem.m_year << ") " << "[GR= " << elem.m_GibbRating << ", PR= " << elem.m_PubRating << ", WT= " << elem.m_Weight <<
                ", MP= " << elem.m_MaxPlayers << ", MT= " << elem.m_MaxTime << "]" << '\n';
        }
    }
}

void TextQuery::Recommendation(int playtime, int playercount, double minRanking) const
{
    for(const auto& elem: results)
    {
        if((elem.m_MaxTime <= playtime) && (elem.m_MaxPlayers >= playercount) && (elem.m_GibbRating >= minRanking))
        {
            cout << elem.m_name << " (" << elem.m_year << ") " << "[GR= " << elem.m_GibbRating << ", PR= " << elem.m_PubRating << ", WT= " << elem.m_Weight <<
                ", MP= " << elem.m_MaxPlayers << ", MT= " << elem.m_MaxTime << "]" << '\n';
        }
    }
}
