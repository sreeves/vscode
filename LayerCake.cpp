/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Definitions of class LayerCake. Constructor for LayerCake instances and Functions "ToString" and "DiscountedPrice".
Done without pair programming and in Visual Studio.
Late Days: none
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "LayerCake.h"
   
LayerCake::LayerCake(string flavor, string frosting, int numLayers) : Cake(flavor, frosting) {
   ostringstream ostream;
   
   this->numLayers = numLayers;

   price = LAYERCAKEPRICE;
   if(frosting == "cream-cheese") {
      price = LAYERCAKEPRICE + (1.00 * numLayers);
   }
   if(numLayers > 1) {
      price = price + (3.00 * (numLayers - 1));
   }

   ostream << numLayers << "-layer " << flavor << " cake with " << frosting;
   ostream << "frosting " << BakedGood::ToString(); //CALL TO BASE CLASS
   description = ostream.str();
}

string LayerCake::ToString() const {
   return description;
}

double LayerCake::DiscountedPrice(int numGoods) {
   double discountedPrice;
   const int DISCOUNTNUM = 3;
   const double DISCOUNTPRICE = 2.00;

   if(numGoods >= DISCOUNTNUM) {
      discountedPrice = numGoods * (price - DISCOUNTPRICE);
   }
   else {
      discountedPrice = numGoods * price;
   }
   return discountedPrice;
}