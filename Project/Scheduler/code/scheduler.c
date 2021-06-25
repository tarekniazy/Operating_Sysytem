#include "ImplementingAlgos.h"
#include <math.h>
int main(int argc, char *argv[])
{

    
  int rec_val;
  int Algorithm=atoi(argv[1]);
  int noofproc;
  int finish;
  FILE* outputt;
  int quantum;				//MOSTAFA
  
  if(Algorithm==5)
  {
  quantum=atoi(argv[2]);		//MOSTAFA
  noofproc=atoi(argv[3]);
  } 
  else
  {
   	noofproc=atoi(argv[2]);
	
  }
  initClk();
  initShmem();
  writeShM(0);
    //TODO: implement the scheduler.
    if(Algorithm==1)  //FCFS
    {
    	queue*Finish=FCFS(noofproc);
    	fclose(output);
    	finish=getClk();
    	int count = 0,runtime=0;
    	double avgWTA =0,Avgwait =0,Std =0,std_sum =0;
    	node*h=Finish->front;
    	while(h != NULL)
    	{
    		avgWTA += h->data.weighted_turnaround_time;
         	Avgwait += h->data.waitingtime;
        	 count++;
         	runtime = runtime + h->data.runningtime;
         	h = h->next;
    	}
    	double CPU = ((double)runtime/(double)finish) * 100;
      	avgWTA = avgWTA /count;
      	Avgwait = Avgwait /count;
      	while (Finish->front !=NULL)
      {
        std_sum += pow((Finish->front->data.weighted_turnaround_time - avgWTA),2);
         dequeue(Finish);
      }
     
      outputt = fopen("scheduler.perf","w");
     fprintf(outputt,"CPU utilization = %0.2f %%\n",CPU);      
      fprintf(outputt,"Avg WTA = %0.2f\n",avgWTA);
      fprintf(outputt,"Avg Waiting = %0.2f\n",Avgwait);
      fclose(outputt);
    }
    else if(Algorithm==2)
 
    {

        printf(" I am  HPF ... :)");

    queue*Finish=SJF(noofproc);
    	fclose(output);
    	finish=getClk();
    	int count = 0,runtime=0;
    	double avgWTA =0,Avgwait =0,Std =0,std_sum =0;
    	node*h=Finish->front;
    	while(h != NULL)
    	{
    		avgWTA += h->data.weighted_turnaround_time;
         	Avgwait += h->data.waitingtime;
        	 count++;
         	runtime = runtime + h->data.runningtime;
         	h = h->next;
    	}
    	double CPU = ((double)runtime/(double)finish) * 100;
      	avgWTA = avgWTA /count;
      	Avgwait = Avgwait /count;
      	while (Finish->front !=NULL)
      {
        std_sum += pow((Finish->front->data.weighted_turnaround_time - avgWTA),2);
         dequeue(Finish);
      }
     
      outputt = fopen("scheduler.perf","w");
     fprintf(outputt,"CPU utilization = %0.2f %%\n",CPU);      
      fprintf(outputt,"Avg WTA = %0.2f\n",avgWTA);
      fprintf(outputt,"Avg Waiting = %0.2f\n",Avgwait);
      fclose(outputt);
    
}

else if(Algorithm==3)
 
    {

      printf(" I am  HPF ... :)");
    queue*Finish=HPF(noofproc);
    	fclose(output);
    	finish=getClk();
    	int count = 0,runtime=0;
    	double avgWTA =0,Avgwait =0,Std =0,std_sum =0;
    	node*h=Finish->front;
      	while(h != NULL)
    	{
    		avgWTA += h->data.weighted_turnaround_time;
         	Avgwait += h->data.waitingtime;
        	 count++;
         	runtime = runtime + h->data.runningtime;
         	h = h->next;
    	}
    	double CPU = ((double)runtime/(double)finish) * 100;
      	avgWTA = avgWTA /count;
      	Avgwait = Avgwait /count;
      	while (Finish->front !=NULL)
      {
        std_sum += pow((Finish->front->data.weighted_turnaround_time - avgWTA),2);
         dequeue(Finish);
      }
     
      outputt = fopen("scheduler.perf","w");
     fprintf(outputt,"CPU utilization = %0.2f %%\n",CPU);      
      fprintf(outputt,"Avg WTA = %0.2f\n",avgWTA);
      fprintf(outputt,"Avg Waiting = %0.2f\n",Avgwait);
      fclose(outputt);
 
    
}


else if(Algorithm==4)
 
    {

      printf(" I am  SRTN ... :)");
    queue*Finish=SRTN(noofproc);
    	fclose(output);
    	finish=getClk();
    	int count = 0,runtime=0;
    	double avgWTA =0,Avgwait =0,Std =0,std_sum =0;
    	node*h=Finish->front;
      	while(h != NULL)
    	{
    		avgWTA += h->data.weighted_turnaround_time;
         	Avgwait += h->data.waitingtime;
        	 count++;
         	runtime = runtime + h->data.runningtime;
         	h = h->next;
    	}
    	double CPU = ((double)runtime/(double)finish) * 100;
      	avgWTA = avgWTA /count;
      	Avgwait = Avgwait /count;
      	while (Finish->front !=NULL)
      {
        std_sum += pow((Finish->front->data.weighted_turnaround_time - avgWTA),2);
         dequeue(Finish);
      }
     
      outputt = fopen("scheduler.perf","w");
     fprintf(outputt,"CPU utilization = %0.2f %%\n",CPU);      
      fprintf(outputt,"Avg WTA = %0.2f\n",avgWTA);
      fprintf(outputt,"Avg Waiting = %0.2f\n",Avgwait);
      fclose(outputt);
 
    
}
   

//////////////////////////// MOSTAFA /////////////////////////////////////
else if (Algorithm == 5)
{

	printf(" I am  RR:");
	queue *Finish = RR(noofproc, quantum);
	fclose(output);
	finish = getClk();
	int count = 0, runtime = 0;
	double avgWTA = 0, Avgwait = 0, Std = 0, std_sum = 0;
	node *h = Finish->front;
	while (h != NULL)
	{
		avgWTA += h->data.weighted_turnaround_time;
		Avgwait += h->data.waitingtime;
		count++;
		runtime = runtime + h->data.runningtime;
		h = h->next;
	}
	double CPU = ((double)runtime / (double)finish) * 100;
	avgWTA = avgWTA / count;
	Avgwait = Avgwait / count;
	while (Finish->front != NULL)
	{
		std_sum += pow((Finish->front->data.weighted_turnaround_time - avgWTA), 2);
		dequeue(Finish);
	}

	outputt = fopen("scheduler.perf", "w");
	fprintf(outputt, "CPU utilization = %0.2f %%\n", CPU);
	fprintf(outputt, "Avg WTA = %0.2f\n", avgWTA);
	fprintf(outputt, "Avg Waiting = %0.2f\n", Avgwait);
	fclose(outputt);
}
//////////////////////////// MOSTAFA /////////////////////////////////////


    //TODO: upon termination release the clock resources.
	destroyShM();

    destroyClk(true);
}

