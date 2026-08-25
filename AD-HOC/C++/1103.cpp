#include <iostream>
#include <string>
using namespace std;

int main(){
    int values[4], min;
    while(true){
        
    for (size_t i = 0; i < 4; i++)
    {
        //Bloqueia ate a entrada dos proximos valores
        //impedindo print min apos a primeira execução
         scanf("%d",&values[i]); 
    }

    if (values[0] == 0 &&
        values[1] == 0 &&
        values[2] == 0 &&
        values[3] == 0) {
        break;
    }   
    int deltaH = values[2] - values[0]; 
    int deltaM = values[3] - values[1]; 
    
    if (deltaH > 0) {
        min = deltaH*60 + deltaM;
        
    }else if (deltaH < 0){
        min = (deltaH+24)*60 + deltaM;
    }
    else {
        if(deltaM > 0) min = deltaM;
        else min = 24*60 + deltaM;

    }

    printf("%d\n", min);

    }
    return 0;
}