//
// Created by william on 2022-11-30.
//

#include "TexasHoldem.h"
#include <algorithm>
#include <iostream>

using namespace std;

TexasHoldem::TexasHoldem() {

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

TexasHoldem::TexasHoldem(int a) {

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

void TexasHoldem::deal() {

    if (deck.size()< 2 * num + 5){
        cout<<"Not enough card to deal"<<endl;
        return;
    }

    for (int i = 0; i < num; ++i) {
        add_card(i);
        add_card(i);
    }

    for (int i = 0; i < 5; ++i) {
        add_to_table();
    }

}

vector<string> TexasHoldem::hands() {

    vector<string> result;

    for (int i = 0; i <num; ++i) {

        vector<string> temp;//place all cards on the table and in the hand of the player into this vector
        temp.insert(temp.end(),playerCard[i].begin(),playerCard[i].end());
        temp.insert(temp.end(),table.begin(),table.end());

        int j;

//        vector <string> cards;

        vector <int> select(7);
        select[0] = select[1] = 0;
        select[2] = select[3] = select[4] = select[5] = select[6] = 1;

        int status = 0;
        string resultString = "High card";

        do
        {
            int currentstatus = 0;

            vector <string> pick;
            for(j = 0; j < 7; ++j){
                if (select[j] == 1) pick.push_back(temp[j]);
            }

            string str;
            str = returnBestHands(pick,status);

            if (currentstatus<status){

                resultString = str;

            }

            currentstatus = status;

        }
        while(next_permutation(select.begin(), select.end()));

        result.push_back(resultString);

    }

    return result;
}

string TexasHoldem::returnBestHands(vector<string> temp,int& status) {

    string str= "High card";

    if (isStraightFlush(temp)){
        str = "Straight Flush";
        status = 1;
    }else if (isFourofaKind(temp)){
        str = "Four of a Kind";
        status = 2;
    }else if (isFullHouse(temp)){
        str = "Full House";
        status = 3;
    }else if (isFlush(temp)){
        str = "Flush";
        status = 4;
    }else if (isStraight(temp)){
        str = "Straight";
        status = 5;
    }else if (isThreeofaKind(temp)){
        str = "Three of a Kind";
        status = 6;
    }else if (isTwoofaKind(temp)){
        str = "Two pair";
        status = 7;
    }else if (isOnePair(temp)){
        str = "Pair";
        status = 8;
    }else{
        str = "High card";
        status = 0;
    }

    return str;

}

