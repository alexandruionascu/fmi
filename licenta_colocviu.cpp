#include<bits/stdc++.h>
#define in f
#define out cout
using namespace std;

//Patch for MinGW to implement to_string function
namespace std {
    template < typename T > std::string to_string( const T& n ) {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
};

class Date {
    private:
        int year;
        int month;
        int day;
    public:
        Date(int day, int month, int year) {
            this->day = day;
            this->month = month;
            this->year = year;
        }

        ostream& operator << (ostream& out) {
        return out << this->day << "-" << this->month << "-" << this->year;
    }

    int toDays() {
        return 365 * year + 30 * month + day;
    }

    int getYear() {
        return year;
    }

    string toString() {
        return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
    }
};


class Author {
    private:
        string firstName;
        string lastName;
    public:
        Author(string firstName, string lastName) {
            this->firstName = firstName;
            this->lastName = lastName;
        }

        string getFirstName() {
            return firstName;
        }

        string getLastName() {
            return lastName;
        }

};

class Source {
    protected:
        vector<Author*> authors;
        Date* date;
        string title;

    public:
        Source(string title, Date* date, vector<Author*> authors) {
            this->title = title;
            this->date = date;
            this->authors = authors;
        }

        void printAuthors() {
            for(auto author : authors) {
                out << author->getFirstName() << " " << author->getLastName() << " ";
            }
        }

        Date* getDate() {
            return date;
        }

        bool hasAuthor(string lastName) {
            for(auto author : authors) {
                if(author->getLastName() == lastName) {
                    return true;
                }
            }

            return false;
        }
};

class WrittenSource : public Source {
    private:
        string publication;
        string publicationTown;
        pair<int, int> pages;

    public:
        WrittenSource(string title, Date* date, vector<Author*> authors, string publication, string publicationTown, pair<int, int> pages) :
             Source(title, date, authors) {
             this->publication = publication;
             this->publicationTown = publicationTown;
             this->pages = pages;
        }

        void printSource() {
            out << title << " " << date->toString() << " ";
            printAuthors();
            out << publication << " " << publicationTown << " " << pages.first << " " << pages.second << '\n';
        }
};

class WebSource : public Source {
    private:
        string url;
        Date* accessedDate;
        string owner;

    public:
        WebSource(string title, Date* date, vector<Author*> authors, string owner, string url, Date* accessedDate) :
             Source(title, date, authors) {
            this->url = url;
            this->owner = owner;
            this->accessedDate = accessedDate;
        }

        void printSource() {
            out << title << " " << date->toString() << " ";
            printAuthors();
            out << owner << " " << url << " " << accessedDate->toString() << '\n';
        }

        string getOwner() {
            return owner;
        }
};

class References {
    private:
        vector<WebSource*> webSources;
        vector<WrittenSource*> writtenSources;

    public:
        void addWebSource(string title, Date* date, vector<Author*> authors,string owner, string url, Date* accessedDate) {
            auto webSource = new WebSource(title, date, authors, owner, url, accessedDate);
            webSources.push_back(webSource);
        }

        void addWrittenSource(string title, Date* date, vector<Author*> authors, string publication, string publicationTown, pair<int, int> pages) {
            auto writtenSource = new WrittenSource(title, date, authors, publication, publicationTown, pages);
            writtenSources.push_back(writtenSource);
        }

        void printReferences() {
            for(auto source : webSources) {
                source->printSource();
            }

            for(auto source : writtenSources) {
                source->printSource();
            }
        }

        void printWrittenReferences(string lastName) {
            for(auto source : writtenSources) {
                if(source->hasAuthor(lastName) == true) {
                    source->printSource();
                }
            }
        }

        void printWebReferences(int year) {
            for(auto source : webSources) {
                if(source->getDate()->getYear() == year)
                    source->printSource();
            }
        }

        void printWebReferences(string owner) {
            for(auto source : webSources) {
                if(source->getOwner() == owner) {
                    source->printSource();
                }
            }
        }




};

int main() {
    auto references = new References();
    references->addWrittenSource("Fuego Story", new Date(10, 4, 2016), {new Author("eul", "liric"), new Author("Mihai", "Eminescu")}, "Editura Bazata", "Chisinau", {10, 20});
    references->printReferences();
}
