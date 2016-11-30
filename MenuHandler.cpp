#include<iostream>
#include "SongRegister.h"

void testMemoryLeaks()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int showMenu();
void addOneSong(SongRegister &songregister);
void presentAllSongs(SongRegister &songregister);
void presentAllSongsWithOneArtist(SongRegister &songregister);
void presentLongestSongs(SongRegister &songregister);
void presentShortestSongs(SongRegister &songregister);
void removeSpecificSong(SongRegister &songregister);
void presentTotalTime(SongRegister &songregister);

int main()
{
	SongRegister songregister;
	int selectNum=0;
	selectNum=showMenu();
	while (true)
	{
		switch (selectNum)
		{
		case 1:addOneSong(songregister); break;
		case 2:presentAllSongs(songregister); break;
		case 3:presentAllSongsWithOneArtist(songregister); break;
		case 4:presentLongestSongs(songregister); break;
		case 5:presentShortestSongs(songregister); break;
		case 6:removeSpecificSong(songregister); break;
		case 7:presentTotalTime(songregister); break;
		case 8:exit(0);
		}
		cout << endl;

		selectNum = showMenu();
	}
	
	testMemoryLeaks();
	return 0;
}

int showMenu()
{
	cout << "Please enter the number to use the specific function: " << endl;
	int num;
	cout << "1. Add a new song with title, artist and the play time.\n"
			<< "2. Present all songs with all the information.\n"
			<< "3. Present all songs with a specific artist.\n"
			<< "4. Present the song that has the longest play time.\n"
			<< "5. Present the song thar has the shortest play time.\n"
			<< "6. Remove the song with the given title,artist and play time.\n"
			<< "7. Present the total play time.\n"
			<< "8. Quit."
			<< endl;
	cin >> num;
	return num;
}

void addOneSong(SongRegister & songregister)
{
	string title, artist;
	int playTime;
	cout << "Please enter the title: ";
	cin.ignore();// clear the enter
	getline(cin, title);
	cout << "Please enter the artist: ";
	getline(cin, artist);
	cout << "Please enter the play time(seconds): ";
	cin >> playTime;
	if (songregister.addSongs(title,artist,playTime)==true)
	{
		cout << "A new song has been added." << endl;
	}
	else
	{
		cout << "Sorry! There is a song already has the same information with what you have typed" << endl;
	}
}

void presentAllSongs(SongRegister & songregister)
{
	cout << songregister.toString();
}

void presentAllSongsWithOneArtist(SongRegister & songregister)
{
	string artist="";
	cout << "Please enter the artist you want to search: ";
	cin >> artist;

	string *strArray = new string[songregister.getNrOfSongs()];

	if (songregister.titleOfAllSongsWithOneArtists(artist,strArray,songregister.getNrOfSongs())==false)
	{
		cout << "Sorry,the artist you typed doesn't exist." << endl;
	}
	else
	{
		cout << "Here is(are) the song(s) of the artist:" << endl;
		for (int i = 0; i < songregister.getNrOfSongs(); i++)
		{
			cout << i + 1 << ". " << strArray[i] << endl;
		}
	}
}

void presentLongestSongs(SongRegister & songregister)
{
	cout << "Here is(are) the song(s) that has(have) the longest play time.\n";
	cout << songregister.songHasLongestTime();
}

void presentShortestSongs(SongRegister & songregister)
{
	cout << "Here is(are) the song(s) that has(have) the shortest play time.\n";
	cout << songregister.songHasShortestTime();
}

void removeSpecificSong(SongRegister & songregister)
{
	string title, artist;
	int playTime;
	cout << "Please enter the title of the song you want to remove: ";
	cin >> title;
	cout << "Please enter the artist of the song you want to remove: ";
	cin >> artist;
	cout << "Please enter the play time  of the song you want to remove: ";
	cin >> playTime;
	if (songregister.removeAsong(title,artist,playTime)==true)
	{
		cout << "The song has been removed!" << endl;
	}
	else
	{
		cout << "The song you want to remove doesn't exist." << endl;
	}
}

void presentTotalTime(SongRegister & songregister)
{
	cout << "The total play time of all songs are " << songregister.getTotalPlayTime() <<"s."<< endl;
}
