#include "Song.h"

Song::Song(string title, string artist, int playTime)
{
	this->title = title;
	this->artist = artist;
	this->playTime = playTime;
}

Song::~Song()
{
}

void Song::setTitle(string title)
{
	this->title = title;
}

void Song::setArtist(string artist)
{
	this->artist = artist;
}

void Song::setPlayTime(int playTime)
{
	this->playTime = playTime;
}

string Song::getTitle() const
{
	return this->title;
}

string Song::getArtist() const
{
	return this->artist;
}

int Song::getPlayTime() const
{
	return this->playTime;
}

bool Song::operator==(const Song & compareSong) const
{
	bool result = false;
	if (this->title==compareSong.title &&
		this->artist==compareSong.artist &&
		this->playTime==compareSong.playTime)
	{
		result = true;
	}
	return result;
}

bool Song::operator!=(const Song & compareSong) const
{
	bool result = false;
	if (this->title!=compareSong.title ||
		this->artist!=compareSong.title ||
		this->playTime!=compareSong.playTime)
	{
		result = true;
	}
	return result;
}

string Song::toString() const
{
	return "Title: " + this->getTitle() + " Artist: " + this->getArtist() + " Play Time: " + to_string(this->getPlayTime()) + "s\n";
}
