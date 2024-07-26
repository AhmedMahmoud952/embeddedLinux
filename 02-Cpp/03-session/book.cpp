#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void readInput();
void menu();

void listUsers();
void addUser();
void deleteUser();
void searchUser();


void menu(){
    auto option = [](std::string command, std::string explantion){
        std::cout << std::left << std::setfill('.') << std::setw(20) << command << std::left << explantion << std::endl;
    };
    std::cout << "What do you want to do?" << std::endl << std::endl;
    option("list", "Lists all users");
    option("add", "adds an user");
    option("delete", "Deletes an user");
    option("deleteall", "Deletes all users");
    option("search", "Search for a user");
    option("close","Closes the address book");
    std::cout << std::endl;
    readInput();
}

void listUsers(){
    std::ifstream myfile("address_book.txt");
    if (myfile.is_open())
    {
        std::string line;
        while (getline(myfile, line))
        {
            std::cout << line << std::endl;
        }
        myfile.close();
    }
    else std::cout << "No content found";
}

void addUser(){
    std::string name;
    std::ofstream myfile("address_book.txt",std::ios::app);
    std::cout << "Enter a Name: " << std::flush;
    std::cin>>name;
    myfile << name << std::endl;
    myfile.close();
}

void deleteUser(){
    std::string name;
    std::string line;
    std::ifstream myfile("address_book.txt");
    std::ofstream temp("temp.txt");
    std::cout << "Enter a name to delete: " << std::flush;
    std::cin >> name;
    while(getline(myfile, line)){
        if(line!= name){
            temp << line << std::endl;
        }
    }
    myfile.close();
    temp.close();
    remove("address_book.txt");
    rename("temp.txt", "address_book.txt");
}

void deleteAllUsers()
{
    remove("address_book.txt");
    std::cout << "All users deleted" << std::endl;
}

void searchUser()
{
    std::string name;
    std::string line;
    std::ifstream myfile("address_book.txt");
    std::cout << "Enter a name to search: " << std::flush;
    std::cin >> name;
    while(getline(myfile, line)){
        if(line == name){
            std::cout << line << " exist" << std::endl;
        }
    }
    
}

void readInput(){
    std::string command;
    std::cin >> command;
    if (command == "list")
    {
        listUsers();
    }
    else if (command == "add")
    {
        addUser();
    }
    else if (command == "delete")
    {
        deleteUser();
    }
    else if (command == "deleteall")
    {
        std::cout << "here" << std::endl;
        deleteAllUsers();
    }
    else if (command == "search")
    {
        searchUser();
    }
    else if (command == "close")
    {
        return;
    }
    menu();
}

int main(int argc, const char** argv) {

    menu();
    return 0;
}
