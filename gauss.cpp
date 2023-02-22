#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>
int main(){
  //gauss elemination with pivoting.
    //getting matrix elements
  int order ;
  cout<<"Enter the order of matrix : "<<endl;
  cin>>order;
  double MatrixA[order][order];
  double VectorB[order];
  double X[order];
  //entering elements;
   cout<<"enter the element of matrix A"<<endl;
  for (int i =0;i<order;i++){
    for (int j=0;j<order;j++){
       cout<<"enter matrix["<<i<<"]["<<j<<"] : ";
       cin>>MatrixA[i][j];
    }
  }
  cout<<"enter the elements of vectorb"<<endl;
  for (int i=0;i<order;i++){
    cout<<"enter vector["<<i<<"] : ";
    cin>>VectorB[i];
  }
  //printing elements
  cout<<"matrix a is "<<endl;
  for(int i =0;i<order;i++){
    for (int j=0;j<order ;j++){
        cout<<setw(2)<<MatrixA[i][j];
    }
    cout<<endl;
  }
  cout<<"Vector b is "<<endl;
  for (int i=0;i<order;i++){
    cout<<VectorB[i]<<endl;
  }
  //forward elimination
  // i for pivot element j for going down for each pivot element and k for 
  //forward elimination
  //pivoting
  for (int i =0;i<(order-1);i++){
    int max_row=i;

    for(int z=i+1;z<order;z++){
        if( fabs(MatrixA[z][i]) > fabs(MatrixA[max_row][i])){
            max_row=z;
        }

    }
    //swapping
     double temp=VectorB[i];
     VectorB[i]=VectorB[max_row];
     VectorB[max_row]=temp;


    
  
    for(int m=0;m<order;m++){
        double temp =MatrixA[i][m];
        MatrixA[i][m]=MatrixA[max_row][m];
        MatrixA[max_row][m]=temp;
    }

    cout<<"printing swapped matrix after "<<i+1<<"th iteration."<<"\n";
    for(int i =0;i<order;i++){
    for (int j=0;j<order ;j++){
        cout<<setw(2)<<MatrixA[i][j];
    }
    cout<<endl;
  }

    for (int j=i+1;j<order ;j++){
      double factor =MatrixA[j][i]/MatrixA[i][i]  ;

      for(int k=i+1;k<order;k++){
        MatrixA[j][k]=MatrixA[j][k]-MatrixA[i][k]*factor;
      }
      VectorB[j]=VectorB[j]-VectorB[i]*factor;
    }
  }
  //we basically saved some steps which in turn prevented it from becoming upper triangle matrix 
  //so making them 0
  for (int i =0;i<order;i++){
    for(int j=0;j<i;j++){
      MatrixA[i][j]=0;
    }
  }
   cout<<"matrix a after forward elimination is "<<endl;
  for(int i =0;i<order;i++){
    for (int j=0;j<order ;j++){
        cout<<setw(2)<<MatrixA[i][j];
    }
    cout<<endl;
  }
  cout<<"vector after forward elimination \n";
  for (int i=0;i<order;i++){
    cout<<VectorB[i]<<endl;
  }

  //back substitution
  // i for variables and j for subtracting


  for (int i=(order-1);i>=0;i--){
    double sum =VectorB[i];
    for (int j=i+1;j<order;j++){
      sum=sum-MatrixA[i][j]*X[j];
    }
    X[i]=sum/MatrixA[i][i];
  }
  //printing solutions
for (int i=0;i<order;i++){
    cout<<"the value of x["<<i<<"] is : "<<X[i]<<"\n";
  }
    return 0;
}