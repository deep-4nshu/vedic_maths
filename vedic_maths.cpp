#include <iostream>
using namespace std;

int calculate_size(long int n)
{
    int d=n;
    int k=1;
while(d!=0)
{
    d=d/10;
    k++;
}
return k-1;
}

void create_array(int *num,int n,long int number)
{
    int f=number;
    for (int i=0;i<n;i++)
    {
     num[i]=f%10;
     f=f/10;
    }
}

void print_array(int *num,int n)
{
    for(int i=0;i<n;i++)
        cout<<num[i];
cout<<endl;
}

int vedic_calc(int *num, int *den, int n)
{
 int number=0;
 int ones=num[0];
 int tens=0;
 int first=1000*den[4]+100*den[3]+10*den[2]+den[1];
   for(int j=1;j<=n-1;j++)
   {
       number=(first*ones)+num[j]+tens;
       tens=number/10;
       ones=number%10;
   }
   return number;
}

int main()
{
    long int n;
    long int d;
    int numerator[1000];
    int denominator[5]={0,0,0,0,0};

cout<<"Enter Numerator: ";
cin>>n;
cout<<"Enter Denominator: ";
cin>>d;
d++;

int num=calculate_size(n);
int den=calculate_size(d);

create_array(numerator,num,n);
create_array(denominator,den,d);
int output=vedic_calc(numerator,denominator,num);
cout<<"Final answer is: ";
cout<<output<<endl;
if(output==d-1)
    cout<<"Divisible.";
    else
    cout<<"Not Divisible.";

}
