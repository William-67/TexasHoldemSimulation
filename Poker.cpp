//
// Created by william on 2022-11-29.
//

#include <iostream>
#include <algorithm>
#include "Poker.h"
#include <sstream>

using namespace std;


Poker::Poker() {

    num = 2;

    playerCard = vector<vector<string> >(num);


    int i,j;
    for (i = 0; i < 13; ++i) {
        for (j = 0; j < 4; ++j) {

            string temp = ranks[i] + suits[j];

            deck.push_back(temp);

        }
    }

    random_shuffle(deck.begin(),deck.end());


}

Poker::Poker(int a) {

    num = a;
    playerCard = vector<vector<string> >(num);

    int i,j;
    for (i = 0; i < 13; ++i) {
        for (j = 0; j < 4; ++j) {

            string temp = ranks[i] + suits[j];

            deck.push_back(temp);

        }
    }

    random_shuffle(deck.begin(),deck.end());
}

bool Poker::add_card(int index) {

    if (deck.empty()){
        return false;
    }


    playerCard[index].push_back(deck.front());

//    cout<<playerCard[index].size()<<endl;

    deck.erase(deck.begin());
    return true;
}

bool Poker::add_to_table() {

    if (deck.empty()){
        return false;
    }

    table.push_back(deck.front());

    deck.erase(deck.begin());
    return true;
}

bool Poker::isStraightFlush(vector<string> cards) {

    return isFlush(cards) && isStraight(cards);
}

bool Poker::areConsecutive(int array[], int n) {

    sort(array,array+n);

    for (int i = 0; i < n-1; ++i) {
        if (array[i+1]!=array[i]+1){
            return false;
        }
    }
    return true;
}

bool Poker::isFourofaKind(vector<string> cards) {

    int i,j;

    for (i = 0; i < cards.size()-1; ++i) {

        int count = 1;

        for (j = i+1; j < cards.size(); ++j) {

            if (cards[i][0] == cards[j][0]){

                count++;

            }

        }

        if (count ==4) return true;

    }

    return false;
}

bool Poker::isThreeofaKind(vector<string> cards) {
    int i,j;

    for (i = 0; i < cards.size()-1; ++i) {

        int count = 1;

        for (j = i+1; j < cards.size(); ++j) {

            if (cards[i][0] == cards[j][0]){

                count++;

            }

        }

        if (count ==3) return true;

    }

    return false;
}

bool Poker::isFlush(vector<string> cards) {
    int i;

    for (i = 0; i < cards.size()-1; ++i) {

        if (cards[i][1] != cards[i+1][1]){
            return false;
        }

    }

    return true;
}

bool Poker::isStraight(vector<string> cards) {
    int i;
    int array[5];

    for (i = 0; i < cards.size(); ++i) {

        int temp;
        switch (cards[i][0]) {
            case 'T':
                temp = 10;
                break;
            case 'J':
                temp = 11;
                break;
            case 'Q':
                temp = 12;
                break;
            case 'K':
                temp = 13;
                break;
            case 'A':
                temp = 14;
                break;
            default:
                stringstream ss;
                ss << cards[i][0];
                ss >> temp;
        }
        array[i] = temp;
    }
    return areConsecutive(array,cards.size());
}

bool Poker::isFullHouse(vector<string> cards) {
    return isThreeofaKind(cards) && isTwoofaKind(cards);
}

bool Poker::isTwoofaKind(vector<string> cards) {
    int i,j;

    for (i = 0; i < cards.size()-1; ++i) {

        int count = 1;

        for (j = i+1; j < cards.size(); ++j) {

            if (cards[i][0] == cards[j][0]){

                count++;

            }

        }

        if (count ==2) return true;

    }

    return false;
}

bool Poker::isTwoPairs(vector<string> cards) {
    int i,j;
    int pair = 0;
    for (i = 0; i < cards.size()-1; ++i) {
        int count = 1;
        for (j = i+1; j < cards.size(); ++j) {
            if (cards[i][0] == cards[j][0]){
                count++;
            }
        }
        if (count==2){
            pair++;
        }
    }

    return pair == 2;
}

bool Poker::isOnePair(vector<string> cards) {

    int i,j;
    int pair = 0;
    for (i = 0; i < cards.size()-1; ++i) {
        int count = 1;
        for (j = i+1; j < cards.size(); ++j) {
            if (cards[i][0] == cards[j][0]){
                count++;
            }
        }
        if (count==2){
            pair++;
        }
    }

    return pair == 1;
}

vector<vector<string> > Poker::getPlayerCards() {
    return playerCard;
}

vector<string> Poker::getTable() {
    return table;
}





