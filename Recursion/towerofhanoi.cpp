#include<iostream>
using namespace std;

void toh(int n,string from,string aux,string to)
{
    // if single disk, it can be directly sent to destination
    if(n==1)
    {
        cout<<"Disk 1 from "+from+" to "+to<<"\n";
        return;
    }
    // send all disks above current disk to the auxiallary tower
    toh(n-1,from,to,aux);
    // send the current disk to its destination tower
    cout<<"Disk "<<n<<" from "+from+" to "+to<<"\n";
    // bring all the remaining disks currently kept in auxillary tower to the destination
    toh(n-1,aux,from,to);
}

int main()
{
    int n;
    cin>>n;
    toh(n,"A","B","C");
}