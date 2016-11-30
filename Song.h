#ifndef  SONG_H
#define SONG_H
#include <string>
using  namespace std;

class Song
{
private:	
	//Attributes
	string title;
	string artist;
	int playTime;//calculated as seconds
public:
	Song(string title="?", string artist="?", int playTime=0);				
	virtual ~Song();
	
	//set functions
	void setTitle(string title);
	void setArtist(string artist);
	void setPlayTime(int playTime);
	
	//get functions
	string getTitle() const;
	string getArtist() const;
	int getPlayTime() const;
    
	//operators implements
	bool operator == (const Song & compareSong)const;					
	bool operator != (const Song & compareSong)const;
	
	virtual string toString() const;//show informations as one string
	
};
#endif // ! SONG_H

