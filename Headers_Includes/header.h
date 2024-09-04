#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

int factorial(int n);   // declaration

int factorial(int n)
{
    int ret = 1 ;

    for (int i = 1 ; i <= n; ++i)
         ret = ret * i;
    return ret ;
}



#endif // HEADER_H_INCLUDED
