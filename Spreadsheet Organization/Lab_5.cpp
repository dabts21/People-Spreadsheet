#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

/* GLOBAL CONSTANTS */

const string IST_FNAME = "input.csv";
const string OST_FNAME = "output.txt";

/* DATA TYPE DECLARATIONS */

struct Character {
	string firstname;
	string middlename;
	string lastname;
	string address;
	string city;
	string state;
	string zip;
	string box;
	string rate_a;
	string rate_b;
	string rate_c;
};


/* FUNCTION DEFINITIONS */

int main(int argc, char** argv) {
	
	string header;
	
	/* Create containers for file data */
	
	Character person;					// contains information about an individual person
	
	vector<Character> people = {};	// contains information about a list of people
	
	try {
		
		/* Open input and output files */
		
		ifstream ist(IST_FNAME);
		ofstream ost(OST_FNAME);
		
		/* Was the input file opened?  If not, throw an exception */
		
		if (!ist) {
			throw runtime_error("ERROR: Input file not found!");
		}
		
		/* Skip the header row */
		
		getline(ist, header);
		
		/* Read lines until EOF reached */
		
		while ( !ist.eof() ) {
			
			//person = {};							// create new map for next person's data
			
			getline(ist, person.firstname, ',');		// read fields (delimited with commas)
			getline(ist, person.middlename, ',');	// "
			getline(ist, person.lastname, ',');		// "
			getline(ist, person.address, ',');		// "
			getline(ist, person.city, ',');			// "
			getline(ist, person.state, ',');			// "
			getline(ist, person.zip, ',');			// "
			getline(ist, person.box, ',');			// "
			getline(ist, person.rate_a, ',');		// "
			getline(ist, person.rate_b, ',');		// "
			getline(ist, person.rate_c);				// last field terminated by '\n'!
		 
			people.push_back(person);					// add map to collection
			
		}
		
		/* Call a function to iterate through the collection, copying the */
		/*  data for each person to the output file, and to the console, in address block format  */
		
		string box;
		
		for (int i =0; i < 500; ++i){
			
			
			cout << people[i].firstname << ' ' << people[i].middlename << ' ' << people[i].lastname << "\n" ;
			cout << people[i].address <<  "\n" ;
			cout << people[i].city << ' ' << people[i].state << ' ' << people[i].zip << "\n";
			
			box = people[i].box;

			switch (box[0]) {
				case 'A': 
					cout << people[i].rate_a << "\n";
					break;
				case 'B': 
					cout << people[i].rate_b<< "\n";
					break;
				case 'C': 
					cout << people[i].rate_c<< "\n";
					break;
			}
			cout << "\n";
			
		}

		/* Close input file; exit */
		
		ist.close();
		ost.close();
		
	}
	
	catch(exception& e) {
		cerr << e.what() << '\n';
		return 1;
	}
	
	return 0;
	
}


