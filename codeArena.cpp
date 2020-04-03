/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

using namespace std;

bool isPrime (int a)
{
    int i=0;
    for(i=2; i<a/2; i++)
        {
                if(a%i == 0)
                    return true;
        }
    return false;    
}

void goodTimes(vector<int>arr)
{
     int B=0;
     int G=0;


      while( arr[0] !=0 && arr[1] !=0 && arr[2] != 0)
            {
                if(isPrime(arr[2]))
                    {
                        if( arr[0]%arr[2] == 0 || arr[1]%arr[2] == 0)
                            ++B;
                    }        
                else    
                    {    ++G;}        

                if(!(arr[2] == 59))    
                    arr[2]++;
                 else
                    {
                        arr[2] = 00; 
                        if(!(arr[1] == 59))
                             arr[1]++; 
                        else
                            {
                                if( !(arr [0] == 23))
                                    arr[0]++;
                                else
                                    arr[0]=00;     
                            }    
                    }
            }
  if(B != 0)          
    if(G%B == 0)
       {
           G= G/B;
           B= B/B;
       } 
    cout<<B<<":"<<G<<endl;   

}

int main()
{
    int T;
    cin>>T;
    int x;
    while(T>0)
        {   
            vector <int> time;
                for(int i=0;i<3;i++)
                 {   
                     cin>>x;
                    time.push_back(x);
                 }   
                goodTimes(time);
             --T;   
        }
    return 0;    
}
