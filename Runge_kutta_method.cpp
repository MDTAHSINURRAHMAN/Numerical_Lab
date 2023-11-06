#include<bits/stdc++.h>
using namespace std;
const int n=20;
double aug[n];
const string eqn;
#define epsilon 0.0001
//#define f(x,y) (y*y-x*x)/(y*y+x*x)


void addCoef(string str){
        int count=0;
        for(int i=0;i<str.size();i++){
                if(('0'<=str[i] && str[i]<='9') ||  str[i]=='+'|| str[i]=='-'){
                        string temp="";
                        int k=i;
                        while(('0'<=str[k] && str[k]<='9') ||  str[k]=='+'|| str[k]=='-'){
                                temp+=str[k];
                                k++;
                        }
                        aug[count]=stoi(temp);
                        count++;
                        i=k;
                }

        }
}

double f(double x,double y){
    return (aug[0]*y*y+aug[1]*x*x)/(aug[2]*y*y+aug[3]*x*x);
}

void runge_kutta_method(double x0,double y0,double xn,double h){
    int n=xn/h;
    double k, k1, k2, k3, k4;
    for(int i=0;i<n;i++){
        k1 = h * (f(x0, y0));
        k2 = h * (f((x0+h/2), (y0+k1/2)));
        k3 = h * (f((x0+h/2), (y0+k2/2)));
        k4 = h * (f((x0+h), (y0+k3)));
        k=y0+(k1+2*k2+2*k3+k4)/6;
        cout<<"(x"<<i<<" : "<<x0<<","<<"y"<<i<<" : "<<y0<<")"<<" : "<<"y"<<i+1<<" : "<<k<<endl;
        x0+=h;
        y0=k;
    }

    cout<<endl;
    cout<<x0<<" : "<<y0<<endl;
}


int main(){
        double x0,y0,xn,h;
        cout<<"Enter the equation: "<<endl;
        string eqn;
        cin>>eqn;
        addCoef(eqn);
        cout<<"Enter the initial value of x"<<endl;
        cin>>x0;
        cout<<"Enter the initial value of y"<<endl;
        cin>>y0;
        cout<<"Enter required value of y at x"<<endl;
        cin>>xn;
        cout<<"Step Size"<<endl;
        cin>>h;
        runge_kutta_method(x0,y0,xn,h);
}
//(1*y*y-1*x*x)/(1*y*y+1*x*x) 