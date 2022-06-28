#ifndef PINAKAS_H
#define PINAKAS_H

class Pinakas{
	private:
		int *p;
		int  n;
	public:
		void setArraySize(int n1);
		void createArray();
		void copyArray(Pinakas ant);
		void freeMemory();
		void fill_100();
		void fill_50_sorted();
		void fill_ASC();
		void fill_DESC();
		void bubble();
		void select();
		void insert();
		void quick(int left,int right);
}; //end

#endif
