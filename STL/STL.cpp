#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <set>
#include <map>
#define all(v)    ((v).begin()),((v).end())
#define sz(v)     ((int)((v).size()))
#define pi        3.14

using namespace std;


template <class Type, class Container = deque<Type> > class stack;

typedef vector<int> vi;
void printVec(vector<int> v2, string s = "")
{
    cout<<s;
    for (int i = 0; i < (int)v2.size(); ++i)
        cout<<v2[i]<<" ";
    cout<<"\n";
}

int myFunc(int x,int y)
{
    return x + 2*y;
}
// Print the queue
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}

void showdq(deque<int> g)
{
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
void showSq(std::stack<int> s)
{
    while (!s.empty())
    {
        std::cout << "\t" << s.top();
        s.pop();
    }
    std::cout << '\n';
}
bool sortPair(const pair<int,char> &a,const pair<int,char> &b)
{
    return a.first < b.first ;
}
int main()
{
    vi v(10);	 							// Initialize 10 elements with zero
    vi v1(10, 7);							// Initialize 10 elements with 7

    // What about vector from array
    const int lenght = 6;
    int array[lenght] = {5, 2, 7, 2, 0, 2};
    vi v2(array, array+lenght);

    printVec(v2, "v2: ");

    cout<<"Front: "<<v2.front()<<" last element: "<<v2.back()<<"\n";
    // Vector from Vector
    vi v3(v1.begin(), v1.end());

    v3.resize(17);
    v3.push_back(7);
    printVec(v3, "v3: ");
    for(int i =0; i<(int)v3.size(); ++i)
        cout << v3[i]<<" ";
    cout<<endl;
    vi::iterator it = v3.begin();
    while(it != v3.end())
    {
        cout<<(*it)<<" ";
        ++it;
    }
    cout<<endl;
    //sort(startaddress, endaddress);
    int arr[] = {9,15,0,2,6,1};
    //ascending
    sort(begin(arr),end(arr));
    for (int i = 0; i < 6; ++i)
        cout << arr[i] << " ";
    cout <<endl;
    //decreasing
    sort(v2.begin(),v2.end(),greater<int>()); // let greater first
    printVec(v2,"v2 ");
    if(v1 < v2) // It's work the same as lexicographical comparison: '7' > '5' so v2 smaller than v1
    {
        cout << "v1 smaller than v2"<<endl;
    }
    else
    {
        cout << "v2 smaller than v1"<<endl;
    }
    v2.erase(v2.begin() + 1); // Remove the 2nd position
    printVec(v2,"erase 2nd :");

    v2.insert(v2.begin() + 3,14);
    printVec(v2,"insert 4th :");

    v2.push_back(72);
    printVec(v2,"push back :");
    if(find(all(v2),7) != v2.end())
        cout << "7 in v2!";
    cout <<endl;
    random_shuffle(all(v2)); // shuffle randomly array numbers
    printVec(v2,"v2 shuffle : ");

    v2.pop_back(); // remove last element in O(1)
    printVec(v2,"Last removed: ");

    replace(all(v2),2,4);
    printVec(v2,"v2: ");

    it = search(all(v2),all(v1)); // search for a vector
    if(it != v2.end())
        cout << "sub vector from index"<<it - v2.begin()<<"\n";
    // Binary Search functions in C++ STL (binary_search, lower_bound and upper_bound)
    //  binary_search(fptr,lptr,num) OLog(n)
    sort(v2.begin(),v2.end());
    printVec(v2,"v2 : ");

    it = lower_bound(v2.begin(),v2.end(),72); // >= 4
    cout <<"position of number 72 in v2 : "<<it - v2.begin()<<endl;

    it = upper_bound(v2.begin(),v2.end(),4); // <= 4 return the last position of the number
    cout <<"position of number 4 in v2 : "<<it - v2.begin()<<endl;

    vi v4 = v2;
    v4.resize(unique(all(v4)) - v4.begin());
    printVec(v4,"v4 : ");
    v1 = v2 ;
    printVec(v1,"v1 : ");
    v1.push_back(v1.back());
    v1.push_back(v1.back() + 20);
    v1.push_back(v1.back() + 7);
    printVec(v1,"v1 : ");
    vi vx;
    vi::iterator st;
    sort(all(v3));

    set_intersection(all(v2),all(v3),back_inserter(vx));
    printVec(vx,"set_intersection : ");
    vx.clear();

    set_difference(all(v2),all(v3),back_inserter(vx));
    printVec(vx,"set_difference : ");
    vx.clear();

    set_union(all(v2),all(v3),back_inserter(vx));
    printVec(vx,"set_union : ");
    vx.clear();
    ////////////////////////////////////////////////////////////////////////

    int mx = *max_element(all(v2));
    int mn = *min_element(all(v2));

    cout <<"Maximum: "<<mx<<" minimum "<<mn<<"\n";
    printVec(v1,"v1 : ");
    v2.resize(v1.size());
    printVec(v2,"v2 : ");
    int size1 = v1.size();
    int size2 = v2.size();

    swap_ranges(v1.begin(),v1.begin() + (v1.size() / 2),v2.begin() + (v2.size() / 2));

    printVec(v1,"v1 : ");
    printVec(v2,"v2 : ");
    int r1 = inner_product(all(v1),v2.begin(),0) ; // v1[0]*v2[0] + v2[0]*v3[0]
    cout<<"inner product "<< r1<<"\n";
    int r2 = inner_product(all(v2),v2.begin(),1,multiplies<int>(),plus<int>());
    cout <<"Product of sum "<<r2<<"\n";

    vi v7(v2.size(),0);
    partial_sum(v2.begin(),v2.end(),v7.begin());
    printVec(v7,"v7 : ");
    v7.clear();
    v7.resize(v2.size());
    partial_sum(all(v2),v7.begin(),minus<int>());
    printVec(v7,"v7 : ");

    partial_sum(all(v2),v7.begin(),myFunc); // v7[i-1] * v2[i]*2
    printVec(v7,"v7 : ");

    adjacent_difference(all(v2),v7.begin()); // see the code reference
    printVec(v7,"v7 : ");

    rotate(v2.begin(),v2.begin()+1,v2.end());

    // if you want a permutation to the array
    sort(all(v2));
    do
    {
        printVec(v2,"Perm : ");
    }
    while(next_permutation(all(v2))); // O(N*N!) until next_permutation finich lexociquecafically permutation and return false
    //Queues
    queue<int> gquiz;
    gquiz.push(10); // in the end
    gquiz.push(20);
    gquiz.push(30);

    cout << "The queue gquiz is : ";
    showq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);
    //Deque // double ended queues
    deque<int> dgquiz;
    dgquiz.push_back(10);
    dgquiz.push_front(20);
    dgquiz.push_back(30);
    dgquiz.push_front(15);//15 20 10 30

    cout << "The deque gquiz is : ";
    showdq(dgquiz);

    cout << "\ngquiz.size() : " << dgquiz.size();
    cout << "\ngquiz.max_size() : " << dgquiz.max_size(); //2305843009213693951

    cout << "\ngquiz.at(2) : " << dgquiz.at(2);
    cout << "\ngquiz.front() : " << dgquiz.front();
    cout << "\ngquiz.back() : " << dgquiz.back();

    cout << "\ngquiz.pop_front() : ";
    dgquiz.pop_front();
    showdq(dgquiz);

    cout << "\ngquiz.pop_back() : ";
    dgquiz.pop_back();
    showdq(dgquiz);
    //Stack // Last in first out (LIFO) the last element add to the stack is the first element
    std::stack<int> sk;

    // Push some elements onto the stack
    sk.push(1);
    sk.push(2);
    sk.push(3);
    sk.push(4);
    sk.push(5);

    // Display the elements of the stack
    cout << "Stack elements are:";
    showSq(sk);

    // Pair
    pair<int,double> p1 = make_pair(15,15.264);
    pair<string,pair<int,double>> p2 = make_pair("mostafa",p1);

    cout<<"p1.first : "<<p1.first<<endl;
    cout <<"p2.second.second : "<< p2.second.second<<endl;

    vector<pair<int,char>> vp;
    vp.push_back(make_pair(1,'a'));
    vp.push_back(make_pair(2,'b'));
    vp.push_back(make_pair(0,'#'));

    sort(all(vp),sortPair);

    for(int i =0; i < vp.size();++i) {
        cout <<"f : "<<vp[i].first<<" s : "<<vp[i].second<<"\n";
    }
    ///////////////////////////////////////
    //Set
    set<string> strset;

    strset.insert("mostafa");
    strset.insert("ali");
    //search in set
     // count return the number of occurrence in an list
    if(strset.count("mostafa")){
        cout << "Mostafa in the set \n";
    }
    //Map
    map<string,int> mp;
    mp["one"] = 10;
    mp["two"] = 20;
    mp["mostafa"] = 30 ;
    mp["ali"] = 45 ; //Sorted
    //How to iterate over a map
    //Convert a map to vector of pairs
    vector<pair<string,int>> mpovc(all(mp));
     for(int i =0; i <(int)mpovc.size();++i) {
        cout <<mpovc[i].first<<" : "<<mpovc[i].second<<"\n";
    }
    //String basics tests
    //String stream
    return 0 ;
}
