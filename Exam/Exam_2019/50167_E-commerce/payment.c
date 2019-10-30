double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]){
    double sum = 0;
    int item_id = -1,order_cnt = -1,onsale_cnt = -1;
    for(int i = 0;i<20000;i++){
        if(item_id != -1 && order_cnt != -1 && onsale_cnt != -1){
            break;
        }
        if(itemID[i] == 0){
            item_id = i;
        }
        if(orderItemID[i] == 0){
            order_cnt = i;
        }
        if(onSaleItemID[i] == 0){
            onsale_cnt = i;
        }
    }
    for(int i = 0;i<order_cnt;i++){
        for(int j = 0;j<item_id;j++){
            if(orderItemID[i] == itemID[j]){
                int ifonsale = 0;
                for(int k = 0;k<onsale_cnt;k++){
                    if(onSaleItemID[k] == itemID[j]){
                        ifonsale = 1;
                        break;
                    }
                }
                if(ifonsale == 0){
                    sum += (price[j] * (orderQuantity[i]));
                }else{
                    sum += (price[j] * (orderQuantity[i]))*0.8;
                }
                break;
            }
        }
    }
    if(sum < 490.00){
        sum += 80;
    }
    return sum;
}