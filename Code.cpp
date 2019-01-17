#include <iostream.h>
#include <stdlib.h>
const int size = 5;
void puzzle(int [][size],int,int,int &);
void path(int [][size],int,int,int &);
int array2[size][size]={0};
main(){
	srand(time(0));
	int c=1,flag=0,flag2=0;
	while (!flag){
	cout<<"puzzle number "<<c++<<endl; 
	int array[size][size]={0};
	for (int i=0;i<size;i++)
		for (int j=0;j<size;j++)
			array[i][j]=rand()%2;
		//	cin>>array[i][j];
	array[0][0]=array[size-1][size-1]=1;
	for (int i=0;i<size;i++){
		for (int j=0;j<size;j++)
			cout<<array[i][j]<<"  ";
		cout<<endl;
	}
	array[0][0]=0;
	puzzle(array,0,0,flag);
	if (flag){
		for (int i=0;i<size;i++)
			for (int j=0;j<size;j++)
				array[i][j]=0;
		array2[0][0]=1;
		path(array,4,4,flag2);	
		cout<<"there is a path"<<endl;
		array[0][0]=array[size-1][size-1]=1;
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++)
				cout<<array[i][j]<<"  ";
			cout<<endl;
		}		
	}
	else{
		cout<<"there is no path in the puzzle number "<<c-1<<endl;	
		for (int i=0;i<size;i++)
			for (int j=0;j<size;j++)
				array2[i][j]=0;	
	}
	}			
}
void puzzle(int array[][size],int i,int j,int &flag){
	if (i==size-1 && j==size-1)
		flag = 1;		
	else{
		if (array[i+1][j]==1 && i<size-1 && flag==0){
			array[i+1][j]=0;
			array2[i+1][j]=1;
			puzzle(array,i+1,j,flag);
		}
		if (array[i][j+1]==1 && j<size-1 && flag==0){
			array[i][j+1]=0;
			array2[i][j+1]=1;
			puzzle(array,i,j+1,flag);
		}
		if (array[i-1][j]==1 && i>0 && flag==0){
			array[i-1][j]=0;
			array2[i-1][j]=1;
			puzzle(array,i-1,j,flag);
		}

		if (array[i][j-1]==1 && j>0 && flag==0){
			array[i][j-1]=0;
			array2[i][j-1]=1;
			puzzle(array,i,j-1,flag);
		}			
	}
}
void path(int array[][size],int i,int j,int &flag2){
	if (i==0 && j==0)
		flag2=1;	
	else{
		if (array2[i][j-1]==1 && j>0 && flag2==0){
			array2[i][j-1]=0;
			array[i][j-1]=1;
			path(array,i,j-1,flag2);
		}	
		if (array2[i-1][j]==1 && i>0 && flag2==0){
			array2[i-1][j]=0;
			array[i-1][j]=1;
			path(array,i-1,j,flag2);
		}		
		if (array2[i][j+1]==1 && j<size-1 && flag2==0){
			array2[i][j+1]=0;
			array[i][j+1]=1;
			path(array,i,j+1,flag2);
		}	
		if (array2[i+1][j]==1 && i<size-1 && flag2==0){
			array2[i+1][j]=0;
			array[i+1][j]=1;
			path(array,i+1,j,flag2);
		}	
	}	
}