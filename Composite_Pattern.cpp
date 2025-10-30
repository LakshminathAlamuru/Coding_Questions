#include<iostream>
#include<list>
using namespace std;

class FileSystem{
    public:
        virtual void search(string name) = 0;
        virtual ~FileSystem() {};
};

class File: public FileSystem
{
    public:
        string filename;
        File(string name)
        {
            filename = name;
        }
        void add(string str)
        {
            filename = str;
        }
        void search(string name)
        {
            if(name == filename)
            {
                cout << "file found" << endl;
            }
        }
};

class Folder: public FileSystem
{
    public:
        string foldername;
        vector<FileSystem*> v;
        Folder(string str)
        {
            foldername = str;
        }
        void add(FileSystem* obj)
        {
            v.push_back(obj);
        }
        void search(string name)
        {
            for(auto child: v)
            {
                child->search(name);
            }
        }

        ~Folder()
        {
            cout << "Deleting all files" << endl;
            for(auto child: v)
            {
                delete child;
            }
        }
};

int main()
{
    Folder *fol = new Folder("Documents");
    File *f1 = new File("Laksh1");
    File *f2 = new File("Laksh2");
    File *f3 = new File("Laksh3");
    File *f4 = new File("Laksh4");
    fol->add(f1);
    fol->add(f2);
    fol->add(f3);
    fol->add(f4);

    fol->search("Laksh4");

    return 0;
}