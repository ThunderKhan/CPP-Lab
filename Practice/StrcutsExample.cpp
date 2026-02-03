#include <iostream>
#include <string>

using namespace std;

struct VideoGames {
    string name;
    int yearReleased;
    float rating;
    string review;
};

int main() {
    VideoGames game1;
    VideoGames game2;

    game1.name = "GTA V";
    game1.yearReleased = 2018;
    game1.rating = 9.67;
    game1.review = "Josh Carman: 'Great game, good graphics, overall perfect!'";
    
    game2.name = "Red Dead Redemption";
    game2.yearReleased = 2002;
    game2.rating = 9.99;
    game2.review = "Alan Sitter: 'Great game, good graphics, overall perfect!'";

    cout << "First game: "<< game1.name << endl;
    cout << "Year Released: "<< game1.yearReleased << endl;
    cout << "Rating: "<< game1.rating << endl;
    cout << "Top review: "<< game1.review << "\n" << endl;
    
    cout << "Second game: "<< game2.name << endl;
    cout << "Year Released: "<< game2.yearReleased << endl;
    cout << "Rating: "<< game2.rating << endl;
    cout << "Top review: "<< game2.review << endl;

    return 0;
}