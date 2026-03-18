// Identification comments code block
// UnCodeSpecial
// Lab 10
// Editor(s) used: Repl.it IDE
// Compiler(s) used: Repl.it IDE
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setw;
using std::setprecision;
using std::left;

#include <string>
using std::string;

#include <algorithm>
using std::swap;

#include <fstream>
using std::ofstream;

#include <cstdlib>
#include <cstring>
#include <ctime>


struct Movie
{
  
  string name;
  int viewed;
  int rating;
  Movie* next;
  
};

void printMenu();
void addMovie(Movie*&, int&);
void updateMovie(Movie*&, int&);
void removeMovie(Movie*&, int);
void listMovie( Movie*);
void arrangeTitle(Movie*);
void arrangeViews(Movie*);
void arrangeRating(Movie*);
void deallocateNodes(Movie*);


int main()
{
  // identification output code block
  cout << "Lab 10\n";
  cout << "UnCodeSpecial\n";
  cout << "Editor(s) used: Repl.it IDE\n";
  cout << "Compiler(s) used: Repl.it IDE\n";
  cout << "File: " << __FILE__ << "\n"; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  Movie* firstMovie = 0;


  int size = 0;  
  char choice;
  printMenu();
  

  while(true)
  {
    
    
    cin>>choice;

    if(choice == 'A' || choice == 'a') 
    {
      addMovie(firstMovie, size);
      
    }

    else if (choice == 'U' || choice == 'u') 
    {
      updateMovie(firstMovie, size);
    }

    else if(choice == 'E'|| choice == 'e')
    {      
      removeMovie(firstMovie, size);
    }

    else if(choice == 'L' || choice == 'l')
    {
      listMovie(firstMovie);
    }


    else if(choice == 'T' || choice == 't')
    {
      arrangeTitle(firstMovie);
    }

    else if(choice == 'V' || choice == 'v')
    {
      arrangeViews(firstMovie);

    }

    else if (choice == 'R' || choice == 'r')
    {
      arrangeRating(firstMovie);
    }
    
    else if(choice == 'Q' || choice == 'q')
    {
      deallocateNodes(firstMovie);
      break;
    }

    else 
    {
      cout << "\nInvalid entry" << endl;
      printMenu();  
    }
  }

  return 0;
}

void printMenu()
{
  // function to print the menu
     
  cout << "\nMENU" << endl;
  cout << "Press A ..Add a movie"<<endl;
  cout << "Press U ..Update a movie"<< endl;
  cout << "Press E ..Erase a movie"<< endl;
  cout << "Press L ..List all movies" << endl;
  cout << "Press T ..Arrange by title"<< endl;
  cout << "Press V ..arrange by year viewed"<< endl;
  cout << "Press R ..arrange by Rating"<< endl;
  cout << "Press Q ..Quit"<< endl;
  cout << "\nYour choice > ";

}



void addMovie(Movie*& first, int& size)
{
  int index = 1, selec = 0;
  

    string buf;

    cout << "\nAdding Movie..." << endl;
    
    
    cin.ignore(1000, 10);
    cout << "Enter a movie's name > ";
    getline(cin, buf);

      

    Movie* temp = new Movie;
    temp->name = buf;

    cout << "Enter the year you saw " << temp->name << "[Like 2020]: ";
    cin >> buf; temp->viewed = atoi(buf.c_str());
    
    cout << "Enter your rating of " << temp->name << "[Like 1, 2, 3, 4, 5]: ";
    cin >> buf; temp->rating = atoi(buf.c_str());
    
    
    
    temp->next = first;
    first = temp;
    size++;

    printMenu();

   
  
  
}

void updateMovie(Movie*& first, int& size)
{

  int index = 1, selec = 0;
  string buf;

  cout << "\nUpdating Movie..." << endl;
  cout << "\nWhich movie to update [1-" << size << "]: ";
  cin >> buf; selec = atoi(buf.c_str());
  cin.ignore(1000, 10);

  if (selec < 1 || selec > size)
  {
    cout << "\n***ERROR***\nInvalid choice, please enter again > ";
    cin >> buf; selec = atoi(buf.c_str());
  }
  

  Movie* p;
  for (p = first; p; p = p->next, index++)
    if (index == selec) break;

  if (p)
  {
    
    
    cout << "Enter an updated name for " << p->name << ": ";
    getline(cin, buf); p->name = buf;

    
    cout << "Enter the year you saw " << p->name << "[Like 2020]: ";
    cin >> buf; p->viewed = atoi(buf.c_str());
    
    cout << "Enter your rating of " << p->name << "[Like 1, 2, 3, 4, 5]: ";
    cin >> buf; p->rating = atoi(buf.c_str());
    
    
  }
  else cout << "\n***ERROR***\nMovie not found, please enter again > ";

  printMenu();
  


}

void removeMovie(Movie*& first, int size)
{
  int choice;
  int index = 1;
  string buf;

  if(size)
  {
    cout << "Which movie to remove [1-" << size << "]:";
    cin >> buf;
    choice = atoi(buf.c_str());

    Movie* p, *prev;
    for(p = first, prev = 0; p; prev = p, p = p->next, index++)
      if(index == choice) break;
      
      if(p)
      {
        if (prev) prev->next = p->next; // skips over the node at p
        else first = p->next; // there's a new head, possibly zero
        delete p;
      }
    else
      cout << "Movie " << choice << " not found\n";
  }
  else
    cout << "\n\n***ERROR***\nInvalid choice, please enter again > ";
    listMovie(first);

    size--;

  
}

void listMovie( Movie* first)
{
  int index = 1;
  

  cout << "\nDisplaying movies\n" << endl;
  cout << left << setw(3) << " #" << setw(14) << " Movie Title" << setw(8) << "Viewed" << setw(8) << "Rating" << endl;
  cout << "--- ------------ ------- -------" << endl;

  for ( Movie* p = first; p; p = p -> next, index++)
  {
    cout << " ";
    cout.width(4);
    cout << index;
    cout.width(14);
    cout << p -> name;
    cout.width(8);
    cout << p -> viewed;
    cout.width(8);
    cout << setprecision(2) << p -> rating;
    cout << endl;
  }
  printMenu();
}



void arrangeTitle(Movie* first)
{
  for (Movie* p = first; p; p = p -> next)
    for (Movie* q = p -> next; q; q = q -> next)
      if (q -> name > p -> name)
        {
        swap(*p, *q);
        swap(p->next, q->next);
        }

cout << "\nDisplaying Movies sorted by titles" << endl;
listMovie(first);

}

void arrangeRating(Movie* first)
{
  for (Movie* p = first; p; p = p -> next)
    for (Movie* q = p -> next; q; q = q -> next)
      if (q -> rating > p -> rating)
        {
          swap(*p, *q);
          swap(p -> next, q -> next);
        }
  cout << "\nDisplaying Movies sorted by rating" << endl;
  listMovie(first);
  
}

void arrangeViews(Movie* first)
{

  for(Movie* p = first; p; p = p -> next)
    for(Movie* q = p -> next; q; q = q -> next)
      if (q -> viewed > p -> viewed)
        {
          swap(*p, *q);
          swap(p -> next, q -> next);
        }
cout << "\nDisplaying Movies sorted by viewed years" << endl;
listMovie(first);

}

void deallocateNodes(Movie* first)
{
  ofstream fout;
  fout.open("movies.txt");
  
  int index = 1;
  for ( Movie* p = first; p; p = p -> next, index++)
  {
    fout << p -> name << endl;
    fout << p -> viewed << endl;
    fout << p -> rating << endl;
  }

  fout << "EOF" << endl;
  fout.close();

  while (first) // keep going as long as the list is not empty
  {
    Movie* p = first; // hold onto head node...
    first = first->next; // ...because we're linking over it to its next
    delete p; // now deallocate the old head
  }

}
