#include "Pinakas.h"
#include "RandMT.h"
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <functional>


using namespace std;

int main(int argc, char** argv){
	
	//variable declaration
	Pinakas ant,antcop;
	int array_size,array_choice;
	double sec1,sec2,sec3,sec4;
	clock_t ct0,ct1,ct2,ct3,ct4,ct5,ct6,ct7;
	
	//file declaration and creation
	ofstream file_anastasios;
	file_anastasios.open("textfileproject4638.txt");
	
	//Student info
	cout<<"Student" <<endl;
	cout<<"=======" <<endl;
	cout<<"Name: ANASTASIOS TZOURAS"<<endl;
	cout<<"AEM:  4638"<<endl <<endl;
	
	cout<<"Computer Characteristics" <<endl;
	cout<<"------------------------" <<endl;
	cout<<"CPU: AMD" <<endl;
	cout<<"     Ryzen 5 1600 3.20GHz" <<endl;
	cout<<"RAM: 8GB" <<endl <<endl;
	
	//User puts desired array size
	cout<<"Array Size? ";
	cin>>array_size;
	cout<<endl <<endl;
	ant.setArraySize(array_size);
	antcop.setArraySize(array_size);
	ant.createArray();
	antcop.createArray();
	
	//User puts desired array type
	cout<<"Array Types" <<endl;
	cout<<"-----------" <<endl;
	cout<<"    1. Random 100%" <<endl;
	cout<<"    2. Sorted 50%, Random 50%" <<endl;
	cout<<"    3. Sorted ASC" <<endl;
	cout<<"    4. Sorted DESC" <<endl;
	cout<<"Choose array type: ";
	cin>>array_choice;
	switch(array_choice){
		case (1):
			ant.fill_100();
		break;
		case (2):
			ant.fill_50_sorted();
		break;
		case (3):
			ant.fill_ASC();
		break;
		case (4):
			ant.fill_DESC();
		break;	
		default:
			cout<<"nothing";
	}
	
	
	//Timings for sorting algorithms
	cout<<"Sorting -->";
	//Timer for BubbleSort
	ant.copyArray(antcop);
	ct0=clock();
	antcop.bubble();
	ct1=clock();
	sec1=(double)(ct1-ct0)/CLOCKS_PER_SEC;
	cout<<"Bubble... ";
	
	
	//Timer for SelectSort
	ant.copyArray(antcop);
	ct2=clock();
	antcop.select();
	ct3=clock();
	sec2=(double)(ct3-ct2)/CLOCKS_PER_SEC;
	cout<<"Select... ";
	//Timer for InsertSort
	
	ant.copyArray(antcop);
	ct4=clock();
	antcop.insert();
	ct5=clock();
	sec3=(double)(ct5-ct4)/CLOCKS_PER_SEC;
	cout<<"Insert... ";
	//Timer for QuickSort
	
	ant.copyArray(antcop);
	ct6=clock();
	antcop.quick(0,array_size);
	ct7=clock();
	sec4=(double)(ct7-ct6)/CLOCKS_PER_SEC;
	cout<<"Quick... ";
	cout<<"FINISHED!!!! :)";
	

	
	//File outputs
	file_anastasios <<"For Table Size = " <<array_size <<endl;
	if(array_choice==1){
		file_anastasios <<"Array Type = Random 100%" <<endl;
	}
	else if(array_choice==2){
		file_anastasios <<"Array Type = Sorted 50%, Random 50%" <<endl;
	}
	else if(array_choice==3){
		file_anastasios <<"Sorted ASC" <<endl;
	}
	else if(array_choice==4){
		file_anastasios <<"Sorted DESC" <<endl;
	}
	
	file_anastasios <<"EXECUTION TIMES(seconds)" <<endl;
	file_anastasios <<"BubbleSort  SelectSort InsertSort QuickSort" <<endl;
	file_anastasios <<"==========  ========== ========== =========" <<endl;
	file_anastasios <<sec1 <<"      " <<sec2 <<"      " <<sec3 <<"      " <<sec4 <<endl;
	
	//Conclusion
	file_anastasios <<"Παρατηρώ καταρχάς οτι ο πιο γρήγορος τροπος ταξινομισης ειναι ο quick ασχετα με τον τροπο που γεμιζει ο πινακας η απο το μεγεθος του" <<endl;
	file_anastasios <<"Επιτα παρατηρώ οτι ο bubblesort ειναι παρα πολυ χρονοβορος και δεν υπαρχει λογος να τον χρησιμοποιουμε εκτος αν ο πινακας ειναι πολυ μικρος" <<endl;
	file_anastasios <<"O selectsort ειναι αρκετα αξιοπιστος ειδικα σε μεσσαιου μεγεθους πινακες αλλα σε μεγαλυτερους πινακες συστηνεται να αποφευγεται" <<endl;
	file_anastasios <<"Ο insertsort ειναι παρομοιος σε ταχυτητα με τον select sort αλλα υπαρχουν ειδικες περιπτωσεις που αν ο πινακας ειναι/n"; 
	file_anastasios <<"φθινουσα ταξινομημενος ο αλγοριθμος αυτος ειναι πιο γρηγορος και απο την quicksort επισης αν ο πινακας ειναι αυξουσα ταξινομημενος/n"; 
	file_anastasios <<"ο αλγοριθμος αυτος λογω της ειδικης κατασκευης του θα παρει παρα πολυ ωρα να ταξινομηθει " <<endl;
	
	//File close
	file_anastasios.close();
	
	//Delete array to free memory
	ant.freeMemory();
	antcop.freeMemory();
	return 0;
}
