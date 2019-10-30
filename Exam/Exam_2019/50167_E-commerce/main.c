#include <stdio.h>
#include "payment.h"
#define MAXN 20000
 
int main(int argc, char const *argv[])
{
  int itemID[MAXN+1], orderItemID[MAXN+1], orderQuantity[MAXN+1], onSaleItemID[MAXN+1];
  double price[MAXN+1];
  int itemCnt, orderCnt, onSaleCnt;
  scanf("%d%d%d", &itemCnt, &orderCnt, &onSaleCnt);
 
  for(int i = 0; i < itemCnt; i++) {
    scanf("%d%lf", &itemID[i], &price[i]);
  }
  itemID[itemCnt] = 0, price[itemCnt] = 0;
 
  for(int i = 0; i < orderCnt; i++) {
    scanf("%d%d", &orderItemID[i], &orderQuantity[i]);
  }
  orderItemID[orderCnt] = 0, orderQuantity[orderCnt] = 0;
 
  for(int i = 0; i < onSaleCnt; i++) {
    scanf("%d", &onSaleItemID[i]);
  }
  onSaleItemID[onSaleCnt] = 0;
 
  double pay = payment(itemID, price, orderItemID, orderQuantity, onSaleItemID);
  printf("%.1lf\n", pay);
 
  return 0;
}