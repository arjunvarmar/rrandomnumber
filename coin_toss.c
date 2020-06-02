#include<stdio.h>
#include<stdlib.h>
#include<gsl/gsl_rng.h>
#include<gsl/gsl_math.h>
#include<time.h>


void main(){

int i;

double randomnumber; 
int total_num_tosses;
int num_heads,num_tails;
double headtotailratio;


double noise, mean_noise;
gsl_rng * ran_num;
const gsl_rng_type * Taus;

gsl_rng_env_setup();
Taus = gsl_rng_taus2;
ran_num = gsl_rng_alloc (Taus);

total_num_tosses = 10;

// Wealth of two persons initialized at 200 dollars
int person1wealth=200;
int person2wealth=200;

// Initializing heads and tails counters to zero before
// starting the tosses
num_heads=0;
num_tails=0;

// Starting the tosses
for(i=0;i<total_num_tosses;i++){

randomnumber = gsl_rng_uniform(ran_num);   // Generate random number
printf("Random number is : %lf\n",randomnumber);

if(randomnumber>0.5){
num_heads++;	// Number of head counts incremented
person1wealth++;   //Person 1 gets 1 dollar
person2wealth--;   // Person 2 loses 1 dollar
}
if(randomnumber<=0.5){
num_tails++;	    // Number of tail counts incremented
person2wealth++;   // Person 2 gets 1 dollar
person1wealth--;   //Person 1 loses 1 dollar
}

}

printf("After %d tosses, wealths of P1: %d, P2: %d\n",total_num_tosses,person1wealth,person2wealth);

printf("After %d tosses, the head to tail ratio is: %lf\n",total_num_tosses,(double) num_heads/total_num_tosses);


}
