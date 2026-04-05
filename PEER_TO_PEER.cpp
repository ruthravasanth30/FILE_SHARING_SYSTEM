#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Graph: peer connections
unordered_map<string, vector<string>> network;

// Hash Table: file -> peers
unordered_map<string, vector<string>> files;

// Add connection between peers
void addConnection(string a, string b) {
    network[a].push_back(b);
    network[b].push_back(a);
}

// Add file to peer
void addFile(string peer, string filename) {
    files[filename].push_back(peer);
}

// Search file
void searchFile(string filename) {
    if(files.find(filename) != files.end()) {
        cout << "File found in peers: ";
        for(string p : files[filename])
            cout << p << " ";
    } else {
        cout << "File not found";
    }
    cout << endl;
}

int main() {
    // Create peers
    addConnection("Peer1", "Peer2");
    addConnection("Peer2", "Peer3");

    // Add files
    addFile("Peer1", "movie.mp4");
    addFile("Peer3", "song.mp3");

    // Search
    searchFile("movie.mp4");
    searchFile("song.mp3");
    searchFile("file.pdf");

    return 0;
}
