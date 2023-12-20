#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include<limits.h>
using namespace std;
vector<string> movies;
vector<double> timings;
static int total;
class Admin{
    public:
    void Set(){
    for (int i = 0; i < 5; i++)
    {
        string movie;
        cin >> (movie);
        movies.push_back(movie);
        cout << endl;
    }
    cout<<"Movies Available:"<<endl;
    cout<<"___________________"<<endl;
    for (int i = 0; i < movies.size(); i++)
    {
        cout << i + 1 << "." << movies[i] << endl;
    }
    cout<<"___________________"<<endl;
    int NoOfShows=4;
    for(int i=0;i<NoOfShows;i++){ 
        cout<<"Timing For Show "<<i+1<<":"<<endl;
        double time;
        cin>>time;
        timings.push_back(time);        
        cout << endl;
    }
    vector<int> Setprices(movies.size(), 0);
    cout << "Set Movie Prices:" << endl;
    for (int i = 0; i < Setprices.size(); i++)
    {
        cout<<"\n";
        int p;
        cin >> p;
        if(!(p>=INT_MAX&&p<=INT_MIN))
        continue;
        cout << "Price for " << movies[i] << ":" ;
        Setprices.push_back(p);
    }
    }
};
class Book: protected Admin
{
public:
    int x, y;
    vector<vector<char>> Box;
    void SetRowsAndCols(int m, int n)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Box[i][j] = '_';
            }
        }
    }
    void ShowSetMatrix(){
        for(int i=0;i<x;i++){
            cout<<"_ _ _ _ _ "<<endl;
            for(int j=0;j<y;j++){
            cout<<Box[i][j];
            }
            cout<<"_ _ _ _ _ "<<endl;
        }
    }
    void ShowTimings(int movieNo){

    }
    Book()
    {
        // int n,m;
        // cout<<"Enter Row:"<<endl;
        // cin>>n;
        // cout<<"\nEnter Cols:"<<endl;
        // cin>>m;
        // this->x=n;
        // this->y=m;
        // Box[x][y]=1;
    }
};
int main()
{
    Admin a1;
    a1.Set();
    //---------Admin Work Done Here!--------------//
    //MENU:
    cout<<"=================="<<endl;
    cout<<"MOVIE TICKET BOOKING MENU:"<<endl;
    cout<<"1.BOOK TICKETS"<<endl;
    cout<<"2.SHOW MOVIE TIMINGS"<<endl;
    cout<<"3.EXTRA SERVICES"<<endl;  
    Book a;
    a.ShowSetMatrix();
        int opt;
        cout << "Select Any One Movie";
        cout<<"(Press 6 to exit):"<<endl;
        cin >> opt;
        switch (opt + 1)
        {
        case 1:{};
            break;
        case 2:{};
            break;
        case 3:{};
            break;
        case 4:{};
            break;
        case 5:{};
            break;
        case 6:break;
        }
    // a.SetRowsAndCols(5,5);
    return 0;
}