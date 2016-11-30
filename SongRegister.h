#ifndef SONGREGISTER_H
#define SONGREGISTER_H
#include"Song.h"

class SongRegister:public Song
{
private:
	int nrOfSongs;
	int capacity;
	Song* *songs;

	void expend();//expend function
	void freeMemory();

public:
	SongRegister(int capacity = 5);	//constructor
	SongRegister(const SongRegister& origin);//copy constructor
	virtual ~SongRegister();//destructor
	void operator=(const SongRegister& origin);//assignmeny operator

	bool addSongs(string title, string artist, int playTime);//functions
	int getNrOfSongs() const;
	bool titleOfAllSongsWithOneArtists(string artist,string strArray[],int strCapacity) const;
	string songHasLongestTime() const;
	string songHasShortestTime() const;
	bool removeAsong(string title, string artist, int playTime);
	int getTotalPlayTime() const;

	string toString() const;


};
#endif // !SONGREGISTER_H

