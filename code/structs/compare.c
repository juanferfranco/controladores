    #include <stdio.h>
    
    struct Point {
        int x;
        int y;
    };
    
    int main()
    {
        struct Point p1 = {10, 20};
        struct Point p2 = p1; 
        printf(" p2.x = %d, p2.y = %d\n", p2.x, p2.y);

        if(p1 == p2){
            printf("p1 is equal to p2\n");
        }

        return 0;
    }