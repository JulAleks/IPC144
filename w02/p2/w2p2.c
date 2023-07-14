/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Julia Alekseev
Student ID#: 051292134
Email      : jalekseev@myseneca.ca
Section    : NGG

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
   const double TAX = 0.13;
   const char patSize = 'S', salSize = 'M', tomSize = 'L';

   double SML, MED, LRG;
   int QTY1, QTY2, QTY3;

   printf("Set Shirt Prices\n");
   printf("================\n");

   printf("Enter the price for a SMALL shirt: $");
   scanf("%lf", &SML);

   printf("Enter the price for a MEDIUM shirt: $");
   scanf("%lf", &MED);

   printf("Enter the price for a LARGE shirt: $");
   scanf("%lf", &LRG);

   printf("\nShirt Store Price List\n");
   printf("======================\n");
   printf("SMALL  : $%.2lf\n", SML);
   printf("MEDIUM : $%.2lf\n", MED);
   printf("LARGE  : $%.2lf\n\n", LRG);

   printf("Patty's shirt size is '%c'\n", patSize);
   printf("Number of shirts Patty is buying: ");
   scanf("%d", &QTY1);

   printf("\nTommy's shirt size is '%c'\n", tomSize);
   printf("Number of shirts Tommy is buying: ");
   scanf("%d", &QTY2);

   printf("\nSally's shirt size is '%c'\n", salSize);
   printf("Number of shirts Sally is buying: ");
   scanf("%d", &QTY3);

   printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
   printf("-------- ---- ----- --- --------- --------- ---------\n");

   double SUB = SML * QTY1;
   double TX = SUB * TAX;
   int subTx = (TX + 0.005) * 100;
   double totalPatty = (subTx / 100.0) + SUB;
   printf("Patty%5c %8.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, SML, QTY1,SUB, subTx / 100.0, totalPatty);

   double SUB3 = MED * QTY3;
   double TX3 = SUB3 * TAX;
   int subTx3 = (TX3 + 0.005) * 100;
   double totalSally = (subTx3 / 100.0) + SUB3;
   printf("Sally%5c %8.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, MED, QTY3, SUB3, subTx3 / 100.0, totalSally);
  
   double SUB2 = LRG * QTY2;
   double TX2 = SUB2 * TAX;
   int subTx2 = (TX2 + 0.005) * 100;
   double totalTom = (subTx2 / 100.0) + SUB2;
   printf("Tommy%5c %8.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, LRG, QTY2, SUB2, subTx2 / 100.0, totalTom);
   printf("-------- ---- ----- --- --------- --------- ---------\n");

   double finSub = SUB + SUB2 + SUB3;
   double finTx = subTx/100.0 + subTx2/100.0 + subTx3/100.0;
   double finTot = totalPatty + totalSally + totalTom;
   printf("%33.4lf %9.4lf %9.4lf\n\n", finSub, finTx, finTot); 
 
   printf("Daily retail sales represented by coins\n");
   printf("=======================================\n\n");
   printf("Sales EXCLUDING tax\n");
   printf("Coin     Qty   Balance\n");
   printf("-------- --- ---------\n");
   printf("%22.4lf", finSub);

   int toonMod = finSub * 100;
   int toonies = toonMod / 200;
   int remainToon = toonMod % 200;
   printf("\nToonies  %d %9.4lf\n", toonies, remainToon / 100.0);

   double loonSub = remainToon / 100.0;
   int loonMod = loonSub * 100;
   int loonies = loonMod / 100;
   int remainLoon = remainToon % 100;
   printf("Loonies    %d %9.4lf\n", loonies, remainLoon / 100.0);

   double quaSub = remainLoon / 100.0;
   int quaMod = quaSub * 100;
   int quarters = quaMod / 25;
   int remainQua = remainLoon % 25;
   printf("Quarters   %d %9.4lf\n", quarters, remainQua / 100.0);

   double dimSub = remainQua / 100.0;
   int dimMod = dimSub * 100;
   int dimes = dimMod / 10;
   int dimQua = remainQua % 10;
   printf("Dimes      %d %9.4lf\n", dimes, dimQua / 100.0);

   double nickSub = dimQua / 100.0;
   int nickMod = nickSub * 100;
   int nickels = nickMod / 5;
   int nickQua = nickMod % 5;
   printf("Nickels    %d %9.4lf\n", nickels, nickQua / 100.0);

   double penSub = nickQua / 100.0;
   int penMod = penSub * 100;
   int pen = penMod / 1;
   int penQua = nickQua % 1;
   printf("Pennies    %d %9.4lf\n\n", pen, penQua / 100.0);

   double averageShirt = finSub / (QTY1 + QTY2 + QTY3);
   printf("Average cost/shirt: $%0.4lf\n\n", averageShirt);

   printf("Sales INCLUDING tax\n");
   printf("Coin     Qty   Balance\n");
   printf("-------- --- ---------\n");
   printf("%22.4lf", finTot);

   int toonMod2 = finTot * 100;
   int toonies2 = toonMod2 / 200;
   int remainToon2 = toonMod2 % 200;
   printf("\nToonies  %d %9.4lf\n", toonies2, remainToon2 / 100.0);

   double loonSub2 = remainToon2 / 100.0;
   int loonMod2 = loonSub2 * 100;
   int loonies2 = loonMod2 / 100;
   int remainLoon2 = remainToon2 % 100;
   printf("Loonies    %d %9.4lf\n", loonies2, remainLoon2 / 100.0);

   double quaSub2 = remainLoon2 / 100.0;
   int quaMod2 = quaSub2 * 100;
   int quarters2 = quaMod2 / 25;
   int remainQua2 = remainLoon2 % 25;
   printf("Quarters   %d %9.4lf\n", quarters2, remainQua2 / 100.0);

   double dimSub2 = remainQua2 / 100.0;
   int dimMod2 = dimSub2 * 100;
   int dimes2 = dimMod2 / 10;
   int dimQua2 = remainQua2 % 10;
   printf("Dimes      %d %9.4lf\n", dimes2, dimQua2 / 100.0);

   double nickSub2 = dimQua2 / 100.0;
   int nickMod2 = nickSub2 * 100;
   int nickels2 = nickMod2 / 5;
   int nickQua2 = dimQua2 % 5;
   printf("Nickels    %d %9.4lf\n", nickels2, nickQua2 / 100.0);

   double penSub2 = nickQua2 / 100.0;
   int penMod2 = penSub2 * 100;
   int pen2 = penMod2 / 1;
   int penQua2 = nickQua2 % 1;
   printf("Pennies    %d %9.4lf\n\n", pen2, penQua2 / 100.0);

   double averageShirt2 = finTot / (QTY1 + QTY2 + QTY3);
   printf("Average cost/shirt: $%0.4lf\n\n", averageShirt2);


    return 0;
}


