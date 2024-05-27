#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;

namespace fs = filesystem;

void list_files(const fs::path& path)
{
    cout << "Contents of " << path << " : \n";
    for (const auto& entry : fs::directory_iterator(path))
    {
        cout << (entry.is_directory() ? "[D] " : "[F] ") << entry.path().filename() << endl;
    }
}

void create_dir(const fs::path& path)
{
    if (fs::create_directory(path))
    {
        cout << "Directory created : " << path << endl;
    }
    else
    {
        cout << "Failed to create directory : " << path << endl;
    }
}

void copy_file_func(const fs::path& source, const fs::path& destination)
{
    try
    {
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
        cout << "File copied from " << source << " to " << destination << endl;
    }
    catch (fs::filesystem_error& e)
    {
        cout << e.what() << endl;
    }
}

void move_file(const fs::path& source, const fs::path& destination)
{
    try
    {
        fs::rename(source, destination);
        cout << "File moved from " << source << " to " << destination << endl;
    }
    catch (fs::filesystem_error& e)
    {
        cout << e.what() << endl;
    }
}

void view_file(const fs::path& path)
{
    ifstream file(path);
    if (!file.is_open())
    {
        cout << "Failed to open file : " << path << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << "\n";
    }
    file.close();
}

int main()
{
    fs::path current_path = "C:\\Users\\AELLP\\OneDrive\\Documents\\Internship CodeAlpha";
    int choice;

    while (true)
    {
        cout << "Current Directory : " << current_path << endl;
        cout << "1. List files" << endl;
        cout << "2. View file" << endl;
        cout << "3. Create directory" << endl;
        cout << "4. Copy file" << endl;
        cout << "5. Move file" << endl;
        cout << "6. Change directory" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 1)
        {
            list_files(current_path);
        }
        else if (choice == 2)
        {
            string filename;
            cout << "Enter filename to view : ";
            cin >> filename;
            view_file(current_path / filename);
        }
        else if (choice == 3)
        {
            string dirname;
            cout << "Enter directory name to create : ";
            cin >> dirname;
            create_dir(current_path / dirname);
        }
        else if (choice == 4)
        {
            string source, destination;
            cout << "Enter source file : ";
            cin >> source;
            cout << "Enter destination path : ";
            cin >> destination;
            copy_file_func(current_path / source, current_path / destination);
        }
        else if (choice == 5)
        {
            string source, destination;
            cout << "Enter source file : ";
            cin >> source;
            cout << "Enter destination path : ";
            cin >> destination;
            move_file(current_path / source, current_path / destination);
        }
        else if (choice == 6)
        {
            string path;
            cout << "Enter path to change to : ";
            cin >> path;
            fs::path new_path = current_path / path;
            if (fs::exists(new_path) && fs::is_directory(new_path))
            {
                current_path = fs::canonical(new_path);
            }
            else
            {
                cout << "Invalid path" << endl;
            }
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

/*

Compile the program :

g++ -std=c++17 -o file_manager filemanager.cpp

Run the program :

./file_manager

*/