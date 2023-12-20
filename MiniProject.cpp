#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> movies;

vector<string> timings;

class Movie {
private:
    string movieName;
    float rating;
    string additionalInfo;

public:
    string getName() const {
        return movieName;
    }

    void setName(const string& newMovie) {
        movieName = newMovie;
    }

    float getRating() const {
        return rating;
    }

    void setRating(float newRating) {
        if (newRating >= 0.0 && newRating <= 10.0) {
            rating = newRating;
        } else {
            cout << "Invalid rating value. Rating should be between 0.0 and 10.0." << endl;
        }
    }

    string getAdditionalInfo() const {
        return additionalInfo;
    }

    void setAdditionalInfo(const string& info) {
        additionalInfo = info;
    }
};

class Admin {
private:
    const string adminPasswd = "123456789";
    vector<string> adminIdList;
    void addAdminId() {
        adminIdList.push_back("kunalvesit123");
         adminIdList.push_back("vinitvesit123");
    }

public:
    const string& getAdminPasswd() const {
        return adminPasswd;
    }

    const vector<string>& getAdminIdList() const {
        return adminIdList;
    }

  bool login() {
    string adminId;
    cout << "Enter admin username ";
    cin >> adminId;

    string adminpwd;
    cout << "Enter admin password ";
    cin >> adminpwd;

    bool valid = false;
    for (const string& admin : adminIdList) {
        if (admin == adminId) {
            valid = true;
            break;
        }
    }


    return valid && adminId == adminpwd;
}


    void SetMoviesAvail(int NoOfShows, unordered_map<string, vector<string>>& MoviMapping) {
        cout << "Enter the number of movies available for today: ";
        for (int i = 0; i < NoOfShows; i++) {
            string movie;
            cout << "Enter movie name: ";
            cin >> movie;
            movies.push_back(movie);
        }

        for (const auto& movie : movies) {
			

            cout << "Enter timings for " << movie << " (yr:month:day:hrs:min) :- ";
            string timing;
            cin >> timing;
            timings.push_back(timing);
        }

        
        for (int i = 0; i < movies.size(); i++) {
            MoviMapping[movies[i]].push_back(timings[i]);
        }

        cout << "Movies and timings set successfully." << endl;
    }

    void AddMovieInfo(unordered_map<string, vector<string>>& MoviMapping) {
        string movieName;
        cout << "Enter the movie name to add more info about it : ";
        cin >> movieName;

        if (MoviMapping.find(movieName) != MoviMapping.end()) {
            cout << "Enter additional information for " << movieName << ": ";
            string additionalInfo;
            cin.ignore(); 
            getline(cin, additionalInfo);

    
            MoviMapping[movieName].push_back(additionalInfo);

            cout << " information added successfully." << endl;
        } else {
            cout << "This movie isn't listed, add it first." << endl;
        }
    }
};

//f
class Customerdisplay{
public:
void ShowTimings(int movieNo, unordered_map<string, vector<string>> &MoviMapping ) {
    if (movieNo >= 0 && movieNo < movies.size()) {
        cout << "Timings for " << movies[movieNo] << " :- " << endl;
        const vector<string>& timings = MoviMapping[movies[movieNo]];

        for (int i = 0; i < timings.size(); ++i) {
            cout << "Show " << i + 1 << ":-" << timings[i] << endl;
        }
    } else {
        cout << "Invalid movie number." << endl;
    }
}

void showAdditionalInfo(int movieNo,unordered_map<string, vector<string>> &MoviMapping) {
    if (movieNo >= 0 && movieNo < movies.size()) {
        cout << "Additional information for " << movies[movieNo] << ":" << endl;
         vector<string>& additionalInfoList = MoviMapping[movies[movieNo]];

        for ( string& info : additionalInfoList) {
            cout << info << endl;
        }
    } else {
        cout << "Invalid movie number." << endl;
    }
}
  




};
/*  

pending....

class Book: protected Admin{

void ShowSetMatrix(){
        for(int i=0;i<x;i++){
            cout<<"_ _ _ _ _ "<<endl;
            for(int j=0;j<y;j++){
            cout<<Box[i][j];
            }
            cout<<"_ _ _ _ _ "<<endl;
        }
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

*/
int main() {
    unordered_map<string, vector<string>> MoviMapping;
    Admin admin;

    int choice1;
    do {
        cout << "1. Admin Login" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice1;

        switch (choice1) {
            case 1: {
                // Admin work...
                  
                Admin admin;
                if (admin.login()) {
                    int adminChoices;
                    cout << "Admin Logged in Successfully..." << endl;
                    cout << "=====================================" << endl;
                    cout << "ADMIN MENU" << endl;
                    cout << "1. Set Movies" << endl;
                    cout << "2. Add Movie Information" << endl;
                    cout << "3. Exit" << endl;
                    cout << "Choose an option: ";
                    cin >> adminChoices;
                    switch (adminChoices) {
                        case 1:
                        
                            int NoOfShows;
                            cout << "Enter the number of shows for each movie: ";
                            cin >> NoOfShows;
                            admin.SetMoviesAvail(NoOfShows, MoviMapping);
                            break;
                        case 2:
                            admin.AddMovieInfo(MoviMapping);
                            break;
                        case 3:
                            cout << "Exiting Admin Menu..." << endl;
                            break;
                        default:
                            cout << "Invalid option. Try again." << endl;
                            break;
                    }
                } else {
                    cout << "Admin Login Failed" << endl << "Security issue" << endl;
                }
                break;
            }
              
            
            case 2: {
                Customerdisplay customer;
                // Customer work...
                int CustChoice;
                cout << "Customer MENU" << endl;
                cout << "1. Show Movies and Timings" << endl;
                cout << "2. Show Information about Available Movies" << endl;
                cout << "3. Book a Ticket for Movies" << endl;
                cout << "Choose an option: ";
                cin >> CustChoice;
                switch (CustChoice) {
                    case 1:
                     int movieNo;
                        cout << "Enter Movie Number: ";
                        cin >> movieNo;
                        customer.ShowTimings(movieNo,MoviMapping);
                        break;
                    case 2:
                    int no;
                        cout << "Enter Movie Number: ";
                        cin >> no;
                        customer.showAdditionalInfo(no, MoviMapping);
                        break;
                    case 3:
                        cout << "Book a Ticket (Not implemented yet)" << endl;
                        break;
                    default:
                        cout << "Invalid option. Try again." << endl;
                        break;
                }
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    } while (choice1 != 3);

    return 0;
}
