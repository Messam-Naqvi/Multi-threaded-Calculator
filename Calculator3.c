#include <stdio.h>  		//for input and ouput
#include <math.h>		//for Math functionality
#include <string.h>		//for using of string
#include <pthread.h>		//for using thread in Calculator
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


//Global variable in the program..
int result =0;		//It control the result of the number that user entered the run time..
int count =1; 		//It control the array element in the array..


//Add the number that user entered run time (thread)
void *sum(void *parameter)
{
	//printf("\nStart of Sum Thread.... \n");
	pthread_self();
	
	//Here I retieve the arr that user entered the run time..
	int *arr = (int *)parameter;
	
	
	//here I simple perform the adding thread..
	//It simple add the first number into the result..
	//At the start of the program result =0 so result equal to that number that user entered.
	//that run every time at the start of the program..
	if(result == 0)
	{
		result = result + arr[0];
	}
	else
	{
		//that loop run how many number that user entered run time for adding purpose..
		do
		{
			result = result + arr[count];
			count++;
		}
		//100 is random number that do not effect in the program..
		while(count ==100);
		
	}
	
	//that display the result on the terminal..
	printf("Result = %d\n", result);
	//printf("End of Sum Thread.... \n");
	
	pthread_exit(NULL);
}



//Substract the number that user entered the run time (thread)
void *substract(void *parameter)
{
	//printf("\nStart of Substract Thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	
	
	//It work same as the sum thread 
	//but It substract the number instead of the adding
	do
	{
		result = result - arr[count];
		count++;
	}
	while(count ==100);
		
	
	
	
	printf("Result = %d\n", result);
	//printf("End of Substract Thread.... \n");
	
	pthread_exit(NULL);
}





//Multiple Number of thread
void *Multiple(void *parameter)
{
	//printf("\nStart of Multiple Thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	
	
	
	do
	{
		result = result * arr[count];
		count++;
	}
	while(count ==100);
		
	
	
	
	printf("Result = %d\n", result);
	//printf("End of Multiple Thread.... \n");
	
	pthread_exit(NULL);
}



//Divide the number that user entered the run time..
void *division(void *parameter)
{
	//printf("\nStart of Division Thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	float r = 0.0;
	r = result;
	
	do
	{
		r = (float)r / arr[count];
		count++;
	}
	while(count ==100);
	
	
	
	
	printf("Result = %.2f\n", r);
	//printf("End of Division Thread.... \n");
	
	pthread_exit(NULL);
}



//square of Number of thread
void *square(void *parameter)
{
	//printf("\nStart of square Thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	
	
	
	do
	{
		result = result * result;
		count++;
	}
	while(count ==100);
		
	
	
	
	printf("Result = %d\n", result);
	//printf("End of square Thread.... \n");
	
	pthread_exit(NULL);
}




//Cube of the Number thread..
void *cube(void *parameter)
{
	//printf("\nStart of Cube Thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	
	
	
	do
	{
		result = result * result * result;
		count++;
	}
	while(count ==100);
		
	
	
	
	printf("Result = %d\n", result);
	//printf("End of cube Thread.... \n");
	
	pthread_exit(NULL);
}



//Square Root of the Number thread..
void *squareroot(void *parameter)
{
	//printf("\nStart of Cube Thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	
	
	
	do
	{
		float z;
		for(z = 0.00;z*z<result;z=z+0.01);
		printf("\nResult = %.2f\n", z);
		
		
		count++;
	}
	while(count ==100);
		
	
	
	
	
	//printf("End of Square Root Thread.... \n");
	
	pthread_exit(NULL);
}


//In that thread you can find the Power of the Number like 2 P 3 = 8
void *Power(void *parameter)
{
	//printf("\nStart of Cube Thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	int number = arr[1];        //number = to that number those is power of the number ..
	int orginalnumber = result; //Orginalnumer = to that number those user want to find the power;
	
	
	do
	{
		
		result = result * orginalnumber;
		count++;
	}
	while(count < number);
		
	
	
	
	printf("Result = %d\n", result);
	//printf("End of cube Thread.... \n");
	
	pthread_exit(NULL);
}


//Find the Area of the Square (thread)
void *Area_of_Square()
{
	//printf("\nStart the find of Area of the Square thread.... \n");
	pthread_self();
	//int *arr = (int *)parameter;
	int height,r=0;
	printf("\nEnter the Height : ");
	scanf("%d",&height);
	//that is formula to calculate the Area of the Square..
	r = height * height;
	
	printf("Area of the Square is %d\n", r);
	//printf("End of find the area of the Square thread.... \n");
	
	pthread_exit(NULL);
}


//Find the Area of the Rectangle (thread)
void *Area_of_Rectangle()
{
	//printf("\nStart the find of Area of the Rectangle thread.... \n");
	pthread_self();
	int height,width,r=0;
	printf("\nEnter the Height : ");
	scanf("%d",&height);
	printf("\nEnter the Width : ");
	scanf("%d",&width);
	//that is formula to calculate the Area of the Rectangle ...
	r = height * width;
	
	printf("Area of the Rectangle is %d\n", r);
	//printf("End of find the area of the Rectangle thread.... \n");
	
	pthread_exit(NULL);
}

//Find the Area of the Triangle (thread)
void *Area_of_Triangle()
{
	//printf("\nStart the find of Area of the Triangle thread.... \n");
	pthread_self();
	int height,width;
	float r =0.0;
	printf("\nEnter the Height : ");
	scanf("%d",&height);
	printf("\nEnter the Width : ");
	scanf("%d",&width);
	//that is formula to calculate the Area of the Rectangle ...
	r = (float)height * width / 2;
	
	printf("Area of the Triangle is %.2f\n", r);
	//printf("End of find the area of the Rectangle thread.... \n");
	
	pthread_exit(NULL);
}


//Find the Area of the Cricle (thread)
void *Area_of_Circle()
{
	//printf("\nStart the find of Area of the Circle thread.... \n");
	pthread_self();
	int radius;
	float r;
	printf("\nEnter the Radius : ");
	scanf("%d",&radius);
	//that is formula to calculate the Area of the Rectangle ...
	r = (float)3.1415 * radius * radius;
	
	printf("Area of the Circle is %.2f\n", r);
	//printf("End of find the area of the Circle thread.... \n");
	
	pthread_exit(NULL);
}



//find the Percentage (thread)
void *Percentage(void *parameter)
{
	//printf("\nStart of Percentage thread.... \n");
	pthread_self();
	int *arr = (int *)parameter;
	float r=0.00;
	r = (float)arr[0] /arr[1] * 100;
		
	printf("Percentage of the Your Number is  = %.2f\n", r);
	//printf("End of Percentage Thread.... \n");
	
	pthread_exit(NULL);
}

float cradic_point(void *parameter)
{
	char *sym = (char *)parameter;
	if(sym == 'A')
	{
		return 4.0;
	}
	else if(sym == 'B')
	{
		return 3.0;
	}
	else if(sym == 'C')
	{
		return 2.0;
	}
	else if(sym == 'D')
	{
		return 1.0;
	}
	else if(sym == 'F')
	{
		return 0.0;
	}
	else 
	{
		printf("\n\nInvalid Grade!");
		return 0.0;
	}
}

//find the GPA (thread)
void *GPA()
{
	//printf("\nStart of GPA thread.... \n");
	pthread_self();
	int numberofSubject=0; 	//In which I take the Number of Subject that Subject Study in the Semester
	float earnpointS = 0.0;	//In which I take the Grade point in numeric
	float earnpoint =0.0;		//In which I multiply the Grade point with Cradic hour of the course.
	float totalpoint = 0.0;	//In which I calculate the total point Student gain in the sememter.
	float gpa =0.0;		//In which I calculate the total gpa of the Student.
	float totalcredichour =0.0;	//In which I take the total Credic Hour that Student Study in the semester.
	
	printf("\nEnter the Number of Subject : ");
	scanf("%d",&numberofSubject);
	char array_for_get_Grade[numberofSubject];
	float array_for_get_Credic_hour[numberofSubject];
	for(int i=0;i< numberofSubject;i++)
	{
		printf("\nEnter the Subject %d Grade : ",i+1);
		scanf("%s",&array_for_get_Grade[i]);
		printf("\nEnter the Credic Hour of the %d Subject : ",i+1);
		scanf("%f",&array_for_get_Credic_hour[i]);
		earnpointS = cradic_point(array_for_get_Grade[i]);
		earnpoint = (float)earnpointS * array_for_get_Credic_hour[i];
		totalpoint = (float)totalpoint + earnpoint;
		totalcredichour = totalcredichour + array_for_get_Credic_hour[i];
		
		
	}
	gpa = (float)totalpoint / totalcredichour;
	printf("Total GPA of the Student is %.2f\n",gpa);
	
	
	
	
	
	//printf("End of GPA  Thread.... \n");
	
	pthread_exit(NULL);
}


//main function of the Calculator
int main(int argc, char *argv[])
{
	//clrscr();
	//printf("Start of Main() function.... \n");
	//printf("At that time total number user enter : %d",argc);
	char symbol1 = argv[argc-1][0];
	//If user want to perform one operation on the multiple number So control entered the if condition.
	if(symbol1 == '+' || symbol1 == '-' || symbol1 == 'X' || symbol1 == '/' || symbol1 == 'S' || symbol1 == 'C' || symbol1 == 'R' || symbol1 == 'A' || symbol1 == 'P' || symbol1 == 'g')
	{
		pthread_t thread;
		int arr[argc -2];
		for(int i = 0; i < argc-2; i++)
		{
			arr[i] = atoi(argv[i + 1]);	
		}
		if(symbol1 == '+')
		{
			for(int i =0;i<argc-2;i++)
			{
				pthread_create(&thread, NULL, sum, (void *)arr);
				pthread_join(thread, NULL);
			}
		}
		else if(symbol1 == '-')
		{
			pthread_create(&thread, NULL, sum, (void *)arr);
			pthread_join(thread, NULL);
			for(int i =0;i<argc-3;i++)
			{
				pthread_create(&thread, NULL, substract, (void *)arr);
				pthread_join(thread, NULL);
			}
		}
		else if(symbol1 == 'X')
		{
			pthread_create(&thread, NULL, sum, (void *)arr);
			pthread_join(thread, NULL);
			for(int i =0;i<argc-3;i++)
			{
				pthread_create(&thread, NULL, Multiple, (void *)arr);
				pthread_join(thread, NULL);
			}
		}
		else if(symbol1 == '/')
		{
			pthread_create(&thread, NULL, sum, (void *)arr);
			pthread_join(thread, NULL);
			for(int i =0;i<argc-3;i++)
			{
				pthread_create(&thread, NULL, division, (void *)arr);
				pthread_join(thread, NULL);
			}
		}
		else if(symbol1 == 'S')
		{
			pthread_create(&thread, NULL, sum, (void *)arr);
			pthread_join(thread, NULL);
			for(int i =0;i<argc-2;i++)
			{
				pthread_create(&thread, NULL, square, (void *)&arr);
				pthread_join(thread, NULL);
			}
		}
		else if(symbol1 == 'C')
		{
			pthread_create(&thread, NULL, sum, (void *)arr);
			pthread_join(thread, NULL);
			for(int i =0;i<argc-2;i++)
			{
				pthread_create(&thread, NULL, cube, (void *)&arr);
				pthread_join(thread, NULL);
			}
		}
		else if(symbol1 == 'R')
		{
			pthread_create(&thread, NULL, sum, (void *)arr);
			pthread_join(thread, NULL);
			for(int i =0;i<argc-2;i++)
			{
				pthread_create(&thread, NULL, squareroot, (void *)&arr);
				pthread_join(thread, NULL);
			}
		}
		else if(symbol1 == 'A')
		{
			char choice; //In which I take the choice from the user..
			printf("\nPress S : For Square ");
			printf("\nPress R : For Rectangle ");
			printf("\nPress T : For Triangle ");
			printf("\nPress C : For Circle ");
			printf("\nEnter Your Choice : ");
			scanf("%s",&choice);
			if(choice == 'S')
			{
				pthread_create(&thread, NULL, Area_of_Square,NULL);
				pthread_join(thread, NULL);
			}
			else if(choice == 'R')
			{
				pthread_create(&thread, NULL, Area_of_Rectangle,NULL);
				pthread_join(thread, NULL);
			}
			else if(choice == 'T')
			{
				pthread_create(&thread, NULL, Area_of_Triangle,NULL);
				pthread_join(thread, NULL);
			}
			else if(choice == 'C')
			{
				pthread_create(&thread, NULL, Area_of_Circle,NULL);
				pthread_join(thread, NULL);
			}
			else 
			{
				printf("\n\n\n\nInvalid Entry!");
			}
				
		}
		else if(symbol1 == 'P')
		{
			pthread_create(&thread, NULL, Percentage, (void *)arr);
			pthread_join(thread, NULL);
			
		}
		else if(symbol1 == 'g')
		{
			pthread_create(&thread, NULL, GPA,NULL);
			pthread_join(thread, NULL);
			
		}
		else 
		{
			printf("\n\n\n\nInvalid Entry!");
		}
		
			
	}
	
	else
	{
		//argc have the total number that use entered at run time
		//I use ceil function that round off the (argc/2)
		//It simple count the number of integer that use entered
		//s have the number of integer
		int s = ceil(argc/2);
		
		//Here I create the array of integer number that user entered the run time..
		int arr[s];
		
		//Here I create the thread..
		pthread_t thread;
		
		
		//a point out the index of number of integer that user entered at run time..
		int a =1;
		
		//Here I convert the odd values come from runtime into the int values
		for(int i = 0; i < s; i++)
		{
			arr[i] = atoi(argv[a]);
			a = a+2;	
		}
		
		
		//Here I simple run the sum thread because I want to add the first index of array into result 0...
		pthread_create(&thread, NULL, sum, (void *)&arr);
		pthread_join(thread, NULL);
		
		
		//ss count the number of operation that user want to perform in expersion..
		//It always less than the integer in the array..
		// b point out the operation
		int ss = s - 1;
		int b =2;
		
		
		//Here I decide which thread is running
		for(int i =0;i<ss;i++)
		{
			char symbol = argv[b][0];
			if(symbol == '+')
			{
				pthread_create(&thread, NULL, sum, (void *)&arr);
				pthread_join(thread, NULL);
			}
			else if(symbol == '-')
			{
				pthread_create(&thread, NULL, substract, (void *)&arr);
				pthread_join(thread, NULL);
			}
			else if(symbol == 'X')
			{
				pthread_create(&thread, NULL, Multiple, (void *)&arr);
				pthread_join(thread, NULL);
			}
			else if(symbol == '/')
			{
				pthread_create(&thread, NULL, division, (void  *)&arr);
				pthread_join(thread, NULL);
			}
			else if(symbol == 'P')
			{
				pthread_create(&thread, NULL, Power, (void  *)&arr);
				pthread_join(thread, NULL);
			}
			
			
			else
			{
				printf("\nInvalid Entry !\n");
			}
			b= b+2;
		}
	}
	//printf("End of Main() function....\n");		
	return 0;
	
}
