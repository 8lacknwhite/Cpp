#include<iostream> 
using namespace std; 
int a,nef,i,j,k;
int in[100], p[50]; 
int h=0, pc=0;

void getData(){

    cout<<"Enter the length of page refrence sequence: ";
    cin>>a; 
    cout<<"Enter the page reference sequence:\n"; 
    for(i=0;i<a;i++)
    {
        cin>>in[i];
    }
    cout<<endl;
    cout<<"Enter number of frames: ";
    cin>>nef;
}

void init(){
    pc=0; 
    for(i=0;i<nef;i++){
        p[i]=9999;
    }
}

int isHit(int data){ 
    h=0;
    for(j=0;j<nef;j++){
        if(p[j]==data){ 
            h=1; 
            break;
        }
    }
    return h;
}

int getHitIndex(int data){ 
    int hitind; 
    for(k=0;k<nef;k++){
        if(p[k]==data){ 
            hitind=k; 
            break;
        }
    }
    return hitind;
}

void dispPages(){ 
    for(k=0; k<nef; k++){
        if(p[k]!=9999){
            cout<<p[k]<<" ";
        }
    }
}

void pagefaultcount(){
    cout<<"\nTotal number of page faults: "<<pc<<endl;
}

void fifo(){
    init();
    for(i=0; i<a; i++){
        cout<<"\nFor "<<in[i]<<" :";
        if(isHit(in[i])==0){ 
            for(k=0; k<nef-1; k++){
                p[k]=p[k+1];
            }
            p[k]=in[i]; 
            pc++; 
            dispPages();
        }
        else{
            cout<<"No page fault";
        }
    }
    pagefaultcount();
}

void optimal(){ 
    init();
    int near[50]; 
    for(i=0;i<a;i++){
        cout<<"\nFor "<<in[i]<<" :";
        if(isHit(in[i])==0){
            for(j=0; j<nef; j++){
                int pg=p[j]; 
                int found=0;
                for(k=i; k<a; k++){ 
                    if(pg==in[k]){
                        near[j]=k; 
                        found=1; 
                        break;
                    }
                    else{
                        found=0;
                    }
                }
                if(!found){
                    near[j]=9999;
                }
            }
            int max=-9999; 
            int repindex;
            for(j=0; j<nef; j++){ 
                if(near[j]>max){ 
                    max=near[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i]; 
            pc++;
            dispPages();
        }
        else{
            cout<<"No Page fault";
        }
    }
    pagefaultcount();
}

void lru(){
    init();
    int least[50];

    for(i=0; i<a; i++){
        cout<<"\nFor "<<in[i]<<" :";
        if(isHit(in[i])==0){ 
            for(j=0; j<nef; j++){
                int pg=p[j]; 
                int found=0;
                for(k=i-1; k>=0; k--){ 
                    if(pg==in[k]){
                        least[j]=k;
                        found=1; 
                        break;
                    }
                    else{
                        found=0;
                    }
                }
                if(!found){
                    least[j]=-9999;
                }
            }
            int min=9999; 
            int repindex;
            for(j=0; j<nef; j++){ 
                if(least[j]<min){
                    min=least[j]; 
                    repindex=j;
                    
                }
            }
            p[repindex]=in[i]; 
            pc++;
            dispPages();
        }
        else{
            cout<<"No Page fault!";
        }
    }
    pagefaultcount();
}

int main(){
    int choice =1 ; 
    while(choice != 0){
        cout<<"Page Replacement Algorithm\n";
        cout<<"1.Enter Data\n2.FIFO\n3.Optimal\n4.LRU\n5.EXIT\n"; 
        cout<<"Enter choice: ";
        cin>>choice; 
        switch(choice){
            case 1:
                getData();
            case 2:
                fifo();
                
            case 3:
                optimal();
			
            case 4:
                lru();
              
            case 5:
                exit(0);
                
            default:
                return 0;
        
        }
    return 0;
	}
}
