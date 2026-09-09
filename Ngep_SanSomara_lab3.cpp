
#include <iostream>
using namespace std;

//  single linked list 
class Node {
public:
    int ID;
    string name;
    string major;
    Node* next;

    Node(int id, string n, string m) {
        ID = id;
        name = n;
        major = m;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int id, string n, string m) {
        Node* newNode = new Node(id, n, m);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtBeginning(int id, string n, string m) {
        Node* newNode = new Node(id, n, m);
        newNode->next = head;
        head = newNode;
    }

    int count() {
        int c = 0;
        Node* temp = head;
        while (temp != nullptr) {
            c = c + 1;
            temp = temp->next;
        }
        return c;
    }

    bool search(int id) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->ID == id) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool deleteAtFirst() {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->ID << " - " << temp->name << " - " << temp->major << endl;
            temp = temp->next;
        }
    }
};

//doubly linked list 

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteAtEnd() {
        if (tail == nullptr) {
            return;
        }
        if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            DNode* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void display() {
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// circular linked list 
class CNode {
public:
    int data;
    CNode* next;

    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    CNode* head;
    CNode* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteHead() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            CNode* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    bool search(int val) {
        if (head == nullptr) {
            return false;
        }
        CNode* temp = head;
        do {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void display() {
        if (head == nullptr) {
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


// music 
class SongNode {
public:
    string title;
    SongNode* next;

    SongNode(string t) {
        title = t;
        next = nullptr;
    }
};

class MusicPlaylist {
private:
    SongNode* tail;
    SongNode* current;

public:
    MusicPlaylist() {
        tail = nullptr;
        current = nullptr;
    }

    void addSong(string title) {
        SongNode* newNode = new SongNode(title);
        if (tail == nullptr) {
            tail = newNode;
            newNode->next = newNode;
            current = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void playNext() {
        if (current == nullptr) {
            cout << "No songs in playlist" << endl;
            return;
        }
        current = current->next;
        cout << "Now playing: " << current->title << endl;
    }
};

 
//brower bistory
class PageNode {
public:
    string url;
    PageNode* prev;
    PageNode* next;

    PageNode(string u) {
        url = u;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
private:
    PageNode* current;

public:
    BrowserHistory(string home) {
        current = new PageNode(home);
    }

    void visit(string url) {
        PageNode* newNode = new PageNode(url);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
        cout << "Visited: " << current->url << endl;
    }

    void back() {
        if (current->prev != nullptr) {
            current = current->prev;
            cout << "Back to: " << current->url << endl;
        } else {
            cout << "Already at the first page" << endl;
        }
    }

    void forward() {
        if (current->next != nullptr) {
            current = current->next;
            cout << "Forward to: " << current->url << endl;
        } else {
            cout << "No forward page" << endl;
        }
    }
};



//undo rebo
class CommandNode {
public:
    string command;
    CommandNode* prev;
    CommandNode* next;

    CommandNode(string c) {
        command = c;
        prev = nullptr;
        next = nullptr;
    }
};

class UndoRedo {
private:
    CommandNode* current;

public:
    UndoRedo() {
        current = new CommandNode("start");
    }

    void doCommand(string cmd) {
        CommandNode* newNode = new CommandNode(cmd);
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
        cout << "Did: " << cmd << endl;
    }

    void undo() {
        if (current->prev != nullptr) {
            cout << "Undo: " << current->command << endl;
            current = current->prev;
        } else {
            cout << "Nothing to undo" << endl;
        }
    }

    void redo() {
        if (current->next != nullptr) {
            current = current->next;
            cout << "Redo: " << current->command << endl;
        } else {
            cout << "Nothing to redo" << endl;
        }
    }
};



int main() {
    cout << "=== Part 1: Singly Linked List ===" << endl;
    SinglyLinkedList list1;
    list1.insertAtEnd(101, "Sophea", "Computer Science");
    list1.insertAtEnd(102, "Dara", "Software Engineering");
    list1.insertAtEnd(103, "Vanna", "Data Science");
    list1.display();

    list1.insertAtBeginning(100, "Kimheng", "Computer Science");
    list1.display();

    cout << "Count: " << list1.count() << endl;
    cout << "Search 102: " << list1.search(102) << endl;
    cout << "Search 999: " << list1.search(999) << endl;

    list1.deleteAtFirst();
    list1.display();

    cout << "\n=== Part 2: Doubly Linked List ===" << endl;
    DoublyLinkedList list2;
    list2.insertAtEnd(10);
    list2.insertAtEnd(20);
    list2.insertAtEnd(30);
    list2.display();

    list2.insertAtBeginning(5);
    list2.display();

    list2.deleteAtEnd();
    list2.display();

    cout << "\n=== Part 2: Circular Linked List ===" << endl;
    CircularLinkedList list3;
    list3.insertAtEnd(1);
    list3.insertAtEnd(10);
    list3.insertAtEnd(4);
    list3.insertAtEnd(6);
    list3.display();

    cout << "Search 4: " << list3.search(4) << endl;
    cout << "Search 99: " << list3.search(99) << endl;

    list3.deleteHead();
    list3.display();

    cout << "\n=== Part 2: Music Playlist ===" << endl;
    MusicPlaylist playlist;
    playlist.addSong("Bad Habits");
    playlist.addSong("Shape of You");
    playlist.addSong("Perfect");
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();

    cout << "\n=== Part 2: Browser History ===" << endl;
    BrowserHistory history("home.com");
    history.visit("google.com");
    history.visit("wikipedia.org");
    history.back();
    history.forward();
    history.forward();

    cout << "\n=== Part 2: Undo Redo ===" << endl;
    UndoRedo editor;
    editor.doCommand("Type Hello");
    editor.doCommand("Type World");
    editor.undo();
    editor.redo();
    editor.undo();
    editor.undo();

    return 0;
}