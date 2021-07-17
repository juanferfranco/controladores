    #include <stdio.h>
    
    struct Point {
        int x;
        int y;
    };
    
    int main()
    {
        struct Point p1 = {10, 20};
        struct Point *pp1 = &p1;
        printf(" p1.x = %d, p1.y = %d\n", pp1->x, pp1->y);
        return 0;
    }