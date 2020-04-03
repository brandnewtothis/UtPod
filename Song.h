
//DOCUMENT HERE


#ifndef Song_H
#define Song_H

#include <string>
#include <istream>


using namespace std; 

//Song class declaration
class Song
{
   private:
    string artist;
    string title;
    int size;
   
   public:
    Song();
    Song(string artist);
    Song(string artist, string title,int size);    

    string getArtist() const;
    void setArtist(string name); 

    string getTitle() const;
    void setTitle(string name); 
    
    int getSize() const;
    void setSize(int songSize);   


    void swap(Song &s);

    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);
 
    ~Song();

};

ostream& operator << (ostream& out,const Song &s);

#endif
