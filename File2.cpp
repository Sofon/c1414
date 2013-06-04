#include <iostream>
#include <ctime>
#include <conio.h>
void getMatrix( int **mat, int n, int m )
{
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < m; ++j )
        {
            std::cout << "Matrix [ " << i + 1 << " ; " << j + 1 << " ] = ";
            std::cin >> mat[ i ][ j ];
        }
}

void print( int **mat, int n, int m )
{
    std::cout << "Matrix:" << std::endl;
    for( int i = 0; i < n; ++i )
    {
        for( int j = 0; j < m; ++j )
            std::cout << mat[ i ][ j ] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void operation( int **mat, int n, int m )
{
    bool negativeFlag = true;
    for( int i = 1; i < n; ++i )
        for( int j = 0; j < i; ++j )
            if ( mat[ i ][ j ] < 0 ) negativeFlag = false;

    if ( negativeFlag )
    {
        for( int i = 1; i < n; ++i )
            for( int j = 0; j < i; ++j )
                mat[ i ][ j ] *= mat[ i ][ i ];
    }
}

int main()
{
    int n, m;

    do
    {
        std::cout << "Enter n and m: ";
        std::cin >> n >> m;
    }
    while ( n > m );

    int **matrix = new int *[ n ];
    for( int i = 0; i < n; ++i )
        matrix[ i ] = new int [ m ];

    getMatrix( matrix, n, m );
    print( matrix, n, m );
    operation( matrix, n, m );
    print( matrix, n, m );

    for( int i = 0; i < n; ++i )
        delete []matrix[ i ];
    delete []matrix;
    getch();
	return 0;
}
