/* utPod_driver.cpp
 * Driver for the UtPod.

Roger Priebe
EE 312 10/16/18


*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

//tests
    void defaultTest();
    void addAnddeleteSongsTest();
    void shuffleTimeTest();
    void memoryTests();
    void equalTest();



int main(int argc, char *argv[]){
   
     addAnddeleteSongsTest();
     memoryTests();
     shuffleTimeTest();
     equalTest(); 
     defaultTest();

}

//tests if two songs are the same
void equalTest(){
    UtPod t;
   
    Song s1("Kaye Ballard", "Fly Me to the Moon", 9);
    Song s2("Kaye Ballard", "Fly Me to the Moon", 9);
    Song s3("Toto", "Africa", 8);

    t.addSong(s1);
    t.addSong(s2);

    t.showSongList();
  
    if(s1 == s2){
       cout << s1 << " And " << s2 << " are the same " << endl;
    } else { 
          cout << s1 << " And " << s2 << " are not the same " << endl;
    }

  
    if(s3 == s2){
       cout << s3 << " And " << s2 << " are the same " << endl;
    } else { 
          cout << s3 << " And " << s2 << " are not the same " << endl;
    }
  
}

//tests clearMemory(), addSong(), getTotalMemory()
void memoryTests(){

    //test for over max memory   
    UtPod r(600);
    cout << "Created New UtPod r" << endl;
    cout << "Total Memory is: " << r.getTotalMemory() << endl;
    r.clearMemory();

    //test for under minimum memory
    UtPod s(-1);
    cout << "Created New UtPod s" << endl;
    cout << "Total Memory is: " << s.getTotalMemory() << endl;
    r.clearMemory();

    //test if can create arbitrary UtPod size;
    UtPod t(400);
    cout << "Created New UtPod t" << endl;
    cout << "Total Memory is: " << t.getTotalMemory() << endl;
    
    Song s1("Jefferson Starship", "We Built This City", 32);
    Song s2("Toto", "Africa", 8);
    Song s3("Kaye Ballard", "Fly Me to the Moon", 9);
    Song s4("Claude Debussy", "Clair de Lune", 5);
    Song s5("Paul Anka", "Put Your Head on My Shoulder but it's playing in another room (1 Hour version)", 200);
    Song s6("Taylor Swift", "You Need to Calm Down", 65);


    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);
    t.addSong(s6);

    cout << "UtPod t's List is:" << endl;
    t.showSongList();
 
    t.clearMemory();
    cout << "Memory is Cleared" << endl;
    cout << "Remaining memory is: " << t.getRemainingMemory() << endl;

}

void shuffleTimeTest(){

    UtPod t;
 
    cout << endl;

    //shuffle empty list
    cout << "\nShuffling no songs in list..." << endl;
    t.shuffle();
    t.showSongList();
    
    Song s1("Jefferson Starship", "We Built This City", 32);
    Song s2("Toto", "Africa", 8);
    Song s3("Kaye Ballard", "Fly Me to the Moon", 9);
    Song s4("Claude Debussy", "Clair de Lune", 5);
    Song s5("Paul Anka", "Put Your Head on My Shoulder but it's playing in another room (1 Hour version)", 200);
    Song s6("Taylor Swift", "You Need to Calm Down", 65);
  

    //shuffle only one song in list
    t.addSong(s1);
    cout << "Added --- " << s1 << endl;

    t.showSongList();
    cout << "\nShuffling when only one song in list..." << endl << endl;
    t.showSongList();
  
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);
    t.addSong(s6);
 
    cout << "\nSong list: " << endl << endl;
    t.showSongList();

    cout << "\nshuffling..." << endl << endl;
  
    t.shuffle();

    t.showSongList();


}

//adds songs to UtPod then deletes all of them
void addAnddeleteSongsTest(){

    UtPod t;
    cout << "Start Adding Songs" << endl; 
 
    Song s1("Jefferson Starship", "We Built This City", 32);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
 
      
    Song s2("Toto", "Africa", 8);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
       
    Song s3("Kaye Ballard", "Fly Me to the Moon", 9);
    result = t.addSong(s3);
    cout << "result = " << result << endl;


    Song s4("Claude Debussy", "Clair de Lune", 5);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
    
    
    Song s5("Paul Anka", "Put Your Head on My Shoulder but it's playing in another room (1 Hour version)", 200);
    result = t.addSong(s5);
    cout << "result = " << result << endl;


    //test for too much space
    Song s6("Taylor Swift", "You Need to Calm Down", 400);
    result = t.addSong(s6);
    cout << "result = " << result << endl;

    
    t.showSongList();
    cout << endl << "Start Deleting" << endl;


    //delete head pointer song, "Put Your Head on My Shoulder but it's playing in another room (1 Hour version)"
    result = t.removeSong(s5);
    cout << "delete " << s5 << endl;

    cout << endl;
    t.showSongList();

    cout << endl;

    //remove song that isn't in list
    result = t.removeSong(s6);
    cout << "delete " << s6 << endl;

    cout << endl;
    t.showSongList();
    cout << endl;
    
    //remove "Africa"
    result = t.removeSong(s2);
    cout << "delete " << s2 << endl;

    cout << endl;
    t.showSongList();
    cout << endl;
    

    //remove "We Built this City"
    result = t.removeSong(s1);
    cout << "delete  " << s1 << endl;


    cout << endl;
    t.showSongList();
    cout << endl;
   
    //remove "Clair de Lune"
    result = t.removeSong(s4);
    cout << "delete " << s4 << endl;


    cout << endl;
    t.showSongList();
    cout << endl;

    //remove only song in list, "Fly Me to the Moon"
    result = t.removeSong(s3);
    cout << "delete " << s3 << endl;
 
    //should print nothing 
    cout << endl;
    t.showSongList();


}


//given driver for UtPod
void defaultTest(){

    UtPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
 
    t.showSongList();

      
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

  
    t.showSongList();
    
    result = t.removeSong(s3);

    cout << "delete result = " << result << endl;
    t.showSongList();
   
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;



 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
  
}

