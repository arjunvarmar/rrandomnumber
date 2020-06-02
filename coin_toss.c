#include<stdio.h>
#include<stdlib.h>
#include<gsl/gsl_rng.h>
#include<gsl/gsl_math.h>
#include<time.h>


void main(){

int i;

double randomnumber; 
long int total_num_tosses;
int num_heads,num_tails;
double headtotailratio;
long int init_wealth,person1wealth,person2wealth;


double noise, mean_noise;
gsl_rng * ran_num;
const gsl_rng_type * Taus;

gsl_rng_env_setup();
Taus = gsl_rng_taus2;
ran_num = gsl_rng_alloc (Taus);

printf("Enter number of tosses\n");
scanf("%ld",&total_num_tosses);
printf("Enter the initial wealth\n");
scanf("%ld",&init_wealth);
//total_num_tosses =1000000;
//init_wealth      =1000000;

// Wealth of two persons initialized at 200 dollars
person1wealth=init_wealth;
person2wealth=init_wealth;

// Initializing heads and tails counters to zero before
// starting the tosses
num_heads=0;
num_tails=0;

// Starting the tosses
for(i=0;i<total_num_tosses;i++){

randomnumber = gsl_rng_uniform(ran_num);   // Generate random number
//printf("Random number is : %lf\n",randomnumber);

if(randomnumber>0.5){
num_heads++;	// Number of head counts incremented
if(person2wealth>0){
person1wealth++;   //Person 1 gets 1 dollar
person2wealth--;   // Person 2 loses 1 dollar
}
}
if(randomnumber<=0.5){
num_tails++;	    // Number of tail counts incremented
if(person1wealth>0){
person2wealth++;   // Person 2 gets 1 dollar
person1wealth--;   //Person 1 loses 1 dollar
}
}


}

printf("After %ld tosses, wealths of P1: %ld, P2: %ld\n",total_num_tosses,person1wealth,person2wealth);

printf("Percentage difference in wealth: %lf\n",(double) (person1wealth-person2wealth)*100/init_wealth);

printf("After %ld tosses, the probabililty for Head is: %lf\n",total_num_tosses,(double) num_heads/total_num_tosses);


}
