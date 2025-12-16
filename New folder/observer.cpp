#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// YOUTUBE NOTIFICATION SYSTEM USING OBSERVER PATTERN.
class Observer{
    public:
        virtual void update(string &message) = 0;
};

class Subject{
    private:
        vector<Observer*> observers;
    public:
        void addObserver(Observer* o){
            observers.push_back(o);
        }

        void removeObserver(Observer* o){
            observers.erase(remove(observers.begin(), observers.end(),o), observers.end());
        }

        void notifyObservers(string &message){
            for(auto o: observers){
                o->update(message);
            }
        }
};

class YoutubeChannel:public Subject{
    private:
        string channelName;
    public:
        YoutubeChannel(string name){
            channelName = name;
        }
        void uploadVideo(string title){
            string message = channelName + " has uploaded a new video (" + title + ")";
            notifyObservers(message);
        }

        void subscribe(Observer* o){
            addObserver(o);
        }

        void unsubscribe(Observer* o){
            removeObserver(o);
        }
};

class User:public Observer{
    private:
        string username;
    public:
        User(string name){
            username = name;
        }

        void update(string &message){
            cout << username << " has received a notification: " << message << endl;
        }

        void subscribe(YoutubeChannel* channel){
            channel->subscribe(this);
        }

        void unsubscribe(YoutubeChannel* channel){
            channel->unsubscribe(this);
        }

        void uploadVideo(YoutubeChannel* channel, string title){
            channel->uploadVideo(title);
        }
};

int main(){
    
    User* user1 = new User("Vansh");
    User* user2 = new User("Bittu");
    User* user3 = new User("Rohit");

    YoutubeChannel* channel = new YoutubeChannel("Code with Vansh");

    user1 -> subscribe(channel);
    user2 -> subscribe(channel);
    user3 -> subscribe(channel);

    user1 -> uploadVideo(channel, "HTML Basics");

    user2 -> unsubscribe(channel);

    user3 -> uploadVideo(channel, "CSS Basics");

    return 0;
}