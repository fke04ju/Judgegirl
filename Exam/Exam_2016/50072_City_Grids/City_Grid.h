typedef struct City {
    int label;
    struct City *east, *north;
} City; 
 
int City_Grid(City *capital);