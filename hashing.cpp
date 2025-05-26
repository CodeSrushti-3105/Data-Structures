#include<iostream>
using namespace std;
const int SIZE = 10;
class HashTable{
    string keys[SIZE];
    string values[SIZE];
    public:
    HashTable(){
        for(int i=0; i<SIZE; i++){
            keys[i] = "";
            values[i] = "";
        }
    }
    int hashFunction(string key){
        int sum = 0;
        int i=0;
        while(key[i] != '\0'){
            sum += key[i];
            i++;
        }
        return sum % SIZE;
    }
    void insert(string key, string value){
        int index = hashFunction(key);
        int start = index;
        while(keys[index]!="" && keys[index] != key){
            index = (index+1)%SIZE;
            if(index == start){
                cout<<"Hash table full\n";
                break;
            }
        }
        keys[index] = key;
        values[index] = value;
        cout<<"Inserted: "<<key<<" -> "<<value<<endl;
    }
    void find(string key){
        int index = hashFunction(key);
        int start = index;
        while(keys[index]!=""){
            if(keys[index] == key){
                cout<<"Found: "<<key<<" -> "<<values[index]<<" at "<<index<<endl;
                return;
            }
            index = (index + 1)% SIZE;
            if(index == start)break;
        }
        cout<<"Key not found!\n";
    }
    void remove(string key){
        int index = hashFunction(key);
        int start = index;
        while(keys[index] != ""){
            if(keys[index] == key){
                keys[index] = "";
                values[index] = "";
                cout<<"Key deleted\n.";
                return;
            }
            index = (index + 1)% SIZE;
        }
        cout<<"Key not found!\n";
    }
    void display(){
        cout<<"Hash table: "<<endl;
        for(int i=0; i<SIZE; i++){
            if(keys[i] != ""){
                cout<<i<<": "<<keys[i]<<" -> "<<values[i]<<endl;
            }else{
                cout<<i<<": EMPTY\n";
            }
        }
    }
    void qinsert(string key, string value){
        int start = hashFunction(key);
        int index;
        for(int i=0; i<SIZE; i++){
            index = (start + i*i)%SIZE;
            if(keys[index] == "" || keys[index] == key){
                keys[index] = key;
                values[index] = value;
                cout << "Inserted: " << key << " -> " << value << endl;
                return;
            }
        }
        cout<<"Hash Table full\n.";
    }

    void qfind(string key){
        int start = hashFunction(key);
        int index;
        for(int i=0; i<SIZE; i++){
            index = (start + i*i)%SIZE;
            if(keys[index] == "")break;
            if(keys[index] == key){
                cout<<"Key found: "<<key<<" -> "<<values[index]<<endl;
                return;
            }
        }
        cout<<"Key not found!\n";
    }
    void qremove(string key){
        int start = hashFunction(key);
        int index;
        for(int i=0; i<SIZE; i++){
            index = (start + i*i)%SIZE;
            if(keys[index] == "")break;
            if(keys[index] == key){
                keys[index] = "";
                values[index] = "";
                cout<<"deleted\n";
                return;
            }
        }
        cout<<"Key not found!"<<endl;
    }
};
int main(){
    HashTable h;
    int ch;
    string name, num;
    do{
        cout<<"\n----Telephone Directory-----\n";
        cout<<"1. Insert name and phone number\n";
        cout<<"2. Find name\n";
        cout<<"3. Delete an entry\n";
        cout<<"\nQuadratic Probing\n";
        cout<<"4. Insert name and phone number\n";
        cout<<"5. Find name\n";
        cout<<"6. Delete an entry\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter telephone number: ";
                getline(cin,num);
                h.insert(name,num);
                h.display();
                break;
            case 2:
                cout<<"Enter name to be found: ";
                cin.ignore();
                getline(cin,name);
                h.find(name);
                break;
            case 3:
                cout<<"Enter name to be deleted: ";
                cin.ignore();
                getline(cin,name);
                h.remove(name);
                break;
            case 4:
                cout<<"Enter name: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter telephone number: ";
                getline(cin,num);
                h.qinsert(name,num);
                h.display();
                break;
            case 5:
                cout<<"Enter name to be found: ";
                cin.ignore();
                getline(cin,name);
                h.qfind(name);
                break;
            case 6:
                cout<<"Enter name to be deleted: ";
                cin.ignore();
                getline(cin,name);
                h.qremove(name);
                break;
            case 7:
                cout<<"Exiting....\n";
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }while(ch != 7);
}
