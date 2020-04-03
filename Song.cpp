
//DOCUMENT HERE

#include <cstdlib>
#include <string>
#include <iostream>

#include "Song.h"

using namespace std; 

//Private variables reminder
/*
    private:
    string artist;
    string title;
    int size;
*/
    Song::Song(){
       artist = "";
       title = "";
       size = NULL;  
    }

    Song::Song(string artist){
       this ->artist = artist;
       title = "";
       size = NULL;
    }

    //create new song containing 
    //artist name, title name and memory size;
    Song::Song(string _artist, string _title,int _size){ 
        artist = _artist;
        title = _title; 
        size = _size;
    }

    string Song::getArtist() const{
        return artist;
    }

    void Song::setArtist(string name){
        artist = name;
    }
 
   
    string Song::getTitle() const{
        return title;
    }

    void Song::setTitle(string name){
        title = name;
    }


    int Song::getSize() const{
       return size;
    }

    void Song::setSize(int songSize){
        this->size = songSize;
    }

    void Song::swap(Song &s2){
        Song temp = s2;
        s2 = *this;
        *this = temp;
    }

    bool Song::operator >(Song const &rhs){

     


    }

    bool Song::operator ==(Song const &rhs){

        return ((artist == rhs.artist) &&
                (title == rhs.title) &&
                (size == rhs.size));

    }

    ostream& operator << (ostream& out, const Song &s){
      out << "Artist:" <<  s.getArtist() << " Title:" << s.getTitle() << " Size:" << s.getSize();
      return out;
    }

    Song::~Song(){
    
    }


