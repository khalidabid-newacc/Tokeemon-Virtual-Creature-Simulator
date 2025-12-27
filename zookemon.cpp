#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//  - Virtual Class Creature
//  - Creature class
class Creature {
public:
  virtual void runComponentTests() const = 0; // the virtual function
  virtual void listen() = 0;
  virtual void play() = 0;
  virtual void feed() = 0;
  virtual void PassTime() = 0;
  virtual ~Creature() = default; // Virtual destructor
};

// Child Class
class Tokeemon : public Creature {
private:
  int hunger;
  int boredom;
  string species; // new memeber

public:
  Tokeemon(const string &species)
      : hunger(rand() % 6), boredom(rand() % 6), species(species) {}

  // virtual function implementation from base
  void runComponentTests() const override {
    cout << "* NOW Running component tests for classes *" << endl;
    cout << *this << endl;
  }

  // Listen
  void listen() override {
    cout << "Hunger: " << hunger << ", Boredom: " << boredom << endl;
    PassTime();
  }

  // Play
  void play() override {
    int playValue = rand() % 5 + 4;
    boredom = max(boredom - playValue, 0);
    PassTime();
  }

  // Feed
  void feed() override {
    int feedValue = rand() % 4 + 3;
    hunger = max(hunger - feedValue, 0);
    PassTime();
  }

  //  PassTime()
  void PassTime() override {
    hunger++;
    boredom++;

    // "catatonic state" AKA when boredom > 20
    if (boredom > 20) {
      cout << "Your Tokeemon has gone into an unresponsive state!" << endl;
      exit(0); // Just exits program
    }

    // Checking if the creature has starved to death
    if (hunger > 20) {
      cout << "Your Tokeemon has died of starvation!" << endl;
      exit(0); // Exits the program
    }
  }

  // Overload «
  friend ostream &operator<<(ostream &os, const Tokeemon &hokeemon) {
    os << "Species: " << hokeemon.species << ", Hunger: " << hokeemon.hunger
       << ", Boredom: " << hokeemon.boredom;
    return os;
  }

  // Getter for species
  const string &getSpecies() const { return species; }
};

// New child class for merged creatures
class MergedCreature : public Creature {
private:
  string name;
  int hunger;
  int boredom;

public:
  MergedCreature(const string &name) : name(name), hunger(0), boredom(0) {}

  // Implement virtual functions from the base class
  void runComponentTests() const override {
    cout << "* NOW Running component tests for classes *" << endl;
    cout << *this << endl;
  }

  // Listen part
  void listen() override {
    cout << "Hunger: " << hunger << ", Boredom: " << boredom << endl;
    PassTime();
  }

  // Play part
  void play() override {
    int playValue = rand() % 5 + 4;
    boredom = max(boredom - playValue, 0);
    PassTime();
  }

  // Feed part
  void feed() override {
    int feedValue = rand() % 4 + 3;
    hunger = max(hunger - feedValue, 0);
    PassTime();
  }

  //PassTime()
  void PassTime() override {
    hunger++;
    boredom++;

    // Checking for catatonic state on the new creature
    if (boredom > 20) {
      cout << "You allowed your critter to be bored! They are unresponsive, YOURE FIRED" << endl;
      exit(0); // Exit the program
    }

    // starvation check, AKA hunger > 20
    if (hunger > 20) {
      cout << "Your Merged Creature has died of starvation! YOURE FIRED"
           << endl;
      exit(0); // Exit the program
    }
  }

  //  Overload «
  friend ostream &operator<<(ostream &os,
                             const MergedCreature &mergedCreature) {
    os << "Name: " << mergedCreature.name
       << ", Hunger: " << mergedCreature.hunger
       << ", Boredom: " << mergedCreature.boredom;
    return os;
  }

  // Public getter for the name
  const string &getName() const { return name; }

  // Public method to set the name
  void setName(const string &newName) { name = newName; }
};

// Program Greeting function to display the message
void programGreeting() {
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Welcome to your very own magical creature zoo care job!" << endl;
  cout << "Program made by Khalid Abid" << endl;
  cout << "26 November 2023" << endl;
  cout << "___________________________________________________________" << endl;
  cout << endl;
}

// Can put CAPITAL or lowercase
// Validate Input
char inputValidation() {
  char choice;
  do {
    cout << "What do you want to do (L - Listen, P - Play, F - Feed, M - "
            "Merge, Q - Quit): ";
    cin >> choice;
    choice = toupper(choice); // Converting it to uppercase
  } while (choice != 'L' && choice != 'P' && choice != 'F' && choice != 'M' &&
           choice != 'Q');

  return choice;
}

// Lambda function example
// lambda function to find number squared
auto square = [](int x) { return x * x; };

// Function to handle merging creatures
void mergeCreatures(Creature &creature1, Creature &creature2) {
  // Create a new merged creature
  MergedCreature mergedCreature("Merged Cryoterra");

  // Critter Name
  // Display the merged creature, Allow the human user to name it
  cout << "Congratulations! Your creatures have merged into a new critter."
       << endl;
  cout << "What do you want to name this critter? : ";
  string mergedCreatureName;
  cin >> mergedCreatureName;

  //  Copy Constructor
  // Set the name for the merged creature using the public method
  mergedCreature.setName(mergedCreatureName);

  // Run component tests for the merged creature
  mergedCreature.runComponentTests();

  // Continuation with the new
  char choice;
  do {
    choice = inputValidation();

    switch (choice) {
    case 'L':
      mergedCreature.listen();
      break;
    case 'P':
      mergedCreature.play();
      break;
    case 'F':
      mergedCreature.feed();
      break;
    }
  } while (choice != 'Q');
}

// Unit test function
void unitTests() {
  // Create an object of the Tokeemon class
  Tokeemon myTokeemon("Cryoterra");

  // Run component tests for the created object
  myTokeemon.runComponentTests();

  // Additional unit tests
  cout << "\nRunning unit tests:" << endl;

  // Test 1: Listen
  cout << "Test 1 - Listen:" << endl;
  myTokeemon.listen();
  cout << "After listening: " << myTokeemon << endl;

  // Test 2: Play
  cout << "\nTest 2 - Play:" << endl;
  myTokeemon.play();
  cout << "After playing: " << myTokeemon << endl;

  // Test 3: Feed
  cout << "\nTest 3 - Feed:" << endl;
  myTokeemon.feed();
  cout << "After feeding: " << myTokeemon << endl;

  // Lambda Function
  // Test 4
  int numberBeingSquared = 5;
  cout << "\nTest 4 - Lambda Function:" << endl;
  cout << "The square of " << numberBeingSquared
       << " is: " << square(numberBeingSquared) << endl;

  cout << "---------------------------------------------------------------"
       << endl;
  cout << endl;
}

int main() {
  // Set seed for random number generation
  srand(static_cast<unsigned int>(time(0))); // Use time(0) for the current time

  // Display program greeting
  programGreeting();

  // Create an object of the Tokeemon class and name the creature
  Tokeemon myTokeemon("Cryoterra");

  // Run unit tests
  unitTests();

  char choice;
  do {
    choice = inputValidation();

    switch (choice) {
    case 'L':
      myTokeemon.listen();
      break;
    case 'P':
      myTokeemon.play();
      break;
    case 'F':
      myTokeemon.feed();
      break;
    case 'M':
      // M for mergeingh the creature
      mergeCreatures(myTokeemon, myTokeemon);
      break;
    }
  } while (choice != 'Q');

  cout << "BYE! Your Tokeemon appreciates you spending time with them." << endl;

  return 0;
}

