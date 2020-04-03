//DOCUMENT HERE

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Song.h"
#include "UtPod.h"

using namespace std;

      //Default constructor
      UtPod::UtPod(){
         memSize = MAX_MEMORY;
         songs = NULL;
      }

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod::UtPod(int size){
        if((size > MAX_MEMORY) || (size <= 0)){
            memSize = MAX_MEMORY;
            songs = NULL;
        } else{ 
            memSize = size;
            songs = NULL;
          } 
      }

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms -

       output parms -
      */

      int UtPod::addSong(Song const &s){ 

          //check if enough space 
          if((this->getRemainingMemory() - s.getSize()) <= 0){
              return NO_MEMORY;        
          } else {  //add song to list
               SongNode *entry = new SongNode;
               entry->next = songs;
               entry->s = s; 
               songs = entry;
               return SUCCESS;
          } 
          
      }

      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -2 if nothing is removed

         input parms -

         output parms -
      */

      int UtPod::removeSong(Song const &s){
               
               SongNode *ptr = songs; 
               SongNode *head = songs;
               SongNode *target = songs;
               SongNode *prev = songs;

               if(songs == NULL){ //empty list
                   return -1;
               }    
 
               if(head->s == s){ //head is what want to delete               
                   if(countSongs() == 1){ //only one element
                      songs = NULL;
                      delete target;
                      return SUCCESS;
                    } else {
                      songs = songs->next;
                      delete target;
                      return SUCCESS;
                    }
               
               } else { //rest of the cases 

                   while(ptr != NULL){
                      if(ptr->s == s){ //current node is match
                         
                          target = ptr;
                          
                          //create new link
                          if(ptr->next == NULL){ 
                              prev->next = NULL; 
                          } else {
                              prev->next = ptr->next;
                            }

                          delete target;

                          return SUCCESS;

                      }

                      prev = ptr;
                      ptr = ptr->next;

                   } 
              }

              return NOT_FOUND;

      } 

      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void UtPod::shuffle(){   

          unsigned int currentTime = (unsigned) time(0);

          int numSongs = countSongs();

          srand(currentTime); //seed rng
  
          if(numSongs <= 1){} //only one element or no elements
             else { 
                //will shuffle a random amount of times
                int randomNum; 
 
                while(randomNum<=0){ //randomNum = 0 means no shuffling will happen
                   randomNum = rand(); 
                   randomNum = randomNum % numSongs;
                }
 
               SongNode *ptr1;
               SongNode *ptr2;
 
               int roll = 0;
               int roll2 = 0;
 
               //rolls random numbers then swap those two contents
               for(int i = 0;i < randomNum; i++){

                  ptr1 = songs; 
                  ptr2 = songs; 
   
                  roll = rand() % numSongs;
                  roll2 = rand() % numSongs;
            
                  for(int j = 0;j<roll;j++){
                     if(ptr1->next == NULL) {
                        ptr1 = songs;
                     } 
                     ptr1 = ptr1->next;
                  }    
  
                  for(int k = 0;k<roll2;k++){
                     if(ptr2->next == NULL) {
                        ptr2 = songs;
                     } 
                     ptr2 = ptr2->next;
                  }    

                  ptr1->s.swap(ptr2->s);

               } 
         

             }

      }

      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms -

         output parms -
      */

      void UtPod::showSongList(){
            //check if list is empty
            if(songs == NULL){ 
               //print out empty line if list is empty 
               cout <<  endl;

            } else { //print out song list

               SongNode *ptr = songs;

               while( ptr != NULL){
                   cout << ptr->s.getTitle() << "," 
                        << ptr->s.getArtist() << "," 
                        << ptr->s.getSize() << endl;
                   ptr = ptr->next;
  
               }
            }


      }

      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      void UtPod::sortSongList(){

      }


      /* FUNCTION - int getTotalMemory
       *  returns the total amount of memory in the UtPod
          o will do nothing if there are less than two songs in the current list

         input parms -

         output parms -
      */

      int getTotalMemory() {
//         return memSize;
      }

      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms -

         output parms -
      */
      void UtPod::clearMemory(){
//go through list and delete one by one

         SongNode *ptr = songs;
         while(songs!= NULL){
               
            ptr = songs;    
            songs = songs->next;
            delete ptr;
                    
         }
      }


      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms -

         output parms -
      */

      int UtPod::getRemainingMemory(){

         SongNode *ptr = songs;

         int remainingMemory = memSize;
 
         while( ptr != NULL){
            remainingMemory = remainingMemory - (ptr->s.getSize());
            ptr = ptr->next;
         }
 
//cout << "\nGet remaining memory is " << remainingMemory << endl;  
         return remainingMemory;
      
      }


      //counts the number of songs in the list and returns the number of songs
      int UtPod::countSongs(){

         SongNode *ptr = songs;

         int count = 0;
 
         while(ptr != NULL){
            count++;
            ptr = ptr -> next;
         }
 
         return count;
      
      }

      //destructor for UtPod
      UtPod::~UtPod(){

            SongNode *ptr = songs;

            while(songs!= NULL){
               
               ptr = songs;    
               songs = songs->next;
               delete ptr;
                    
            }
  
     }

