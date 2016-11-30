#include "SongRegister.h"
#include <limits>

void SongRegister::expend()
{
	this->capacity += 5;
	Song* *temp = new Song*[this->capacity];
	for (int i = 0; i < this->nrOfSongs; i++)
	{
		temp[i] = this->songs[i];
	}
	delete[] this->songs;
	this->songs = temp;
	for (int i = nrOfSongs; i < this->capacity; i++)
	{
		this->songs[i] = nullptr;
	}
	
}

void SongRegister::freeMemory()
{
	for (int i = 0; i < this->nrOfSongs; i++)
	{
		delete this->songs[i];
	}
	delete[] this->songs;
}

SongRegister::SongRegister(int capacity)
{
	this->capacity = capacity;
	this->nrOfSongs = 0;
	this->songs = new Song*[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		this->songs[i] = nullptr;
	}
}

SongRegister::SongRegister(const SongRegister & origin)
{
	//shallow copy
	this->capacity = origin.capacity;
	this->nrOfSongs = origin.nrOfSongs;

	//deep copy
	this->songs = new Song*[this->capacity];
	for (int  i = 0; i <this->nrOfSongs; i++)
	{
		this->songs[i] = new Song(*origin.songs[i]);
	}
	for (int i = this->nrOfSongs; i < this->capacity; i++)
	{
		this->songs[i] = nullptr;
	}
}

SongRegister::~SongRegister()
{
	this->freeMemory();
}

void SongRegister::operator=(const SongRegister & origin)
{
	if (this!=&origin)
	{
		this->freeMemory();

		//shallow copy
		this->capacity = origin.capacity;
		this->nrOfSongs = origin.nrOfSongs;

		//deep copy
		this->songs = new Song*[this->capacity];
		for (int i = 0; i < this->nrOfSongs; i++)
		{
			this->songs[i] = new Song(*origin.songs[i]);
		}
		for (int i =this->nrOfSongs; i <this->capacity ; i++)
		{
			this->songs[i] = nullptr;
		}
	}
}

bool SongRegister::addSongs(string title, string artist, int playTime)
{
	bool exist = false;
	for (int i = 0; i < this->nrOfSongs; i++)
	{
		if (*this->songs[i]==Song(title,artist,playTime))
		{
			exist = true;
			break;
		}
	}
	if (exist == false)
	{
		if (this->nrOfSongs == this->capacity)
		{
			expend();
		}
		else
		{
			this->songs[this->nrOfSongs++] = new Song(title, artist, playTime);
		}
	}
	return !exist;
}

int SongRegister::getNrOfSongs() const
{
	return this->nrOfSongs;
}

bool SongRegister::titleOfAllSongsWithOneArtists(string artist,string strArray[],int strCapacity) const  
{
	bool exist = false;
	int position = 0;
	for (int i = 0; i < this->nrOfSongs; i++)
	{
		if (this->songs[i]->getArtist()==artist)
		{
			strArray[position++] = this->songs[i]->getTitle();
			exist = true;
		}
	}
	for (int i = position; i < strCapacity; i++)
	{
		strArray[i] = nullptr;
	}
	return exist;
}

string SongRegister::songHasLongestTime() const
{
	string LongestTime="";
	string longestTitle="", longestArtist="";
	int longestTime=0;

	for (int i = 0; i < this->nrOfSongs; i++)
	{
		if (this->songs[i]->getPlayTime()>longestTime)
		{
			LongestTime ="Title: "+ this->songs[i]->getTitle()+" Artist:"+this->songs[i]->getArtist()+" Play Time: "+to_string(this->songs[i]->getPlayTime())+"\n";
			
			longestTime = this->songs[i]->getPlayTime();
			longestArtist = this->songs[i]->getArtist();
			longestTitle = this->songs[i]->getTitle();
		}
		if (this->songs[i]->getPlayTime()==longestTime)
		{
			if (this->songs[i]->getTitle()!=longestTitle || this->songs[i]->getArtist()!=longestArtist)
			{
				LongestTime += "Title: " + this->songs[i]->getTitle() + " Artist:" + this->songs[i]->getArtist() + " Play Time: " + to_string(this->songs[i]->getPlayTime())+ "\n";
			}
		}
	}
	return LongestTime;
}

string SongRegister::songHasShortestTime() const
{
	string ShortestTime ="";
	string shortestTitle = "", shortestArtist = "";
	int shortestTime=INT_MAX ;			//<limits> 2147483647

	for (int i = 0; i < this->nrOfSongs; i++)
	{
		if (this->songs[i]->getPlayTime()<shortestTime)
		{
			ShortestTime = "Title: " + this->songs[i]->getTitle() + " Artist:" + this->songs[i]->getArtist() + " Play Time: " + to_string(this->songs[i]->getPlayTime())+ "\n";
			
			shortestTime = this->songs[i]->getPlayTime();
			shortestArtist = this->songs[i]->getArtist();
			shortestTitle = this->songs[i]->getTitle();
		}
		if (this->songs[i]->getPlayTime() == shortestTime)
		{
			if (this->songs[i]->getArtist()!=shortestArtist || this->songs[i]->getTitle()!=shortestTitle)
			{
				ShortestTime += "Title: " + this->songs[i]->getTitle() + " Artist:" + this->songs[i]->getArtist() + " Play Time: " + to_string(this->songs[i]->getPlayTime()) + "\n";
			}
		}
	}
	return ShortestTime;
}

bool SongRegister::removeAsong(string title, string artist, int playTime)
{
	bool exist = false;
	for (int i = 0; i < this->nrOfSongs; i++)
	{
		if (*this->songs[i]==Song(title,artist,playTime))
		{
			exist = true;
			delete this->songs[i];
			this->songs[i] = this->songs[--this->nrOfSongs];
			this->songs[this->nrOfSongs] = nullptr;
		}
	}
	return exist;
}

int SongRegister::getTotalPlayTime() const
{
	int totalTime=0;
	for (int i = 0; i < this->nrOfSongs; i++)
	{
		totalTime += this->songs[i]->getPlayTime();
	}
	return totalTime;
}

string SongRegister::toString() const
{
	for (int i = 0; i < this->nrOfSongs; i++)
	{
		return this->songs[i]->toString();
	}
}



