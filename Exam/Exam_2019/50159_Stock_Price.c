#include <stdio.h>
#include <stdbool.h>
 
int main()
{
  int first, second;
  if (scanf("%d%d", &first, &second) != 2) {
    printf("0\n");
    return 0;
  }
  bool up = second > first;
 
  int maxLength = 0, maxLeft = 0, maxStart;
  int index = 3;
  int prev = second, prevLength = 0, prevStart;
  int curr, currLength = 2, currStart = 1;
  while (scanf("%d", &curr) != EOF) {
    if (up? curr > prev : prev > curr)
      currLength++;
    else {
      prevLength = currLength;
      currLength = 2;
      prevStart = currStart;
      currStart = index - 1;
      up = !up;
    }
    if (prevLength > 0 &&
    ((currLength + prevLength - 1 > maxLength) ||
     ((currLength + prevLength - 1 == maxLength) &&
      (prevLength > maxLeft)))) {
      maxLength = currLength + prevLength - 1;
      maxLeft = prevLength;
      maxStart = prevStart;
    }
#ifdef DEBUG
    printf("%d %d %d %d %d %d\n", index, curr, currStart, currLength,
       prevStart, prevLength);
#endif
    prev = curr;
    index++;
  }
  if (maxLength == 0)
    printf("0\n");
  else
    printf("%d %d\n", maxLength, maxStart);
}