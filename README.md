# People-Spreadsheet
C++ program that systematically organizes information in a spreadsheet. 

## Introduction
  This was a program that I created my sophomore year at Jacksonville State University. Its coded in C++ and takes an otherwise very messy spreadsheet and organizes each person, place, number, etc. with its respective partner and places it in an organized manner. You might possibly have to create an empty output.txt file and add it to the same folder as the program for GitHub doesn't allow empty files. The stepdown through the code can be seen below.
  
## Necessary Code and Important Tools
  The code begins with me including vectors and maps. A vector in C++ is a list that can be added upon once its created. A map is a larger more broader storage container that stores items based on certain elements in mapped fashion. Both of these tools will be extremely helpful. The next thing I do is create constant strings to initialize the two files we will be dealing with. The input.csv and output.txt file. Next I create a struct that allows me to make a list of different strings related to the eleven categories within the spreadsheet. I then begin on the main function of the code. I begin by initializing a string called header that takes the header of the csv and stores it in a string. Following that, I create a person that uses the character struct datatype that I created earlier. This allows me to store information about an individual person. I then create a vector of people using the character datatype. This allows me to store individual information about many people in the csv.
  
## Reading and Outputing Information
  After I have the things I need to organize my information, it’s now time to open up the files and decipher the information. I do this by creating a try block. I then attempt to open the files so that the information can be read. If for some reason the csv file is unable to be opened, then I have include a small if statement to throw an error if it cannot be found. Otherwise I have the getline method receive the header of the file, which contains all the information about a person. I use a while loop to loop through and assign each string separated by commas in the csv to their respective field. Once it gets done with an iteration of the loop, it then assigns those fields to a person The loop continues until the end of the file (eof) is reached. Finally, I initialize a string called box to create separate “boxes” to display each person and their data. I do this by creating a for loop that selects a person based on the iteration of the loop and displays them in an organized string. Also, in the spreadsheet each person has a different rate that they use, A, B, or C. I use a switch statement to select each case and assign the correct number from the spreadsheet. At the conclusion of the file, the input.csv and output.txt files are closed. 
  
Reads fields from spreadsheet and adds them to a vector:

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
For loop that prints the information of that person, from the vector, onto the screen:

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
Finally, example of output after readin the input.csv file:

    Jose K Bowden
    4664 Sharon Lane
    Plymouth IN 46563
    37.38

    Danette S Becker
    603 Orchard Street
    Eden Prairie MN 55344
    33.03

    Rachel L Whitaker
    3589 Braxton Street
    Chicago IL 60606
    33.03

    Lonnie V Hood
    1535 Bedford Street
    Stamford CT 6902
    8.1

    Joyce B Ramsey
    2951 Duck Creek Road
    San Bruno CA 94066
    16.28
