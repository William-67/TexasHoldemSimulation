#include <iostream>
#include <algorithm>
#include "Poker.h"
#include "TexasHoldem.h"


using namespace std;



void testSomething();
void testSwitch();
void testAll();
void testTexas();

int main() {

    testAll();
    testTexas();
//    testSomething();
//testSwitch()



    return 0;

}


void testSomething(){

    string a = "love";
    string b = "you";
    string c = a +b;

    string ranks[13] = {"2","3","4","5","6","7","8","9","T","J","Q","K","A"};
    string suits[4] =  {"D","C","S","H"};

    vector<string> deck;

    int i,j;
    for (i = 0; i < 13; ++i) {
        for (j = 0; j < 4; ++j) {
            string temp = ranks[i] + suits[j];
            deck.push_back(temp);

        }
    }

    random_shuffle(deck.begin(),deck.end());
    vector<string>::iterator vi;
    for (vi = deck.begin() ;vi != deck.end(); ++vi) {
        cout<<*vi<<endl;
    }

//    for (int k = 0; k < deck.size(); ++k) {
//        cout<<k<<endl;
//    }
}

void testSwitch(){
    char a = 'a';
    string b = "abort";
    switch (b[0]) {
        case 'a':
            cout<<"yes"<<endl;
            break;
    }
}

void testAll(){

//    cout<<"In my implementation, isFullHouse returns (isthreeofakind() && isTwoofaKind) "<<endl;
//    cout<<"Therefore if isFullhouse pass, the two rest function pass"<<endl;
//    cout<<"Same for isStraightFlush() "<<endl;
//    cout<<" "<<endl;

    Poker p;
    vector<string> v;
    vector<string> v1;

    v.push_back("TH");
    v.push_back("QH");
    v.push_back("JH");
    v.push_back("AH");
    v.push_back("KH");

    v1.push_back("6H");
    v1.push_back("7H");
    v1.push_back("9H");
    v1.push_back("7D");
    v1.push_back("jH");

    cout<<"----------Test is Flush----------"<<endl;
    if (p.isFlush(v)){
        cout<<"test 1 pass"<<endl;
    } else{
        cout<<"test 1 fail"<<endl;
    }
    if (!p.isFlush(v1)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }

    cout<<"----------Test is Straight----------"<<endl;
    if (p.isStraight(v)){
        cout<<"test 1 pass"<<endl;
    } else{
        cout<<"test 1 fail"<<endl;
    }
    if (!p.isStraight(v1)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }


    cout<<"----------Test is Straight Flush----------"<<endl;
    if (p.isStraightFlush(v)){
        cout<<"test 1 pass"<<endl;
    }else{
        cout<<"test 1 fail"<<endl;
    }

    if (!p.isStraightFlush(v1)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }



    v.clear();
    v1.clear();

    v.push_back("9H");
    v.push_back("6S");
    v.push_back("9D");
    v.push_back("9C");
    v.push_back("9S");

    v1.push_back("2H");
    v1.push_back("6S");
    v1.push_back("5H");
    v1.push_back("8C");
    v1.push_back("9S");

    cout<<"----------Test is FOur of a Kind----------"<<endl;
    if (p.isFourofaKind(v)){
        cout<<"test 1 pass"<<endl;
    }else{
        cout<<"test 1 fail"<<endl;
    }

    if (!p.isFourofaKind(v1)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }


    v.clear();
    v1.clear();

    v.push_back("JH");
    v.push_back("7S");
    v.push_back("7D");
    v.push_back("JD");
    v.push_back("JC");

    v1.push_back("2H");
    v1.push_back("6D");
    v1.push_back("5D");
    v1.push_back("8C");
    v1.push_back("8S");

    cout<<"----------Test is Full House----------"<<endl;

    if (p.isFullHouse(v)){
        cout<<"test 1 pass"<<endl;
    }else{
        cout<<"test 1 fail"<<endl;
    }

    if (!p.isFullHouse(v1)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }

    cout<<"----------Test is one pair----------"<<endl;

    if (p.isOnePair(v1)){
        cout<<"test 1 pass"<<endl;
    }else{
        cout<<"test 1 fail"<<endl;
    }

    if (!p.isOnePair(v)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }

    v.clear();
    v1.clear();

    v.push_back("TH");
    v.push_back("6S");
    v.push_back("TD");
    v.push_back("TC");
    v.push_back("QS");

    v1.push_back("2H");
    v1.push_back("6S");
    v1.push_back("KH");
    v1.push_back("8C");
    v1.push_back("QS");



    cout<<"----------Test is three of a kind----------"<<endl;

    if (p.isThreeofaKind(v)){
        cout<<"test 1 pass"<<endl;
    }else{
        cout<<"test 1 fail"<<endl;
    }

    if (!p.isThreeofaKind(v1)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }

    v.clear();
    v1.clear();

    v.push_back("TH");
    v.push_back("6S");
    v.push_back("AS");
    v.push_back("TC");
    v.push_back("6D");

    v1.push_back("2H");
    v1.push_back("6S");
    v1.push_back("9H");
    v1.push_back("8C");
    v1.push_back("QS");



    cout<<"----------Test is two pairs----------"<<endl;

    if (p.isTwoPairs(v)){
        cout<<"test 1 pass"<<endl;
    }else{
        cout<<"test 1 fail"<<endl;
    }

    if (!p.isTwoPairs(v1)){
        cout<<"test 2 pass"<<endl;
    }else{
        cout<<"test 2 fail"<<endl;
    }


    //test add_card;
    cout<<"----------Test add card----------"<<endl;
    p.add_card(0);
    p.add_card(0);

    vector<vector<string> > players = p.getPlayerCards();

    cout<<"player 0 has "<<players[0].size()<<" cards now"<<endl;
    cout<<"player 0 has "<<players[1].size()<<" cards now"<<endl;

    cout<<"----------Test add_to_table----------"<<endl;
    p.add_to_table();
    p.add_to_table();
    p.add_to_table();

    vector<string> table = p.getTable();
    vector<string> :: iterator tableIt;
    for (tableIt = table.begin(); tableIt !=table.end() ; ++tableIt) {
        cout<<*tableIt<<", ";
    }

}

void testTexas(){

    cout<<endl;
    cout<<"----------Test method in texas Holdem----------"<<endl;

    TexasHoldem texas = TexasHoldem();

    texas.deal();

    vector<string> table = texas.getTable();

    cout<<"Table card:"<<endl;
    vector<string> :: iterator tableIt;
    for (tableIt = table.begin(); tableIt !=table.end() ; ++tableIt) {
        cout<<*tableIt<<", ";
    }

    cout<<endl;

    cout<<"Cards in two players hands are"<<endl;
    vector<vector<string> > players = texas.getPlayerCards();
    vector<string> player1 = players[0];
    vector<string> player2 = players[1];

    cout<<"player1's cards: "<<endl;
    for (tableIt = player1.begin(); tableIt !=player1.end() ; ++tableIt) {
        cout<<*tableIt<<", ";
    }
    cout<<endl;

    cout<<"player2's cards: "<<endl;
    for (tableIt = player2.begin(); tableIt !=player2.end() ; ++tableIt) {
        cout<<*tableIt<<", ";
    }
    cout<<endl;



    vector<string> bestCard = texas.hands();

    cout<<endl;
    for (tableIt = bestCard.begin(); tableIt !=bestCard.end() ; ++tableIt) {
        cout<<*tableIt<<", ";
    }

}