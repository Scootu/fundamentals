#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string sample = "Hello world";
    cout << "Enter your text to be deployed " << endl ;
	//getline(cin,sample);
	clog << "An error occurred" << endl ; // or you can use cerr
	cout << sample << " - A computer science portal for geeks"<< endl ;
    signed short iVar = 32767; //2 bits this is maximum value can put in this data type 2^(n-1) -1 = 32767
    cout << iVar <<endl ;
    double dVal3 =.7e3; // 700
    cout <<dVal3<<endl;
    int iVal5 = 98652 ; //        11000000111101100 // 17 bits
    unsigned short age = iVal5; // 1000000110011100 it's cute the first 16 bits
    cout << age <<endl; // it's give 33116
    // the range of cout
    int iMax = 2147483647;
    cout <<(long long)iMax + (long long)iMax<<endl;
    cout <<M_E<<endl; // it's work without autocomplete
    cout <<INT_MAX<<endl ;
    cout<<ULONG_LONG_MAX<<endl; // 18446744073709551615 this is for 64 bits
    // we can use different libraries for storing larger numbers than this
    long double maxValue = numeric_limits<long double>::max();
    cout << "The largest value you can store in a long double is: " << maxValue << endl;
    // type promotion in c++ operations
    unsigned int uiNum = 30 ;
    int iNum = 20 ;
    cout << iNum - uiNum << endl ; // This is a runtime error and will don't get -10 because the type is unsigned int
    // but we can correct this
    cout << iNum - (int)uiNum <<endl;
    iNum = (uiNum =(uiNum + 1) + 1) ; // 32
    cout << iNum << endl ;
    //Increment / Decrement operators
    int C = 1 ;
    int y = C++;
    cout << y << C << endl; // 1 2
    C = 1 ;
    y = ++C ;
    cout << y << C <<endl; // 2 2
    // display summed numbers aligned
    cout<<"____________________"<<endl<<endl;
    cout <<setw(3)<<6<< endl  // but the 6 in the index 3
         <<setw(3)<<18<<endl
         <<setw(3)<<124<<endl
         <<"---\n"
         <<(6+18+124)<<endl;

    // setiosflags
    cout << "|"<< setw(20)<< setiosflags(ios::scientific)<< 1452.256 << endl ;
    cout <<fixed<<setprecision(3)<< 145.25447552<<endl;
    cout <<"Base oct "<<0x01000f<<endl; // this will convert to decimal
    string emailAddress = "", provider= "",domain = "";
    cout <<"Enter your email" <<endl ;
    getline(cin,emailAddress,'@');
    getline(cin,provider,'.');
    getline(cin,domain);
    cout << "your email address \n"
         << " Email Address : "<< emailAddress<<endl
         << " Provider : "<<provider<<endl
         << " domain : "<<domain<<endl;
    cout << "Enter either National security number or Full Name as your identifier \n" ;
    string line1;
    getline(cin,line1);
    istringstream iss1(line1);
    char ch = iss1.peek();
    if(!isdigit(ch)){
        cout << "It's a string.\n\n";
    }else {
        cout << "It's a number.\n\n";
    }
    int a = 11 ;
    bool bCompare = (a == 11.0) ;
    cout <<"11 == 11.0 : "<<bCompare<<endl;

	return 0;
}
