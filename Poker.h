//
// Created by william on 2022-11-29.
//

#ifndef LAB10_POKER_H
#define LAB10_POKER_H

#include <list>
#include <string>
#include <vector>

using namespace std;

//#define ranks {"2","3","4","5","6","7","8","9","T","J","Q","K","A"};
//#define suits {"D","C","S","H"};


class Poker {


protected:

    int num;
    vector<vector<string> > playerCard;
    vector<string> table;
    vector<string> deck;

    string ranks[13] = {"2","3","4","5","6","7","8","9","T","J","Q","K","A"};
    string suits[4] =  {"D","C","S","H"};

public:
    Poker();
    Poker(int);
    bool add_card(int);
    bool add_to_table();

    bool isStraightFlush(vector<string>);
    bool isFourofaKind(vector<string>);
    bool isFullHouse(vector<string>);
    bool isFlush(vector<string>);
    bool isStraight(vector<string>);
    bool isThreeofaKind(vector<string>);

    bool isTwoPairs(vector<string>);
    bool isOnePair(vector<string>);

    bool areConsecutive(int[],int);
    bool isTwoofaKind(vector<string>);

    //this two methods are just for testing
    vector<vector<string> > getPlayerCards();
    vector<string> getTable();
};


#endif //LAB10_POKER_H
