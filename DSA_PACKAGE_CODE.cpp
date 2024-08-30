#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <Windows.h>
#include "MMSystem.h"

using namespace std;

typedef struct node
{
        char song[100];
        node *fwd;
        node *bwd;
}node;

node* top;
node* temp;
node* top1;
node* ptr;
node* start;
fstream file;
class Playlist
{
        public:
                Playlist()
                {
                        top = NULL;
                }
                int addNode();
                void deleteNode(node*);
                void countNodes(node*);
                void searchSong(node*);
                void push(char*);
                void display();
                void play(node*);
                void recent();
                void topElement();
                int deleteSearch();
                void addPlaylist(node*);
                void deleteMenu(node*);
                int printPlaylist();
};
int Playlist :: addNode()
{
        ptr=start;
        file.open("songs.txt",ios :: app);
        if(!file)
        {
        //	cout << "rtwff";
        	return 0;
		}
               // return 0;
        else
        {
                char a[50];
                cout << "\nEnter Song name-  ";
                cin >> ws;
                cin.getline(a,50);
                while(ptr -> fwd != NULL)
                {
                        ptr = ptr -> fwd;
                }
                node *n=new node;
                strcpy( n->song , a);
                ptr->fwd=n;
                n -> bwd = ptr;
                n -> fwd=NULL;
                file << n->song;
                file << "\n";
        }
        file.close();
        
}
int Playlist :: printPlaylist()
{
        ptr = start;
        file.open("songs.txt",ios :: in);
        string line;
        if(!file.is_open())
                return 0;
        else
        {
                cout << "\nPlaylist Name- "<< ptr->song << endl;
                while(file >> line && ptr->fwd != NULL)
                {
                                cout << line << endl;
                                ptr = ptr -> fwd;
                }
        }
        file.close();
}
void Playlist :: countNodes(node* ptr)
{
        int i = 0;
        while(ptr -> fwd != NULL)
        {
                ptr = ptr -> fwd;
                i++;
        }
        i++;
        cout << "\nTotal songs-  " << i-1 << endl;
}
void Playlist :: searchSong(node* ptr)
{
        char song[100];
        cout<<"\n\a\a\a\aEnter song To be Searched- ";
        cin >> ws;
        cin >> song;
        int flag = 0;
        while(ptr != NULL)
        {
                if(strcmp(ptr -> song, song)==0)
                {
                        cout << "\n\a\a\a\a#Song Found" << endl;
                        flag++;
                        break;
                }
                else
                {
                ptr = ptr -> fwd;
                }
        }
        if(flag == 0)
        {
                cout<<"\n\a\a\a\a#Song Not found"<<endl;
        }
}
void Playlist :: push(char data[])
{
        if (top == NULL)
        {
                top = new node;
                top -> fwd = NULL;
                strcpy(top -> song, data);
        }
        else if (strcmp(top -> song, data)!=0)
        {
                temp = new node;
                temp -> fwd = top;
                strcpy(temp -> song, data);
                top = temp;
        }
}
void  Playlist :: display()
{
        top1 = top;
        if (top1 == NULL)
        {
                cout << "\n\a\a\a\a=>NO recently played tracks.\n";
                return;
        }
        cout << "\n\a\a\a\a#Recently played tracks-\n";
        while (top1 != NULL)
        {
                cout << top1->song << endl;
                top1 = top1 -> fwd;
        }
}
void Playlist :: play(node* ptr)
{
        char song[100];
        char chh;
        printPlaylist();
        cout<<"\n\a\a\a\aChoose song you wish to play- ";
        cin >> ws;
        cin >> song;
        int flag = 0;
        while(ptr != NULL)
        {
                if(strcmp(ptr -> song,song)==0)
                {
                        cout<<"\n\a\a\a\a=>Now Playing......"<<song<<endl;
                        //PlaySound(TEXT("Aval.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        if(strcmp(ptr -> song,"Aval") == 0)
                        {
                        	PlaySound(TEXT("Aval.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        	cout << "To pause press 'p'"<< endl;
                        	cin >> chh;
                        	if(chh == 'p' || chh == 'P')
                        	{
                        		PlaySound(0,0,0);
							}
						}
                        	//PlaySound(TEXT("Aval.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        else if(strcmp(ptr -> song,"Chillena") == 0)
                        {
                        	PlaySound(TEXT("Chillena.wav"),NULL,SND_FILENAME|SND_ASYNC);
                        	cout << "To pause press 'p'"<< endl;
                        	cin >> chh;
                        	if(chh == 'p' || chh == 'P')
                        	{
                        		PlaySound(0,0,0);
							}
                    	}
						else if(strcmp(ptr -> song,"Munbe_Vaa") == 0)
						{
		
							PlaySound(TEXT("Munbe_Vaa.wav"),NULL,SND_FILENAME|SND_ASYNC);
							cout << "To pause press 'p'"<< endl;
                        	cin >> chh;
                        	if(chh == 'p' || chh == 'P')
                        	{
                        		PlaySound(0,0,0);
							}
						}
						else if(strcmp(ptr -> song,"Thuli_Thuli") == 0)
						{
							PlaySound(TEXT("Thuli.wav"),NULL,SND_FILENAME|SND_ASYNC);
							cout << "To pause press 'p'"<< endl;
                        	cin >> chh;
                        	if(chh == 'p' || chh == 'P')
                        	{
                        		PlaySound(0,0,0);
							}
						}
						else if(strcmp(ptr -> song,"Anbil_Avan") == 0)
						{
							PlaySound(TEXT("Anbil_Avan.wav"),NULL,SND_FILENAME|SND_ASYNC);	
							cout << "To pause press 'p'"<< endl;
                        	cin >> chh;
                        	if(chh == 'p' || chh == 'P')
                        	{
                        		PlaySound(0,0,0);
							}
						}
						flag++;
                        push (song);
                        break;
                }
                else
                {
                ptr = ptr -> fwd;
                }
        }
        if(flag == 0)
        {
                cout << "\n\a\a\a\a#Song Not found" << endl;
        }
}
void Playlist :: recent()
{
        display();
}
void Playlist :: topElement()
{
        top1 = top;
        if(top1 == NULL)
        {
                cout << "\n\a\a\a\a#NO last played tracks.\n";
                return;
        }
        cout << "\n=>Last Played Song - "<< top -> song << endl;
}
int Playlist :: deleteSearch()
{
        char usersong[50];
        printPlaylist();
        cout << "\nChoose song you wish to delete- ";
        cin >> ws;
        cin.getline(usersong,50);
        int flag = 0;
        node *temp;
        ptr = start->fwd;
        while(ptr != NULL)
        {
                if(strcmp(ptr->song,usersong) == 0)
                {
                        cout << "\n\a\a\a\a#Song Found" << endl;
                        if(ptr -> fwd == NULL)
                        {
                                temp = ptr;
                                ptr=ptr->bwd;
                                ptr->fwd=NULL;
                                delete temp;
                                flag++;
                                break;
                        }
                        ptr -> bwd -> fwd = ptr -> fwd;
                        ptr -> fwd -> bwd = ptr -> bwd;
                        temp = ptr;
                        delete temp;
                        flag++;
                        break;
                }
                else
                {
                        ptr = ptr -> fwd;
                }

        }
        if(flag == 0)
        {
                cout << "\n\a\a\a\a#Song Not found" << endl;
        }
        ptr=start->fwd;
        file.open("songs.txt",ios :: out);
        if(!file)
                return 0;
        while(ptr!=NULL)
        {
                file << ptr->song;
                file << "\n";
                ptr =ptr->fwd;
        }
        file.close();
}
int main()
{
        int choice,loc;
        char song[100];
        Playlist obj;
        node *n  = new node;
        cout << "\t\t\t\t\t**PLAYLIST CREATOR**" << endl;
        cout << "Enter your playlist name-  ";
        cin >> ws;
        cin.getline(n->song,50);
        start=n;
        start -> fwd = NULL;
        start -> bwd = NULL;
        //PlaySound(TEXT("karma_tswift.wav"),NULL,SND_FILENAME|SND_ASYNC);
        //PlaySound(TEXT("Aval.wav"),NULL,SND_FILENAME|SND_ASYNC);
        //system("pause");
        do{
                cout << "\n1. To add a new song\n2. To delete a song\n3. To Display Entered Playlist\n4.To display the total number of songs\n5.To Search for a Song\n6.To play a song\n7.To display recently played songs\n8.To display last played song\n9.To exit\n";
                cout << "\nEnter your choice- ";
                cin >> choice;
        switch(choice)
        {
            case 1:obj.addNode();
            break;
            case 2:obj.deleteSearch();
            break;
            case 3:obj.printPlaylist();
            break;
            case 4:obj.countNodes(start);
            break;
            case 5:obj.searchSong(start);
            break;
            case 6:obj.play(start);
            break;
            case 7:obj.recent();
            break;
            case 8:obj.topElement();
            break;
            case 9:file.open("songs.txt",ios :: out);
       // file.seekp(0);
		file.close();
			return 0;
        default: cout << "Invalid choice. Please enter a valid choice from 1-9." << endl;
        }
    }while(choice!=9);
}
