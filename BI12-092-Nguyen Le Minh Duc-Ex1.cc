#include <iostream>
#define size_x 19
#define size_y 22
#define size_z 23
#define kbits 10

int majB(int x, int y, int z);

int main()
{
    int x[size_x] = {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    int y[size_y] = {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    int z[size_z] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};

    int i, j = 0;
    int m;

    for (i = 0; i < kbits; i++)
    {
        m = majB(x[8], y[10], z[10]);
        
        if (x[8] = m)
        {
            int a = x[13] ^ x[16] ^ x[17] ^ x[18];
            for (j = size_x - 1; j >= 0; j--)
            {
                if (j == 0)
                {
                    x[j] = a;
                } else {
                    x[j] = x[j-1];
                }
            }
        }

        if (y[10] == m)
        {
            int a = y[20] ^ y[21];
            for (j = size_y - 1; j >= 0; j--)
            {
                if (j == 0)
                {
                    y[j] = a;
                } else {
                    y[j] = y[j-1];
                }
            }
        }

        if (z[10] == m)
        {
            int a = z[7] ^ z[20] ^ z[21] ^ z[22];
            for (j = size_z - 1; j >= 0; j--)
            {
                if (j == 0)
                {
                    z[j] = a;
                } else {
                    z[j] = z[j-1];
                }
            }
        }

        if (i < kbits)
        {
            printf("\nKeystream Bit = %d", x[size_x - 1] ^ y[size_y - 1] ^ z[size_z - 1]);
            printf("\n\n");
        }

        printf("\nX: ");
        for (j = 0; j < size_x; j++)
        {
            printf("%d", x[j]);
        }
        printf("\nY: ");
        for (j = 0; j < size_y; j++)
        {
            printf("%d", y[j]);
        }
        printf("\nZ: ");
        for (j = 0; j < size_z; j++)
        {
            printf("%d", z[j]);
        }
    }
}

int majB(int x, int y, int z)
{
    if (x == 0)
    {
        if (y == 0 || z == 0) { return 0; }
        else { return 1; }
    }
    else
    {
        if ( y == 1 || z == 1) { return 1;}
        else { return 0; }
    }

}