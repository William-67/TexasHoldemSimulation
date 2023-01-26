//
// Created by william on 2022-11-30.
//

#ifndef LAB10_TEXASHOLDEM_H
#define LAB10_TEXASHOLDEM_H

#include "Poker.h"

using namespace std;

class TexasHoldem : public Poker {

public:
    TexasHoldem();
    TexasHoldem(int);

    void deal();
    vector<string> hands();



    string returnBestHands(vector<string>,int&);
};


#endif //LAB10_TEXASHOLDEM_H
